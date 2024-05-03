#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LEDSET,
	_DEMOCRACY
};

enum keycodes {
	QMK_BEST = SAFE_RANGE,
	TABOUT,
	TASKMANAGE,
	CLIPB,
	BAR380MM
	// Other declarations would go here, separated by commas, if you have them
};
//macro functions, this layout takes standard KC codes, make sure to unregister everything!
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
		case TABOUT: 
				if(record->event.pressed){
					//keydown event
					register_code(KC_LGUI);
					register_code(KC_TAB);
				} else {
					//keyup event
					unregister_code(KC_TAB);
					unregister_code(KC_LGUI);
				}		
			return false;
        case TASKMANAGE:        
				if(record->event.pressed){
					register_code(KC_LCTL);
					register_code(KC_LSFT);
					register_code(KC_ESC);
				} else {
					unregister_code(KC_ESC);
					unregister_code(KC_LSFT);
					unregister_code(KC_LCTL);
				}
			return false;
        case BAR380MM:        
				if(record->event.pressed){
					register_code(KC_LCTL); 
					tap_code_delay(KC_D, 186);
					tap_code_delay(KC_S, 182);
					tap_code_delay(KC_W, 178);
					tap_code_delay(KC_W, 188);
					tap_code_delay(KC_A, 184);
					tap_code_delay(KC_S, 189);
					tap_code_delay(KC_S, 181);
				} else {
					unregister_code(KC_LCTL);
				}
			return false;
		case CLIPB:        
				if(record->event.pressed){
					register_code(KC_LGUI);
					register_code(KC_V);
				} else {
					unregister_code(KC_V);
					unregister_code(KC_LGUI);
				}
			return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_SLEP, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_INS, KC_HOME, KC_END, 
		CLIPB, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_MUTE, KC_DEL, KC_PAUS, 
		KC_APP, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_PGUP, KC_MNXT, 
		TASKMANAGE, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN, KC_PGDN, KC_MPRV, 
		TABOUT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, 
		LT(1, KC_NO), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

	[_LEDSET] = LAYOUT(
		RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_REBOOT, 
		RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
    return false;
};

const rgblight_segment_t PROGMEM CAPSLOCK[] = RGBLIGHT_LAYER_SEGMENTS(
    {55, 1, HSV_WHITE}
);	
	
const rgblight_segment_t PROGMEM LEDSET[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_WHITE},
	{16, 4, HSV_WHITE},
	{53, 2, HSV_WHITE},
	{ 84, 2, HSV_WHITE}
);	

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    CAPSLOCK,  
    LEDSET
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
};

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LEDSET));

    return state;
};