/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"
// #define RAISE MO(_RAISE)
// #define LOWER MO(_LOWER)

// MACROS
enum custom_keycodes {
    ARROW = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ARROW:
        if (record->event.pressed) {
            // when keycode is pressed
            SEND_STRING("=>");
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

// COMBOS
// https://codepen.io/mvaneijgen/full/LYEVQXp
// generated code has "_combo" added to end of variables in COMBO parameters
enum combos {
  F_D_ESC,
  F_S_F13,
  J_K_BSPC,
  J_L_DEL,
  // symbols
    // home row
  SPC_F_LPRN,
  ENT_J_RPRN,
  SPC_D_LCBR,
  ENT_K_RCBR,
  SPC_S_LBRC,
  ENT_L_RBRC,
  SPC_A_LT,
  ENT_SC_GT,
    // upper row
  SPC_Q_EXLM,
  SPC_W_AT,
  SPC_E_HASH,
  SPC_R_DLR,
  SPC_T_PERC,
  ENT_Y_CIRC,
  ENT_U_AMPR,
  ENT_I_ASTR,
  ENT_O_DQT,
  ENT_P_UNDS,
    // lower row
  SPC_GRV_TILD,
  ENT_SLSH_QUES,
  ENT_BSLS_PIPE,
  ENT_DOT_ARROW,
  ENT_EQL_GOEQ,
  // combo shifts
    // left hand
  ENT_Q_SFTA,
  ENT_W_SFTA,
  ENT_E_SFTA,
  ENT_R_SFTA,
  ENT_T_SFTA,
  ENT_A_SFTA,
  ENT_S_SFTA,
  ENT_D_SFTA,
  ENT_F_SFTA,
  ENT_G_SFTA,
  ENT_Z_SFTA,
  ENT_X_SFTA,
  ENT_C_SFTA,
  ENT_V_SFTA,
  ENT_B_SFTA,
    // right hand
  SPC_Y_SFTA,
  SPC_U_SFTA,
  SPC_I_SFTA,
  SPC_O_SFTA,
  SPC_P_SFTA,
  SPC_H_SFTA,
  SPC_J_SFTA,
  SPC_K_SFTA,
  SPC_L_SFTA,
  SPC_N_SFTA,
  SPC_M_SFTA,
  SPC_SCLN_COLN,
};

const uint16_t PROGMEM f_d_esc[] = { KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM f_s_f13[] = { KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM j_k_bspc[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM j_l_del[] = { KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM spc_f_lprn[] = { KC_SPC, KC_F, COMBO_END};
const uint16_t PROGMEM ent_j_rprn[] = { KC_ENT, KC_J, COMBO_END};
const uint16_t PROGMEM spc_d_lcbr[] = { KC_SPC, KC_D, COMBO_END};
const uint16_t PROGMEM ent_k_rcbr[] = { KC_ENT, KC_K, COMBO_END};
const uint16_t PROGMEM spc_s_lbrc[] = { KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM ent_l_rbrc[] = { KC_ENT, KC_L, COMBO_END};
const uint16_t PROGMEM spc_a_lt[] = { KC_SPC, KC_A, COMBO_END};
const uint16_t PROGMEM ent_sc_gt[] = { KC_ENT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM spc_q_exlm[] = { KC_SPC, KC_Q, COMBO_END};
const uint16_t PROGMEM spc_w_at[] = { KC_SPC, KC_W, COMBO_END};
const uint16_t PROGMEM spc_e_hash[] = { KC_SPC, KC_E, COMBO_END};
const uint16_t PROGMEM spc_r_dlr[] = { KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM spc_t_perc[] = { KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM ent_y_circ[] = { KC_ENT, KC_Y, COMBO_END};
const uint16_t PROGMEM ent_u_ampr[] = { KC_ENT, KC_U, COMBO_END};
const uint16_t PROGMEM ent_i_astr[] = { KC_ENT, KC_I, COMBO_END};
const uint16_t PROGMEM ent_o_dqt[] = { KC_ENT, KC_O, COMBO_END};
const uint16_t PROGMEM ent_p_unds[] = { KC_ENT, KC_P, COMBO_END};
const uint16_t PROGMEM ent_dot_arrow[] = { KC_ENT, KC_DOT, COMBO_END};
const uint16_t PROGMEM ent_eql_goeq[] = { KC_ENT, KC_EQL, COMBO_END};
const uint16_t PROGMEM ent_slsh_ques[] = { KC_ENT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM ent_bsls_pipe[] = { KC_ENT, KC_BSLS, COMBO_END};
const uint16_t PROGMEM spc_grv_tild[] = { KC_SPC, KC_GRV, COMBO_END};
// combo shift
const uint16_t PROGMEM ent_q_sftq[] = {KC_ENT ,KC_Q , COMBO_END};
const uint16_t PROGMEM ent_w_sftw[] = {KC_ENT ,KC_W , COMBO_END};
const uint16_t PROGMEM ent_e_sfte[] = {KC_ENT ,KC_E , COMBO_END};
const uint16_t PROGMEM ent_r_sftr[] = {KC_ENT ,KC_R , COMBO_END};
const uint16_t PROGMEM ent_t_sftt[] = {KC_ENT ,KC_T , COMBO_END};
const uint16_t PROGMEM ent_a_sfta[] = {KC_ENT ,KC_A , COMBO_END};
const uint16_t PROGMEM ent_s_sfts[] = {KC_ENT ,KC_S , COMBO_END};
const uint16_t PROGMEM ent_d_sftd[] = {KC_ENT ,KC_D , COMBO_END};
const uint16_t PROGMEM ent_f_sftf[] = {KC_ENT ,KC_F , COMBO_END};
const uint16_t PROGMEM ent_g_sftg[] = {KC_ENT ,KC_G , COMBO_END};
const uint16_t PROGMEM ent_z_sftz[] = {KC_ENT ,KC_Z , COMBO_END};
const uint16_t PROGMEM ent_x_sftx[] = {KC_ENT ,KC_X , COMBO_END};
const uint16_t PROGMEM ent_c_sftc[] = {KC_ENT ,KC_C , COMBO_END};
const uint16_t PROGMEM ent_v_sftv[] = {KC_ENT ,KC_V , COMBO_END};
const uint16_t PROGMEM ent_b_sftb[] = {KC_ENT ,KC_B , COMBO_END};
const uint16_t PROGMEM spc_y_sfty[] = {KC_SPC ,KC_Y , COMBO_END};
const uint16_t PROGMEM spc_u_sftu[] = {KC_SPC ,KC_U , COMBO_END};
const uint16_t PROGMEM spc_i_sfti[] = {KC_SPC ,KC_I , COMBO_END};
const uint16_t PROGMEM spc_o_sfto[] = {KC_SPC ,KC_O , COMBO_END};
const uint16_t PROGMEM spc_p_sftp[] = {KC_SPC ,KC_P , COMBO_END};
const uint16_t PROGMEM spc_h_sfth[] = {KC_SPC ,KC_H , COMBO_END};
const uint16_t PROGMEM spc_j_sftj[] = {KC_SPC ,KC_J , COMBO_END};
const uint16_t PROGMEM spc_k_sftk[] = {KC_SPC ,KC_K , COMBO_END};
const uint16_t PROGMEM spc_l_sftl[] = {KC_SPC ,KC_L , COMBO_END};
const uint16_t PROGMEM spc_n_sftn[] = {KC_SPC ,KC_N , COMBO_END};
const uint16_t PROGMEM spc_m_sftm[] = {KC_SPC ,KC_M , COMBO_END};
const uint16_t PROGMEM spc_scln_coln[] = { KC_SPC, KC_SCLN, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [F_D_ESC] = COMBO(f_d_esc, KC_ESC),
  [F_S_F13] = COMBO(f_s_f13, KC_F13),
  [J_K_BSPC] = COMBO(j_k_bspc, KC_BSPC),
  [J_L_DEL] = COMBO(j_l_del, KC_DEL),
  [SPC_F_LPRN] = COMBO(spc_f_lprn, KC_LPRN),
  [ENT_J_RPRN] = COMBO(ent_j_rprn, KC_RPRN),
  [SPC_D_LCBR] = COMBO(spc_d_lcbr, KC_LCBR),
  [ENT_K_RCBR] = COMBO(ent_k_rcbr, KC_RCBR),
  [SPC_S_LBRC] = COMBO(spc_s_lbrc, KC_LBRC),
  [ENT_L_RBRC] = COMBO(ent_l_rbrc, KC_RBRC),
  [SPC_A_LT] = COMBO(spc_a_lt, KC_LT),
  [ENT_SC_GT] = COMBO(ent_sc_gt, KC_GT),
  [SPC_Q_EXLM] = COMBO(spc_q_exlm, KC_EXLM),
  [SPC_W_AT] = COMBO(spc_w_at, KC_AT),
  [SPC_E_HASH] = COMBO(spc_e_hash, KC_HASH),
  [SPC_R_DLR] = COMBO(spc_r_dlr, KC_DLR),
  [SPC_T_PERC] = COMBO(spc_t_perc, KC_PERC),
  [ENT_Y_CIRC] = COMBO(ent_y_circ, KC_CIRC),
  [ENT_U_AMPR] = COMBO(ent_u_ampr, KC_AMPR),
  [ENT_I_ASTR] = COMBO(ent_i_astr, KC_ASTR),
  [ENT_O_DQT] = COMBO(ent_o_dqt, KC_DQT),
  [ENT_P_UNDS] = COMBO(ent_p_unds, KC_UNDS),
  [ENT_DOT_ARROW] = COMBO_ACTION(ent_dot_arrow),
  [ENT_EQL_GOEQ] = COMBO_ACTION(ent_eql_goeq),
  [ENT_SLSH_QUES] = COMBO(ent_slsh_ques,KC_QUES),
  [ENT_BSLS_PIPE] = COMBO(ent_bsls_pipe,KC_PIPE),
  [SPC_GRV_TILD] = COMBO(spc_grv_tild, KC_TILD),
// combo shifts
  [ENT_Q_SFTA] = COMBO_ACTION(ent_q_sftq),
  [ENT_W_SFTA] = COMBO_ACTION(ent_w_sftw),
  [ENT_E_SFTA] = COMBO_ACTION(ent_e_sfte),
  [ENT_R_SFTA] = COMBO_ACTION(ent_r_sftr),
  [ENT_T_SFTA] = COMBO_ACTION(ent_t_sftt),
  [ENT_A_SFTA] = COMBO_ACTION(ent_a_sfta),
  [ENT_S_SFTA] = COMBO_ACTION(ent_s_sfts),
  [ENT_D_SFTA] = COMBO_ACTION(ent_d_sftd),
  [ENT_F_SFTA] = COMBO_ACTION(ent_f_sftf),
  [ENT_G_SFTA] = COMBO_ACTION(ent_g_sftg),
  [ENT_Z_SFTA] = COMBO_ACTION(ent_z_sftz),
  [ENT_X_SFTA] = COMBO_ACTION(ent_x_sftx),
  [ENT_C_SFTA] = COMBO_ACTION(ent_c_sftc),
  [ENT_V_SFTA] = COMBO_ACTION(ent_v_sftv),
  [ENT_B_SFTA] = COMBO_ACTION(ent_b_sftb),
  [SPC_Y_SFTA] = COMBO_ACTION(spc_y_sfty),
  [SPC_U_SFTA] = COMBO_ACTION(spc_u_sftu),
  [SPC_I_SFTA] = COMBO_ACTION(spc_i_sfti),
  [SPC_O_SFTA] = COMBO_ACTION(spc_o_sfto),
  [SPC_P_SFTA] = COMBO_ACTION(spc_p_sftp),
  [SPC_H_SFTA] = COMBO_ACTION(spc_h_sfth),
  [SPC_J_SFTA] = COMBO_ACTION(spc_j_sftj),
  [SPC_K_SFTA] = COMBO_ACTION(spc_k_sftk),
  [SPC_L_SFTA] = COMBO_ACTION(spc_l_sftl),
  [SPC_N_SFTA] = COMBO_ACTION(spc_n_sftn),
  [SPC_M_SFTA] = COMBO_ACTION(spc_m_sftm),
  [SPC_SCLN_COLN] = COMBO(spc_scln_coln,KC_COLN),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case ENT_DOT_ARROW:
      if (pressed) {
        SEND_STRING("=>");
      }
      break;
    case ENT_EQL_GOEQ:
      if (pressed) {
        SEND_STRING(":=");
      }
      break;
    case ENT_Q_SFTA: if (pressed) { SEND_STRING("Q"); } break;
    case ENT_W_SFTA: if (pressed) { SEND_STRING("W"); } break;
    case ENT_E_SFTA: if (pressed) { SEND_STRING("E"); } break;
    case ENT_R_SFTA: if (pressed) { SEND_STRING("R"); } break;
    case ENT_T_SFTA: if (pressed) { SEND_STRING("T"); } break;
    case ENT_A_SFTA: if (pressed) { SEND_STRING("A"); } break;
    case ENT_S_SFTA: if (pressed) { SEND_STRING("S"); } break;
    case ENT_D_SFTA: if (pressed) { SEND_STRING("D"); } break;
    case ENT_F_SFTA: if (pressed) { SEND_STRING("F"); } break;
    case ENT_G_SFTA: if (pressed) { SEND_STRING("G"); } break;
    case ENT_Z_SFTA: if (pressed) { SEND_STRING("Z"); } break;
    case ENT_X_SFTA: if (pressed) { SEND_STRING("X"); } break;
    case ENT_C_SFTA: if (pressed) { SEND_STRING("C"); } break;
    case ENT_V_SFTA: if (pressed) { SEND_STRING("V"); } break;
    case ENT_B_SFTA: if (pressed) { SEND_STRING("B"); } break;
    case SPC_Y_SFTA: if (pressed) { SEND_STRING("Y"); } break;
    case SPC_U_SFTA: if (pressed) { SEND_STRING("U"); } break;
    case SPC_I_SFTA: if (pressed) { SEND_STRING("I"); } break;
    case SPC_O_SFTA: if (pressed) { SEND_STRING("O"); } break;
    case SPC_P_SFTA: if (pressed) { SEND_STRING("P"); } break;
    case SPC_H_SFTA: if (pressed) { SEND_STRING("H"); } break;
    case SPC_J_SFTA: if (pressed) { SEND_STRING("J"); } break;
    case SPC_K_SFTA: if (pressed) { SEND_STRING("K"); } break;
    case SPC_L_SFTA: if (pressed) { SEND_STRING("L"); } break;
    case SPC_N_SFTA: if (pressed) { SEND_STRING("N"); } break;
    case SPC_M_SFTA: if (pressed) { SEND_STRING("M"); } break;
  }
}

//// shortenings
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _DEV 3
#define _PLOVER 4
#define _GAME 5

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
      KC_DEL  ,  KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,  KC_B   ,            KC_N   ,  KC_M   ,  KC_COMM, KC_DOT  ,  KC_SLSH,  KC_BSLASH,
                           KC_GRV ,  A_TAB  ,                                                    KC_PLUS, KC_EQL  ,
                                   LT(_RAISE, KC_TAB) , KC_SPC  ,            KC_ENT , LT(_LOWER, KC_CAPS),
                                              KC_LALT , KC_LCTL ,            KC_LCTL, KC_LALT  ,
                                            TG(_GAME) , KC_LGUI ,            KC_LGUI, CG_TOGG
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
     KC_PSCR  , _______ , _______ , _______ , _______ , _______ ,             KC_TAB  , _______ , _______ , _______ , _______ , _______ ,
                         KC_VOLD , KC_VOLU ,                                                     _______ , _______ ,
                                             _______ , _______ ,             _______ , MO(_DEV) ,
                                             _______ , _______ ,             _______ ,  _______ ,
                                             RESET   , _______ ,             _______ ,  RESET   
  ),

  [_DEV] = LAYOUT_5x6(

     _______ , _______ , _______ , _______ , CMB_TOG , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , KC_LBRC , KC_LCBR , KC_LPRN , _______ ,             _______ , KC_RPRN , KC_RCBR , KC_RBRC , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , ARROW   , _______ , _______ , _______ ,
                         _______ , _______ ,                                                     _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______ ,
                                             _______ , _______ ,             _______ , _______


  ),
  

// https://www.paulfioravanti.com/blog/starting-stenography-ergodox/
  [_PLOVER] = LAYOUT_5x6(

     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
     XXXXXXX , STN_N1  , STN_N2  , STN_N3  , STN_N4  , STN_N5  ,             STN_N6  , STN_N7  , STN_N8  , STN_N9  , STN_NA  , STN_NB  ,
     XXXXXXX , STN_S1  , STN_TL  , STN_PL  , STN_HL  , STN_ST1 ,             STN_ST3 , STN_FR  , STN_PR  , STN_LR  , STN_TR  , STN_DR  ,
     XXXXXXX , STN_S2  , STN_KL  , STN_WL  , STN_RL  , STN_ST2 ,             STN_ST4 , STN_RR  , STN_BR  , STN_GR  , STN_SR  , STN_ZR  ,
                         XXXXXXX , XXXXXXX ,                                                     XXXXXXX , XXXXXXX ,
                                             STN_A   , STN_O   ,             STN_E   , STN_U   ,
                                             XXXXXXX , XXXXXXX ,             XXXXXXX , XXXXXXX ,
                                         TG(_PLOVER) , XXXXXXX ,             XXXXXXX , XXXXXXX

  ),

  [_GAME] = LAYOUT_5x6(

      KC_GRV  ,  KC_1   , KC_1   ,  KC_2   ,  KC_3   ,  KC_4   ,             KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0   ,  KC_BSPC  ,
      KC_TAB  ,  KC_I   , KC_Q   ,  KC_W   ,  KC_E   ,  KC_R   ,             KC_Y   ,  KC_U   ,  KC_I   ,  KC_O   ,  KC_P   ,  KC_MINS  ,
      OSM_SFT ,  KC_M   , KC_A   ,  KC_S   ,  KC_D   ,  KC_F   ,             KC_H   ,  KC_J   ,  KC_K   ,  KC_L   ,  KC_SCLN ,  SFT_QT   ,
      KC_DEL  ,  KC_ESC , KC_Z   ,  KC_X   ,  KC_C   ,  KC_V   ,             KC_N   ,  KC_M   ,  KC_COMM, KC_DOT  ,  KC_SLSH,  KC_BSLASH,
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
