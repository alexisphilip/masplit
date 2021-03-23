/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "sendstring_french.h"

// Set le "capslock" à false par défault.
int lock = 0;

// Déclaration des "layers".
enum layers {
  _QWERTY, // Base layer.
  _LAYER1, // Layer 2.
  _LAYER2, // Layer 3.
  _LAYER3  // Layer 4.
};

// Déclaration des "keycodes".
enum keycodes { // Ces keycodes correspondent à des layers ou des macros.
  QWERTY = SAFE_RANGE,
  EXEMPLE,
  // Macros
  Cmd,
  Notepad,
  Gmail,
  Drive,
  CandS,
  CPicker,
  // String
  Mail,
  Rouge,
  Cmt,
  Explorer,
  RESTART,
  // Special characters
  SC_ee, // 183 É aigu
  SC_eg, // 212 È grave
  SC_ag, // 183 À grave
  SC_ug, // 235 Ù grave
  SC_cc, // 128 Ç cédille
  SC_oe, // 0156 œ || 0140 Œ
  SC_ae, // 145  æ || 146  Æ
  SC_qo, // 171 « (quote open)
  SC_qc, // 187 » (quote close)
  // Emojis
  Tput,
  Tflip,
  Disface,
  Shrug
};

// Définition des "layers".
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE LAYER :
 * Qwerty (sera traduit en français par l'OS) :
 * - Dispostion AZERTY ;
 * - Accès à deux couches supplémentaires (LAYER1 et LAYER2).
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |C.lock|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |LAYER2|LAYER1|    Space    |LAYER1|LAYER2| Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,      KC_1,    KC_2,    KC_3,        KC_4,        KC_5,   KC_6,   KC_7,        KC_8,        KC_9,        KC_0,    KC_DEL,  \
  KC_TAB,      KC_Q,    KC_W,    KC_E,        KC_R,        KC_T,   KC_Y,   KC_U,        KC_I,        KC_O,        KC_P,    KC_BSPC, \
  KC_CAPSLOCK, KC_A,    KC_S,    KC_D,        KC_F,        KC_G,   KC_H,   KC_J,        KC_K,        KC_L,        KC_SCLN, KC_ENT,  \
  KC_LSFT,     KC_Z,    KC_X,    KC_C,        KC_V,        KC_B,   KC_N,   KC_M,        KC_COMM,     KC_DOT,      KC_SLSH, KC_RSFT, \
  KC_LCTL,     KC_LGUI, KC_LALT, MO(_LAYER2), MO(_LAYER1), KC_SPC, KC_SPC, MO(_LAYER1), MO(_LAYER2), MO(_LAYER3), KC_APP,  KC_RCTL  \
),

/* LAYER 1 :
 * - Caractères spéciaux ;
 * - Contrôles de navigateur Internet ;
 * - Gestion des fenêtres (CtrlT & CtrlW).
 * ,-------------------------------------------------------------------------.
 * |     |     |  ~  |  #  |       |     |  `  |  |  |  \  |  @  |  °  |     |
 * |-----+-----+-----+-----+-------+-----+-----+-----+-----+-----+-----+-----|
 * |     |  €  |  *  |  =  |   +   |  À  |  Ç  | ù/Ù |  %  |  ^  |  $  |     |
 * |-----+-----+-----+-----+-------+-----+-----+-----+-----+-----+-----+-----|
 * |     |  [  |  ]  |  {  |   }   |  É  |  È  |  (  |  )  |  <  |  >  |     |
 * |-----+-----+-----+-----+-------+-----+-----+-----+-----+-----+-----+-----|
 * |     |CtrlW|CtrlT| URL |Refresh| œ/Œ | æ/Æ |  «  |  »  |     |     |     |
 * |-----+-----+-----+-----+-------+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |       |           |     |     |     |     |     |
 * `-------------------------------------------------------------------------'
 */
