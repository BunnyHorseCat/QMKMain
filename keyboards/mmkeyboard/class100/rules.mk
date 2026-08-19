
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

#HAPTIC_ENABLE = yes
#HAPTIC_DRIVER = SOLENOID   #启用电磁阀

VIAL_INSECURE = no    #禁用启动VIAL恶意刷新固件的按键
#RGB_MATRIX_EFFECT_BREATHING = yes

#AUDIO_DRIVER = pwm_software
#AUDIO_ENABLE = yes
#RGBLIGHT_DRIVER = WS2812

#ENCODER_ENABLE = yes  #旋钮编码器
#RGB_MATRIX_ENABLE = yes
#RGB_MATRIX_DRIVER = WS2812
#WS2812_DRIVER = pwm