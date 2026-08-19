#include "class100.h"

// ===== 开机灯效相关变量 =====
static bool startup_animation_done = false;  // 开机动画是否已完成
static uint32_t startup_timer = 0;           // 开机动画计时器
static uint8_t animation_stage = 0;          // 当前动画阶段：0=未开始，1=点亮扩展，2=熄灭收缩，3=完成
static uint8_t expand_step = 0;              // 扩展效果的当前步数
static uint8_t shrink_step = 0;              // 收缩熄灭的当前步数

// 保存用户的RGB设置（用于动画结束后恢复）
static uint8_t saved_mode = 0;
static uint8_t saved_hue = 0;
static uint8_t saved_sat = 0;
static uint8_t saved_val = 0;
static uint8_t saved_speed = 0;

// 动画参数配置（可修改）
#define EXPAND_STEP_DELAY 50                // 点亮扩展每步间隔（毫秒）
#define SHRINK_STEP_DELAY 50                // 熄灭收缩每步间隔（毫秒）
#define EFFECT_BRIGHTNESS 191                // 灯效亮度 75% (255 * 0.75 = 191)
#define EFFECT_COLOR_R 255                   // 红色 R值
#define EFFECT_COLOR_G 0                     // 红色 G值
#define EFFECT_COLOR_B 0                     // 红色 B值

// ===== 开机初始化函数 =====
void keyboard_post_init_user(void) {


    audio_off();
   // clicky_disable();
    //haptic_disable();

    #ifdef RGB_MATRIX_ENABLE
    // 先确保RGB矩阵启用（会从EEPROM自动加载用户设置）
    rgb_matrix_enable();
    
    // 保存用户当前的RGB设置（从EEPROM加载的）
    saved_mode = rgb_matrix_get_mode();
    saved_hue = rgb_matrix_get_hue();
    saved_sat = rgb_matrix_get_sat();
    saved_val = rgb_matrix_get_val();
    saved_speed = rgb_matrix_get_speed();
    
    // 如果亮度为0（可能是首次启动，EEPROM未初始化），使用默认值
    if (saved_val == 0) {
        saved_val = RGB_MATRIX_DEFAULT_VAL;  // 使用config.h中定义的默认亮度
        rgb_matrix_sethsv(saved_hue, saved_sat, saved_val);  // 设置并保存到EEPROM
    }
    
    // 启动开机灯效
    startup_timer = timer_read32();
    startup_animation_done = false;
    animation_stage = 1;  // 开始阶段1：点亮扩展
    expand_step = 0;
    shrink_step = 0;
    
    // 临时禁用默认RGB矩阵效果，使用自定义开机动画
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 0);  // 暂时全部关闭，准备开机动画
    #endif
}

// ===== 自定义矩阵扫描函数 - 控制动画进度 =====
void matrix_scan_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    if (!startup_animation_done) {
        uint32_t elapsed = timer_elapsed32(startup_timer);
        
        // 阶段1：从中间向两边扩展点亮
        if (animation_stage == 1) {
            if (elapsed >= EXPAND_STEP_DELAY) {
                expand_step++;
                startup_timer = timer_read32();  // 每步后重置计时器，确保每步都能看到
                
                // 扩展完成（从中间到两端共10步，LED[12]到LED[3]/LED[21]）
                if (expand_step > 10) {
                    animation_stage = 2;  // 进入阶段2：熄灭收缩
                    shrink_step = 0;
                }
            }
        }
        // 阶段2：从两边向中间收缩熄灭（原路返回）
        else if (animation_stage == 2) {
            if (elapsed >= SHRINK_STEP_DELAY) {
                shrink_step++;
                startup_timer = timer_read32();  // 每步后重置计时器
                
                // 收缩完成（从两端向中间熄灭共10步）
                if (shrink_step > 10) {
                    animation_stage = 3;  // 动画完成
                    startup_animation_done = true;
                    
                    // 恢复用户之前保存的RGB设置
                    rgb_matrix_enable();  // 确保RGB矩阵已启用
                    rgb_matrix_mode_noeeprom(saved_mode);  // 恢复模式
                   // if (saved_mode >= RGB_MATRIX_EFFECT_MAX) {
                   //     saved_mode = RGB_MATRIX_SOLID_COLOR;
                   // }
                    rgb_matrix_sethsv_noeeprom(saved_hue, saved_sat, saved_val);  // 恢复颜色和亮度
                    rgb_matrix_set_speed_noeeprom(saved_speed);  // 恢复速度
                }
            }
        }
    }
    #endif
}

