
#ifndef MAX7219_SYMBOLS_H_
#define MAX7219_SYMBOLS_H_

// macros of special character codes
#define MAX7219_CHAR_EMPTY        0b00000000
#define MAX7219_CHAR_SPACE        0b00000000
#define MAX7219_CHAR_POINT        0b10000000
#define MAX7219_CHAR_MINUS        0b00000001
#define MAX7219_CHAR_DASH         0b00000001
#define MAX7219_CHAR_DEGREE       0b01100011
#define MAX7219_CHAR_OVERLINE     0b01000000
#define MAX7219_CHAR_UNDERSCORE   0b00001000

// macros of digit codes
#define MAX7219_CHAR_DIGIT_0      0b01111110
#define MAX7219_CHAR_DIGIT_1      0b00110000
#define MAX7219_CHAR_DIGIT_2      0b01101101
#define MAX7219_CHAR_DIGIT_3      0b01111001
#define MAX7219_CHAR_DIGIT_4      0b00110011
#define MAX7219_CHAR_DIGIT_5      0b01011011
#define MAX7219_CHAR_DIGIT_6      0b01011111
#define MAX7219_CHAR_DIGIT_7      0b01110000
#define MAX7219_CHAR_DIGIT_8      0b01111111
#define MAX7219_CHAR_DIGIT_9      0b01111011

// macros of codes of some Latin letters
#define MAX7219_CHAR_A_BIG        0b01110111
#define MAX7219_CHAR_B_SMALL      0b00011111
#define MAX7219_CHAR_C_BIG        0b01001110
#define MAX7219_CHAR_C_SMALL      0b00001101
#define MAX7219_CHAR_D_SMALL      0b00111101
#define MAX7219_CHAR_E_BIG        0b01001111
#define MAX7219_CHAR_F_BIG        0b01000111
#define MAX7219_CHAR_G_BIG        0b01011111
#define MAX7219_CHAR_G_SMALL      0b01111011
#define MAX7219_CHAR_H_BIG        0b00110111
#define MAX7219_CHAR_H_SMALL      0b00010111
#define MAX7219_CHAR_I_BIG        0b00110000
#define MAX7219_CHAR_I_SMALL      0b00010000
#define MAX7219_CHAR_J_BIG        0b00111000
#define MAX7219_CHAR_J_SMALL      0b00011000
#define MAX7219_CHAR_L_BIG        0b00001110
#define MAX7219_CHAR_L_SMALL      0b00000110
#define MAX7219_CHAR_N_SMALL      0b00010101
#define MAX7219_CHAR_O_BIG        0b01111110
#define MAX7219_CHAR_O_SMALL      0b00011101
#define MAX7219_CHAR_P_BIG        0b01100111
#define MAX7219_CHAR_Q_SMALL      0b01110011
#define MAX7219_CHAR_R_SMALL      0b00000101
#define MAX7219_CHAR_S_BIG        0b01011011
#define MAX7219_CHAR_T_SMALL      0b00001111
#define MAX7219_CHAR_U_BIG        0b00111110
#define MAX7219_CHAR_V_SMALL      0b00011100
#define MAX7219_CHAR_Y_SMALL      0b00111011
#define MAX7219_CHAR_Z_BIG        0b01001001

// macro for setting a dot in a character
#define MAX7219_CHAR_SIGN_WITH_POINT(MAX7219_CHAR)    (MAX7219_CHAR | 0b10000000)

// macro for resetting a dot in a character
#define MAX7219_CHAR_SIGN_WITHOUT_POINT(MAX7219_CHAR) (MAX7219_CHAR & 0b01111111)

#endif
