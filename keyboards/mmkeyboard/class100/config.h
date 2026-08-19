/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1

#define SOLENOID_PIN A0
#define HAPTIC_ENABLE_PIN C3
#define SOLENOID_DEFAULT_DWELL 35
#define SOLENOID_MIN_DWELL 4
#define SOLENOID_MAX_DWELL  80
#define HAPTIC_OFF_IN_LOW_POWER 1
#define NO_HAPTIC_MOD

#define AUDIO_CLICKY
#define AUDIO_PIN A2
#define AUDIO_PWM_DRIVER PWMD2
#define AUDIO_PWM_CHANNEL 3
#define AUDIO_PWM_PAL_MODE 1
#define NO_MUSIC_MODE
#define AUDIO_STATE_TIMER  GPTD4
//#define AUDIO_PIN_ALT_AS_NEGATIVE
//#define AUDIO_PIN_ALT A1

#define AUDIO_DAC_SAMPLE_MAX 4095U               //DAC通常以12Bit模式运行，因此100%的卷=4095U
#define AUDIO_CLICKY_FREQ_DEFAULT	1320.0f	      //设置点击声音的默认/开始音频频率。
#define AUDIO_CLICKY_FREQ_MIN	65.0f	            //设置最低频率（低于60f是有点bug）。
#define AUDIO_CLICKY_FREQ_MAX	1500.0f	         //设置最高频率。过高可能会导致同事攻击你。
#define AUDIO_CLICKY_FREQ_FACTOR	10.0f	       //设置向上/向下键代码的步进。这是一个乘法因子。默认情况下将频率向上/向下步进音乐小调三分之一。
#define AUDIO_CLICKY_FREQ_RANDOMNESS	0.0f	   //为单击设置随机性因子，将其设置为 0f会让每次点击都一样 1.0f会使这个声音很像90年代的电脑屏幕滚动/打字的效果。
#define AUDIO_CLICKY_DELAY_DURATION	 6         //整数音符的持续时间，其中1是速度的1/16，或64个音符,主点击效果将延迟此持续时间。将其调整到6-12左右的值将有助于补偿开关的音量过大。

////////////////////////////////////
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BAND_VAL  // 默认灯效：竖条渐变
#if defined(RGB_MATRIX_ENABLE)
//WS2812 RGB PWM项目
//#define WS2812_DI_PIN  A6
#define RGBLED_NUM 22
#define RGB_MATRIX_LED_COUNT 22
#define DRIVER_LED_TOTAL RGBLED_NUM
//#define WS2812_EXTERNAL_PULLUP
#define WS2812_PWM_DRIVER PWMD3  //PWD3?
#define WS2812_PWM_CHANNEL 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3
#define WS2812_PWM_TARGET_PERIOD 800000

//#define RGB_MATRIX_EFFECT_BREATHING

// 启用RGB灯效模式（极简版，只保留4个最常用的）
#define ENABLE_RGB_MATRIX_SOLID_COLOR        // 1. 纯色
#define ENABLE_RGB_MATRIX_BREATHING          // 3. 呼吸灯
#define ENABLE_RGB_MATRIX_BAND_VAL           // 4. 竖条渐变（默认）
#define ENABLE_RGB_MATRIX_CYCLE_ALL          // 8. 全彩循环

#endif

