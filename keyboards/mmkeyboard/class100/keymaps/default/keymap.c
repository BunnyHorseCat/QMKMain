/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
       //  ESC     F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12    F13       F14       F15     F16       F17     F18     F19     F20     F21    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SCRL, KC_PAUS,    KC_VOLU, KC_VOLD, KC_MUTE,   KC_CALC,
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,            KC_UP,               KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RGUI, MO(1),   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,   KC_P0,   KC_PDOT,   KC_PENT
		),

      //  ESC     F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12      F13       F14       F15     F16       F17     F18     F19     F20     F21     
    [1] = LAYOUT(
    KC_ESC,           KC_MSEL, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MAIL, KC_WHOM, KC_CALC, KC_WSCH,   KC_PSCR, KC_SCRL, KC_PAUS,    KC_CALC, KC_MYCM, KC_MAIL,   KC_WHOM,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, AU_ON,   AU_OFF,  CK_UP,   CK_DOWN, CK_RST,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, HF_ON,   HF_OFF,  HF_FDBK, HF_RST,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,            KC_UP,               KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		MO(2), KC_LGUI, KC_LALT,                              KC_SPC,                             KC_RALT, KC_RGUI, MO(1),   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,   KC_P0,   KC_PDOT,   KC_PENT
		),

    [2] = LAYOUT(
    EE_CLR,           QK_BOOT, KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SCRL, KC_PAUS,    KC_CALC, KC_MYCM, KC_MAIL,   KC_WHOM,
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,            KC_UP,               KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RGUI, MO(1),   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,   KC_P0,   KC_PDOT,   KC_PENT
		),

    [3] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    KC_PSCR, KC_SCRL, KC_PAUS,    KC_CALC, KC_MYCM, KC_MAIL,   KC_WHOM,
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,            KC_UP,               KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RGUI, MO(1),   KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,     KC_P0,  KC_P0,   KC_PDOT,   KC_PENT
		),
};