[_LAYER1] = LAYOUT( \
  _______, _______,    FR_TILD,    FR_HASH, _______, _______, FR_GRV,  FR_PIPE, FR_BSLS, FR_AT,   FR_OVRR, _______, \
  _______, FR_EURO,    FR_ASTR,    FR_EQL,  FR_PLUS, SC_ag,   SC_cc,   SC_ug,   FR_PERC, FR_CIRC, FR_DLR,  _______, \
  _______, FR_LBRC,    FR_RBRC,    FR_LCBR, FR_RCBR, SC_ee,   SC_eg,   FR_LPRN, FR_RPRN, FR_LESS, FR_GRTR, _______, \
  _______, LCTL(KC_Z), LCTL(KC_T), KC_F6,   KC_F5,   SC_oe,   SC_ae,   SC_qo,   SC_qc,   _______, _______, _______, \
  _______, _______,    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* LAYER 2 :
 * - Fonctions (F1 - F12) ;
 * - Gestion de directions (flèches directionnelles, début, haut de page...) ;
 * - Gestion des médias (volume sonore, play / pause) ;
 * - Execution d'applications (ouverture de "notepad", "cmd", "Gmail"...) ;
 * - Gestion du système (mise-en-veille, arrêt et redémarrage) ;
 * - Reset du microcontrôlleur.
 * ,---------------------------------------------------------------------------------------------------.
 * | Power | Restart | Sleep |        |        |       |      |      |      | Media- | Media+ |  Mute  |
 * |-------+---------+-------+--------+--------+-------+------+------+------+--------+--------+--------|
 * |       |   Cmd   |  Calc | Notepd | Explrr | Rouge |      | Home |  Up  |  End   |  P.up  | Play/P |
 * |-------+---------+-------+--------+--------+-------+------+------+------+--------+--------+--------|
 * |       | CPicker | CandS | Drive  | Gmail  |  Mail |      | Left | Down | Right  | P.down |  Vol+  |
 * |-------+---------+-------+--------+--------+-------+------+------+------+--------+--------+--------|
 * |       |  AltF4  |       |        |        |       |      |Ctrl L| Ins  | Ctrl R |        |  Vol-  |
 * |-------+---------+-------+--------+--------+-------+------+------+------+--------+--------+--------|
 * |       |  Reset  |       |        |        |              |      |      |        |        |        |
 * `---------------------------------------------------------------------------------------------------'
 */
[_LAYER2] = LAYOUT( \
  KC_PWR,  RESTART,     KC_SLEP, _______, _______,  _______, _______, _______,       _______, KC_MPRV,       KC_MNXT, KC_MUTE, \
  _______, Cmd,         KC_CALC, Notepad, Explorer, Rouge,   _______, KC_HOME,       KC_UP,   KC_END,        KC_PGUP, KC_MPLY, \
  _______, CPicker,     CandS,   Drive,   Gmail,    Mail,    _______, KC_LEFT,       KC_DOWN, KC_RGHT,       KC_PGDN, KC_VOLU, \
  _______, LALT(KC_F4), _______, _______, _______,  Cmt,     _______, LCTL(KC_LEFT), KC_INS,  LCTL(KC_RGHT), _______, KC_VOLD, \
  _______, RESET,       _______, _______, _______,  _______, _______, _______,       _______, _______,       _______, _______  \
),

/* LAYER 3 :
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LAYER3] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______,  _______, _______, \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______,  _______, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______  \
)
};

// Cette fonction est appellée à chaque touche pressée ou relachée.
// Elle vérifie si la touche pressée correspond à un cas du switch.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    // tflip: (╯°□°)╯ ︵ ┻━┻
    // tflip2: ┻━┻︵ \(°□°)/ ︵ ┻━┻
    // fu: t(-_-t)
    // cloud: (っ◕‿◕)っ
    // shrug: ¯\_(ツ)_/¯
    // disface: ಠ_ಠ
    // heartface: ♥‿♥
    // happyface: ʘ‿ʘ

    //cd C:/Users/Alexis/Documents/Keyboard/qmk_firmware
    //make handwired/puch:default:avrdude

    // Set le caps lock à true ou false;
    case KC_CAPSLOCK:
      if (record->event.pressed) {
        if (lock) lock = 0;
        else lock = 1;
      };
    break;

    // É
    case SC_ee:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_4);
        tap_code(KC_KP_4);
        unregister_code(KC_LALT);
      };
    break;

    // È
    case SC_eg:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_2);
        tap_code(KC_KP_1);
        tap_code(KC_KP_2);
        unregister_code(KC_LALT);
      };
    break;

    // À
    case SC_ag:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_8);
        tap_code(KC_KP_3);
        unregister_code(KC_LALT);
      };
    break;

    // Ç
    case SC_cc:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_2);
        tap_code(KC_KP_8);
        unregister_code(KC_LALT);
      };
    break;

    // "ù" ou "Ù"
    case SC_ug:
      if (record->event.pressed) {
        // Si maljuscule non active.
        if (!lock) {
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_5);
          tap_code(KC_KP_1);
          unregister_code(KC_LALT);
        } else {
          register_code(KC_LALT);
          tap_code(KC_KP_2);
          tap_code(KC_KP_3);
          tap_code(KC_KP_5);
          unregister_code(KC_LALT);
        }
      };
    break;

    // "œ" ou "Œ"
    case SC_oe:
      if (record->event.pressed) {
        // Si maljuscule non active.
        if (!lock) {
          register_code(KC_LALT);
          tap_code(KC_KP_0);
          tap_code(KC_KP_1);
          tap_code(KC_KP_5);
          tap_code(KC_KP_6);
          unregister_code(KC_LALT);
        } else {
          register_code(KC_LALT);
          tap_code(KC_KP_0);
          tap_code(KC_KP_1);
          tap_code(KC_KP_4);
          tap_code(KC_KP_0);
          unregister_code(KC_LALT);
        }
      };
    break;

    // "æ" ou "Æ"
    case SC_ae:
      if (record->event.pressed) {
        // Si maljuscule non active.
        if (!lock) {
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_4);
          tap_code(KC_KP_5);
          unregister_code(KC_LALT);
        } else {
          register_code(KC_LALT);
          tap_code(KC_KP_1);
          tap_code(KC_KP_4);
          tap_code(KC_KP_6);
          unregister_code(KC_LALT);
        }
      };
    break;

    // «
    case SC_qo:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_7);
        tap_code(KC_KP_1);
        unregister_code(KC_LALT);
      };
    break;

    // »
    case SC_qc:
      if (record->event.pressed) {
        register_code(KC_LALT);
        tap_code(KC_KP_1);
        tap_code(KC_KP_8);
        tap_code(KC_KP_7);
        unregister_code(KC_LALT);
      };
    break;

    // Ecrit l'adresse e-mail.
    case Mail:
      if (record->event.pressed) {
        SEND_STRING("alexis.philip13@gmail.com");
      }
    break;

    // Ecrit le premier chapitre du "Petit Chaperon Rouge".
    case Rouge:
      if (record->event.pressed) {
        SEND_STRING("Il etait une fois une petite fille de village, la plus jolie qu'on eut su voir ; sa mere en etait folle, et sa mere-grand plus folle encore. Cette bonne femme lui fit faire un petit chaperon rouge, qui lui seyait si bien que partout on l'appelait le petit Chaperon rouge. Un jour sa mère, ayant cuit et fait des galettes, lui dit : « Va voir comme se porte ta mère-grand, car on m'a dit qu'elle était malade, porte-lui une galette et ce petit pot de beurre. » Le petit Chaperon rouge partit aussitôt pour aller chez sa mère-grand, qui demeurait dans un autre village. En passant dans un bois elle rencontra compère le loup, qui eut bien envie de la manger ; mais il n'osa, à cause de quelques bûcherons qui étaient dans la forêt. Il lui demanda où elle allait ; la pauvre enfant, qui ne savait pas qu'il est dangereux de s'arrêter à écouter un loup, lui dit : « Je vais voir ma mère-grand, et lui porter une galette avec un petit pot de beurre que ma mère lui envoie. »");
      }
    break;

    // Ecrit un commentaire de fonction.
    case Cmt:
      if (record->event.pressed) {
        SEND_STRING("/**" SS_TAP(X_ENTER) " * " SS_TAP(X_ENTER) "* " SS_TAP(X_ENTER) "* @param:  " SS_TAP(X_ENTER) "* @return: " SS_TAP(X_ENTER) "*/");
        tap_code(KC_UP); tap_code(KC_UP); tap_code(KC_UP); tap_code(KC_UP);
      }
    break;

    // Execute cmd.exe
    case Cmd:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
      };
    break;

    // Execute notepad.exe
    case Notepad:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("notepad" SS_TAP(X_ENTER));
      };
    break;

    // Execute l'explorateur Windows.
    case Explorer:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(300);

        SEND_STRING("start ." SS_TAP(X_ENTER));
        _delay_ms(500);

        register_code(KC_LALT); tap_code(KC_TAB); unregister_code(KC_LALT);
        _delay_ms(300);
        register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT);
      };
    break;

    // Ouvre Gmail dans le navigateur par défaut.
    case Gmail:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(300);

        SEND_STRING("cmd /c start http://gmail.com/" SS_TAP(X_ENTER));
        _delay_ms(500);

        register_code(KC_LALT); tap_code(KC_TAB); unregister_code(KC_LALT);
        _delay_ms(300);
        register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT);
      };
    break;

    // Ouvre Drive dans le navigateur par défaut.
    case Drive:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(300);

        SEND_STRING("cmd /c start http://drive.google.com/" SS_TAP(X_ENTER));
        _delay_ms(500);
        
        register_code(KC_LALT); tap_code(KC_TAB); unregister_code(KC_LALT);
        _delay_ms(300);
        register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT);
      };
    break;

    // Copy and search. Copie le texte sélectionné et recherhe dans le navigateur.
    case CandS:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_LGUI("r"));
        _delay_ms(700);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(700);

        SEND_STRING("cmd /c start https://www.google.com/search?q=" SS_LCTRL("v") SS_TAP(X_ENTER));
        _delay_ms(700);
        register_code(KC_LALT); tap_code(KC_TAB); unregister_code(KC_LALT);
        _delay_ms(700);
        register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT);
      };
    break;

    // Color picker. Copie une couleur l'ouvre dans le color picker.
    case CPicker:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_LGUI("r"));
        _delay_ms(300);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(300);

        SEND_STRING("cmd /c start http://www.alexisphilip.fr/color-picker/index.html?color=" SS_LCTRL("v") SS_TAP(X_ENTER));
        _delay_ms(800);

        register_code(KC_LALT); tap_code(KC_TAB); unregister_code(KC_LALT);
        _delay_ms(300);
        register_code(KC_LALT); tap_code(KC_F4); unregister_code(KC_LALT);
      };
    break;

    // Restart l'ordinateur.
    case RESTART:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_LGUI("r"));
        _delay_ms(100);
        SEND_STRING("cmd" SS_TAP(X_ENTER));
        _delay_ms(100);
        SEND_STRING("shutdown /r /t 0" SS_TAP(X_ENTER));
      };
    break;


    /* Exemple d'un "case".
    "case MACRO" ou "case KC_".
    Si c'est une touche macro, il faut l'ajouter dans "keycodes". */
    case EXEMPLE:
      // Quand la touche est pressée.
      if (record->event.pressed) {
        // SENDSTRING("text");
      }
      // Quand la touche est relachée.
      else {

      }
      // Laisse la touche être appuyée.
      // return true;
      // Ne laisse pas la touche être appuyée.
      // return false;
    break;
  }

  return true;
};
