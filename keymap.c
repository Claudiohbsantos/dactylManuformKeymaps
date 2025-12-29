/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
// #define RAISE MO(_RAISE)
// #define LOWER MO(_LOWER)

//// shortenings
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _DEV 3
#define _GAME 4

// #define SFT_A LSFT_T(KC_A )
// #define SFT_SC RSFT_T(KC_SCLN )
#define SFT_QT RSFT_T(KC_QUOT)
#define A_TAB LALT(KC_TAB)

#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
      KC_GRV  ,  KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,  KC_5   ,            KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC  ,
      KC_TAB  ,  KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,  KC_T   ,            KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   ,  KC_MINS  ,
      OSM_SFT ,  KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,  KC_G   ,            KC_H   ,  KC_J   ,  KC_K   ,  KC_L   ,  KC_SCLN ,  SFT_QT   ,
      KC_DEL  ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,            KC_N   ,  KC_M   ,  KC_COMM, KC_DOT  ,  KC_SLSH,  KC_BSLS,
                           KC_GRV ,  A_TAB  ,                                                    KC_PLUS, KC_EQL  ,
                                   LT(_RAISE, KC_TAB) , KC_SPC  ,            KC_ENT , LT(_LOWER, KC_CAPS),
                                              KC_LALT , KC_LCTL ,            KC_RCTL, KC_RALT  ,
                                            TG(_GAME) , KC_LGUI ,            KC_RGUI, CG_TOGG
  ),

  [_LOWER] = LAYOUT_5x6(
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ ,  KC_P7  ,  KC_P8  ,  KC_P9  , KC_PPLS , KC_PLUS ,
     _______ , KC_HOME , KC_PGUP , KC_PGDN , KC_END  , _______ ,             _______ ,  KC_P4  ,  KC_P5  ,  KC_P6  , KC_PMNS , KC_PIPE ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ ,  KC_P1  ,  KC_P2  ,  KC_P3  , KC_EQL  , KC_UNDS ,
                         _______ , KC_PSCR ,                                                      KC_P0, KC_ASTR,
                                            MO(_DEV) , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______

  ),

  [_RAISE] = LAYOUT_5x6(
     KC_F12  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,             KC_F6   ,  KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  ,
     _______ , KC_MPRV , KC_MUTE , KC_MPLY , KC_MNXT , _______ ,             _______ , _______ , KC_UP   , _______ , _______ , KC_MUTE ,
     _______ , KC_LEFT , KC_UP   , KC_DOWN , KC_RGHT , _______ ,             _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ ,
     KC_F12  ,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,             KC_F6   ,  KC_F7  ,  KC_F8  ,  KC_F9  , KC_F10  , KC_F11  ,
                         KC_VOLD , KC_VOLU ,                                                     _______ , _______ ,
                                             _______ , _______ ,             _______ , MO(_DEV) ,
                                             _______ , _______ ,             _______ ,  _______ ,
                                             _______ , QK_BOOT  ,             QK_RBT  , _______
  ),

  [_DEV] = LAYOUT_5x6(

     _______ , _______ , _______ , _______ , QK_COMBO_TOGGLE , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , KC_LBRC , KC_LCBR , KC_LPRN , _______ ,             _______ , KC_RPRN , KC_RCBR , KC_RBRC , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
                         _______ , _______ ,                                                     _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______


  ),


  [_GAME] = LAYOUT_5x6(

      KC_GRV  ,  KC_1   , KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,             KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC  ,
      KC_TAB  ,  KC_I   , KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,             KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   ,  KC_MINS  ,
      OSM_SFT ,  KC_M   , KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,             KC_H   ,  KC_J   ,  KC_K   ,  KC_L   ,  KC_SCLN ,  SFT_QT   ,
      KC_DEL  ,  KC_ESC , KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,             KC_N   ,  KC_M   ,  KC_COMM, KC_DOT  ,  KC_SLSH,  KC_BSLS,
                           KC_GRV ,  A_TAB  ,                                                    KC_PLUS, KC_EQL  ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                            TG(_GAME)  , _______ ,             _______ , _______


  ),

};

  // [LAYER] = LAYOUT_5x6(

  //    _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
  //    _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
  //    _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
  //    _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
  //                        _______ , _______ ,                                                     _______ , _______ ,
  //                                            _______ , _______ ,             _______ , _______ ,
  //                                            _______ , _______ ,             _______ , _______ ,
  //                                            _______ , _______ ,             _______ , _______

  // ),