// ===== RGB 指示灯函数 - 绘制开机灯效和锁定键状态 =====
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    
    // ========== 开机灯效绘制 ==========
    if (!startup_animation_done) {
        // 阶段1：从中间向两边扩展点亮（LED[3]到LED[21]，共19个LED）
        if (animation_stage == 1 && expand_step > 0) {
            // 计算当前应该点亮的LED范围
            // expand_step=1: 点亮LED[12]
            // expand_step=2: 点亮LED[11]和LED[13]
            // expand_step=3: 点亮LED[10]和LED[14]
            // 依次类推...
            
            for (uint8_t step = 1; step <= expand_step && step <= 10; step++) {
                int8_t center = 12;  // 中心LED索引
                
                if (step == 1) {
                    // 第一步只点亮中心
                    RGB_MATRIX_INDICATOR_SET_COLOR(center, 
                        EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                        EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                        EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                } else {
                    // 向两边扩展
                    int8_t left_led = center - (step - 1);
                    int8_t right_led = center + (step - 1);
                    
                    // 确保LED索引在有效范围内（LED[3]到LED[21]）
                    if (left_led >= 3) {
                        RGB_MATRIX_INDICATOR_SET_COLOR(left_led,
                            EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                    }
                    if (right_led <= 21) {
                        RGB_MATRIX_INDICATOR_SET_COLOR(right_led,
                            EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                    }
                }
            }
        }
        // 阶段2：从两边向中间收缩熄灭（原路返回）
        else if (animation_stage == 2) {
            // 计算当前应该保持点亮的LED范围
            // shrink_step=0: 保持全亮（刚从阶段1切换过来）
            // shrink_step=1: 熄灭LED[3]和LED[21]，保持LED[4]到LED[20]
            // shrink_step=2: 熄灭LED[4]和LED[20]，保持LED[5]到LED[19]
            // 依次类推，直到只剩LED[12]，然后全部熄灭
            
            // 计算当前仍然点亮的范围
            uint8_t remaining_steps = 10 - shrink_step;
            
            if (remaining_steps > 0) {
                // 还有LED需要保持点亮
                for (uint8_t step = 1; step <= remaining_steps; step++) {
                    int8_t center = 12;  // 中心LED索引
                    
                    if (step == 1) {
                        // 中心LED始终保持点亮，直到最后
                        RGB_MATRIX_INDICATOR_SET_COLOR(center, 
                            EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                            EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                    } else {
                        // 向两边扩展的仍然点亮的LED
                        int8_t left_led = center - (step - 1);
                        int8_t right_led = center + (step - 1);
                        
                        if (left_led >= 3) {
                            RGB_MATRIX_INDICATOR_SET_COLOR(left_led,
                                EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                                EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                                EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                        }
                        if (right_led <= 21) {
                            RGB_MATRIX_INDICATOR_SET_COLOR(right_led,
                                EFFECT_COLOR_R * EFFECT_BRIGHTNESS / 255,
                                EFFECT_COLOR_G * EFFECT_BRIGHTNESS / 255,
                                EFFECT_COLOR_B * EFFECT_BRIGHTNESS / 255);
                        }
                    }
                }
            }
            // 如果remaining_steps==0，所有LED都熄灭（不绘制任何颜色）
        }
        
        return false;  // 开机灯效期间，不显示其他指示
    }
    
    // ========== 正常模式：显示锁定键指示灯 ==========
    // Caps Lock 指示灯（LED #1 显示红色）
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 255, 0, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
    }
    
    // Num Lock 指示灯（LED #0 显示红色）
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 255, 0, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }
    
    // Scroll Lock 指示灯（LED #2 显示红色）
    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 255, 0, 0);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 0);
    }
    
    return false;
}
