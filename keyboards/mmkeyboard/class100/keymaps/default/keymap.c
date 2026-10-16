/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
       //  ESC     F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12    F13       F14       F15     F16       F17     F18     F19     F20     F21    
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
                KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SCRL, KC_PAUS,   KC_VOLU, KC_VOLD, KC_MUTE,   KC_CALC,
		KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,   KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                                   KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,                     KC_UP,              KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, MO(1),   KC_RGUI, KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT,   KC_P0,   KC_P0,   KC_PDOT,   KC_PENT
		),

      //  ESC     F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12      F13       F14       F15     F16       F17     F18     F19     F20     F21     
    [1] = LAYOUT(
                CK_RST,             KC_BRID,  KC_BRIU,  G(KC_TAB), G(KC_E),  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            NK_TOGG,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,
		HF_RST,   RM_HUEU,  RM_VALU,  RM_SATU,  HF_DWLU,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPLY,  _______,  KC_VOLU,  _______,  _______,  _______,  _______,
		RM_TOGG,  RM_HUED,  RM_VALD,  RM_SATD,  HF_DWLD,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_MPRV,  KC_MNXT,  KC_VOLD,  _______,  _______,  _______,  _______,
		AU_TOGG,  RM_NEXT,  RM_SPDU,  CK_UP,    HF_CONT,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,
		CK_TOGG,  RM_PREV,  RM_SPDD,  CK_DOWN,  HF_FDBK,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  PDF(2),                       _______,            _______,  _______,  _______,  _______,
		HF_TOGG,  _______,  _______,                                 _______,                                _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______
		),

    [2] = LAYOUT(
                KC_ESC,           KC_BRID, KC_BRIU, KC_NO,   KC_NO,   RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,            KC_PSCR, KC_SCRL, KC_PAUS,   KC_VOLU, KC_VOLD, KC_MUTE,   KC_CALC,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,   KC_NUM,  KC_PSLS, KC_PAST,   KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,     KC_PPLS,
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                                                   KC_P4,   KC_P5,   KC_P6,     KC_PPLS,
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,                     KC_UP,              KC_P1,   KC_P2,   KC_P3,     KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(3),   KC_RGUI, KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT,   KC_P0,   KC_P0,   KC_PDOT,   KC_PENT
		),

    [3] = LAYOUT(
                CK_RST,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             NK_TOGG,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,
		HF_RST,   RM_HUEU,  RM_VALU,  RM_SATU,  HF_DWLU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPLY,  _______,  KC_VOLU,  _______,  _______,  _______,  _______,
		RM_TOGG,  RM_HUED,  RM_VALD,  RM_SATD,  HF_DWLD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_MPRV,  KC_MNXT,  KC_VOLD,  _______,  _______,  _______,  _______,
		AU_TOGG,  RM_NEXT,  RM_SPDU,  CK_UP,    HF_CONT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,
		CK_TOGG,  RM_PREV,  RM_SPDD,  CK_DOWN,  HF_FDBK,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  PDF(0),                       _______,            _______,  _______,  _______,  _______,
		HF_TOGG,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______
		),
};