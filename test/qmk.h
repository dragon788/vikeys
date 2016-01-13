static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   1  |   2  |   3  |   4  |   5  |   \  |           |   '  |   6  |   7  |   8  |   9  |   0  |   =    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  | ~Fn1 |           | ~Fn3 |   Y  |   U  |   I  |   O  |   P  |   [    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RShift |
     * |--------+------+------+------+------+------|  Fn0 |           | ~Fn4 |------+------+------+------+------+--------|
     * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RCtrl  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | ~Fn1 | ~Fn2 | Caps | LAlt | LGui |                                       |  Lft |  Up  |  Dn  | Rght | ~Fn4 |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | +Fn2 | Home |       | PgUp | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 | BkSp |  ESC |------|       |------| Enter| Space|
     *                                 |      |      |  Spc |       | Ins  |      |      |
     *                                 `--------------------'       `--------------------'
     */
    /* Keymap 0: Default Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ESC    |   1  |   2  |   3  |   4  |   5  |+Fn3|           |   '  |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   D  |   F  |   K  | +Fn1 |           | ~Fn3 |   J  |   U  |   R  |   L  |   ;  |   =    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | LCtrl  |   A  |   S  |   E  |   T  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | '      |
     * |--------+------+------+------+------+------|  Fn0 |           | ~Fn4 |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LAlt | ~Fn2 | Caps | ~Fn1 | LGui |                                       |  Esc |  Dn  |  [   | ]    | Rgui |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | +Fn2 | Home |       | PgUp | Del  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |  End |       | PgDn |      |      |
     *                                 | Space| BkSp |------|       |------| Enter| Space|
     *                                 |      |      |  Spc |       | Ins  |      |      |
     *                                 `--------------------'       `--------------------'
     */
/* Standard qwerty
    KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_ESC,
        KC_BSLS,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_FN2,
        KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_FN1,
        KC_LGUI,KC_GRV, KC_BSLS,KC_LEFT,KC_RGHT,
                                      KC_LCTL,KC_LALT,
                                           KC_HOME,
                                 KC_BSPC,KC_DEL, KC_END,
        // right hand
             KC_FN3, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
             KC_LBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_RBRC,
                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
             KC_FN1, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                       KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_RGUI,
        KC_RALT,KC_RCTL,
        KC_PGUP,
        KC_PGDN,KC_ENT, KC_SPC
    ),
    */
    KEYMAP(  // layout: layer 0: default
        // left hand
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_FN4,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LALT,
        KC_CAPS, KC_FN3, KC_LALT,KC_FN1,KC_LGUI,
                                      KC_MPLY, KC_MUTE,
                                           KC_VOLU,
                                 KC_BSPC,KC_DEL, KC_VOLD,
        // right hand
             KC_GRV, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,
             KC_RBRC, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_EQL,
                  KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,
             KC_BSLS, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
                       KC_RALT,KC_FN1,  KC_LBRC,KC_RBRC,KC_LGUI,
        KC_PGUP,KC_FN2,
        KC_PGDN,
        KC_INS, KC_ENT, KC_SPC
    ),
    KEYMAP(  // layout: layer 1: norman
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,    KC_TRNS,
        KC_TRNS, KC_A,    KC_S,    KC_E,    KC_T,    KC_G,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_FN5, KC_TRNS,
                                      KC_TRNS, KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
             KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
             KC_TRNS, KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN,   KC_TRNS,
                  KC_Y,   KC_N,   KC_I,   KC_O,   KC_H, KC_TRNS,
             KC_TRNS, KC_P,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_TRNS,
                       KC_TRNS,KC_FN5,  KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

    KEYMAP(  // layout: layer 2: F-keys instead of numbers
        // left hand
        KC_FN0,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
        KC_TRNS,KC_EQL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_FN4,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_TRNS,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_TRNS, KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_GRV, 
             KC_TRNS,KC_FN7,KC_FN8,KC_FN6,KC_BSLS,KC_LBRC,KC_RBRC,
                  KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_BSLS,KC_DEL,
             KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    ),


    KEYMAP(  // layout: layer 3: mouse + numpad
        // left hand
        KC_TRNS,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_PAUS,KC_PSCR,
        KC_TRNS,WH_KC_L,WH_KC_U,WH_KC_D,WH_KC_R,KC_BTN2,KC_TRNS,
        KC_TRNS,MS_KC_L,MS_KC_U,MS_KC_D,MS_KC_R,KC_BTN1,
        KC_TRNS,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_BTN3,KC_TRNS,
        KC_TRNS,KC_FN4,KC_TRNS,KC_TRNS,KC_TRNS,
                                      KC_FN4,KC_TRNS,
                                           KC_TRNS,
                                 KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_SLCK,KC_NLCK,KC_PSLS,KC_PAST,KC_PAST,KC_PMNS,KC_BSPC,
             KC_TRNS,KC_NO,  KC_P7,  KC_P8,  KC_P9,  KC_PMNS,KC_BSPC,
                  KC_NO,  KC_P4,  KC_P5,  KC_P6,  KC_PPLS,KC_PENT,
             KC_TRNS,KC_NO,  KC_P1,  KC_P2,  KC_P3,  KC_PPLS,KC_PENT,
                       KC_P0,  KC_PDOT,KC_SLSH,KC_PENT,KC_PENT,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS
    )
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0 - Teensy key
    ACTION_LAYER_MOMENTARY(2),                      // FN1 - switch to Layer1 from layer 0
    ACTION_LAYER_SET(1, ON_PRESS),                  // FN2 - push Layer2
    ACTION_LAYER_SET(3, ON_PRESS),                  // FN3 - push Layer3
    ACTION_LAYER_SET(0, ON_PRESS),                  // FN4 - push Layer0
    ACTION_LAYER_MOMENTARY(1),                      // FN5 - switch to Layer1 from layer 1
    ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),             // FN6  = Shifted BackSlash // " in WorkmanCRO(D(LSHIFT), D(D), END),
    ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),             // FN7  = Shifted BackSlash // " in Workman
    ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),             // FN8  = Shifted BackSlash // " in Workman
    MACRO(D(LSHIFT), D(D), END),

};


void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}

/*
    KEYMAP(  // layout: layer N: transparent on edges, all others are empty
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,  
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,NO,  NO,  NO,  NO,  NO,  
        TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
        TRNS,TRNS,TRNS,LALT,LGUI,
                                      TRNS,TRNS,
                                           TRNS,
                                 LCTL,LSFT,TRNS,
        // right hand
             NO,  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                  NO,  NO,  NO,  NO,  NO,  TRNS,
             TRNS,NO,  NO,  NO,  NO,  NO,  TRNS,
                       RGUI,RALT,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,RSFT,RCTL
    ),
    KEYMAP(  // layout: layer N: fully transparent
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
*/



/*
 * Fn action definition
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(TEENSY_KEY),                    // FN0  - Teensy key

    ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),             // FN1  = Shifted BackSlash // " in Workman
    ACTION_MODS_KEY(MOD_LSFT, KC_MINS),             // FN2  = Shifted Minus     // \ in Workman
    ACTION_MODS_KEY(MOD_LSFT, KC_COMM),             // FN3  = Shifted comma     // < in Workman
    ACTION_MODS_KEY(MOD_LSFT, KC_DOT),              // FN4  = Shifted dot       // > in Workman

    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_BSPC),         // FN5  = LShift with tap BackSpace
    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_DEL),          // FN6  = LCtrl  with tap Delete
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_ESC),          // FN7  = LAlt   with tap Escape
    ACTION_MODS_TAP_KEY(MOD_RALT, KC_INS),          // FN8  = RAlt   with tap Ins
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),          // FN9  = RShift with tap Enter
    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_SPC),          // FN10 = RCtrl  with tap Space

    ACTION_MODS_TAP_KEY(MOD_LSFT, KC_TAB),          // FN11 = LShift with tap Tab
    ACTION_MODS_TAP_KEY(MOD_LCTL, KC_GRV),          // FN12 = LCtrl  with tap Tilda
    ACTION_MODS_TAP_KEY(MOD_LALT, KC_SPC),          // FN13 = LAlt   with tap Space
    ACTION_MODS_TAP_KEY(MOD_LGUI, KC_ESC),          // FN14 = LGui   with tap Escape
    ACTION_MODS_TAP_KEY(MOD_RSFT, KC_QUOT),         // FN15 = RShift with tap quotes
    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RBRC),         // FN16 = RCtrl  with tap ]

    ACTION_LAYER_SET(0, ON_BOTH),                   // FN17 - set Layer0
    ACTION_LAYER_SET(1, ON_BOTH),                   // FN18 - set Layer1, to use Workman layout at firmware level
    ACTION_LAYER_SET(2, ON_BOTH),                   // FN19 - set Layer2, to use with Numpad keys

    ACTION_LAYER_MOMENTARY(1),                      // FN20 - momentary Layer2, to use with Numpad keys
    ACTION_LAYER_TAP_KEY(5, KC_ENT),                // FN21 - momentary Layer5 on Enter, to use with F* keys on top row
    ACTION_LAYER_TAP_KEY(6, KC_ENT),                // FN22 - momentary Layer6 on Enter, to use with F* keys on top row, cursor, Teensy, Workman-layer switch
    ACTION_LAYER_MOMENTARY(7),                      // FN23 - momentary Layer7, to use with F* keys (F1-F24)

    ACTION_LAYER_TAP_KEY(4, KC_Z),                  // FN24 = momentary Layer4 on Z key, to use with unconvenient keys
    ACTION_LAYER_TAP_KEY(3, KC_X),                  // FN25 = momentary Layer3 on X key, to use with F* keys
    ACTION_LAYER_TAP_KEY(8, KC_C),                  // FN26 = momentary Layer8 on C key, to use with mouse and navigation keys
    ACTION_LAYER_TAP_KEY(2, KC_V),                  // FN27 = momentary Layer2 on V key, to use with Numpad keys

    // i'd like to remove this - will try to get used to live without this and convert them to usual keys
    ACTION_LAYER_TAP_KEY(4, KC_A),                  // FN28 = momentary Layer4 on A key, to use with unconvenient keys
    ACTION_LAYER_TAP_KEY(3, KC_S),                  // FN29 = momentary Layer3 on S key, to use with F* keys
    ACTION_LAYER_TAP_KEY(8, KC_D),                  // FN30 = momentary Layer8 on D key, to use with mouse and navigation keys
    ACTION_LAYER_TAP_KEY(2, KC_F),                  // FN31 = momentary Layer2 on F key, to use with Numpad keys
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    print("action_function called\n");
    print("id  = "); phex(id); print("\n");
    print("opt = "); phex(opt); print("\n");
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
 */

