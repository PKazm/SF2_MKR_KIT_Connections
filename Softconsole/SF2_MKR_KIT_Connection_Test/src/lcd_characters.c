#include "lcd_characters.h"


const uint8_t spacer[] = {0b10000000};
const uint8_t spacer_mask[] = {0b01111111};

const uint8_t ascii_3x5_alpha[] = {0b00011111, 0b00011111, 0b00011111};
const uint8_t ascii_3x5_alpha_border[] = {0b01111111, 0b01111111, 0b01111111, 0b01111111, 0b01111111};
const uint8_t ascii_3x5_0[] = {0b00011111, 0b00010001, 0b00011111};
const uint8_t ascii_3x5_1[] = {0b00000000, 0b00000010, 0b00011111};
const uint8_t ascii_3x5_2[] = {0b00011001, 0b00010101, 0b00010010};
const uint8_t ascii_3x5_3[] = {0b00010101, 0b00010101, 0b00011111};
const uint8_t ascii_3x5_4[] = {0b00000111, 0b00000100, 0b00011111};
const uint8_t ascii_3x5_5[] = {0b00010111, 0b00010101, 0b00011101};
const uint8_t ascii_3x5_6[] = {0b00011111, 0b00010101, 0b00011101};
const uint8_t ascii_3x5_7[] = {0b00000001, 0b00011101, 0b00000011};
const uint8_t ascii_3x5_8[] = {0b00011111, 0b00010101, 0b00011111};
const uint8_t ascii_3x5_9[] = {0b00000111, 0b00000101, 0b00011111};
const uint8_t ascii_3x5_a[] = {0b00011110, 0b00000101, 0b00011110};
const uint8_t ascii_3x5_b[] = {0b00011111, 0b00010101, 0b00001010};
const uint8_t ascii_3x5_c[] = {0b00001110, 0b00010001, 0b00010001};
const uint8_t ascii_3x5_d[] = {0b00011111, 0b00010001, 0b00001110};
const uint8_t ascii_3x5_e[] = {0b00011111, 0b00010101, 0b00010101};
const uint8_t ascii_3x5_f[] = {0b00011111, 0b00000101, 0b00000101};
const uint8_t ascii_3x5_g[] = {0b00011111, 0b00000101, 0b00000101};
const uint8_t ascii_3x5_h[] = {0b00011111, 0b00000100, 0b00011111};
const uint8_t ascii_3x5_i[] = {0b00010001, 0b00011111, 0b00010001};
const uint8_t ascii_3x5_j[] = {0b00010001, 0b00011111, 0b00000001};
const uint8_t ascii_3x5_k[] = {0b00011111, 0b00000100, 0b00011011};
const uint8_t ascii_3x5_l[] = {0b00010000, 0b00010000, 0b00011111};
const uint8_t ascii_3x5_m[] = {0b00011111, 0b00000010, 0b00011111};
const uint8_t ascii_3x5_n[] = {0b00011111, 0b00000001, 0b00011110};
const uint8_t ascii_3x5_o[] = {0b00001110, 0b00010001, 0b00001110};
const uint8_t ascii_3x5_p[] = {0b00011111, 0b00000101, 0b00000010};
const uint8_t ascii_3x5_q[] = {0b00001110, 0b00011001, 0b00011110};
const uint8_t ascii_3x5_r[] = {0b00011111, 0b00000101, 0b00011010};
const uint8_t ascii_3x5_s[] = {0b00010010, 0b00010101, 0b00001001};
const uint8_t ascii_3x5_t[] = {0b00000001, 0b00011111, 0b00000001};
const uint8_t ascii_3x5_u[] = {0b00011111, 0b00010000, 0b00011111};
const uint8_t ascii_3x5_v[] = {0b00001111, 0b00010000, 0b00001111};
const uint8_t ascii_3x5_w[] = {0b00011111, 0b00001000, 0b00011111};
const uint8_t ascii_3x5_x[] = {0b00011011, 0b00000100, 0b00011011};
const uint8_t ascii_3x5_y[] = {0b00000111, 0b00011100, 0b00000111};
const uint8_t ascii_3x5_z[] = {0b00011001, 0b00010101, 0b00010011};

const uint8_t * ascii_3x5[] = {   ascii_3x5_0,
                            ascii_3x5_1,
                            ascii_3x5_2,
                            ascii_3x5_3,
                            ascii_3x5_4,
                            ascii_3x5_5,
                            ascii_3x5_6,
                            ascii_3x5_7,
                            ascii_3x5_8,
                            ascii_3x5_9,
                            ascii_3x5_a,
                            ascii_3x5_b,
                            ascii_3x5_c,
                            ascii_3x5_d,
                            ascii_3x5_e,
                            ascii_3x5_f,
                            ascii_3x5_g,
                            ascii_3x5_h,
                            ascii_3x5_i,
                            ascii_3x5_j,
                            ascii_3x5_k,
                            ascii_3x5_l,
                            ascii_3x5_m,
                            ascii_3x5_n,
                            ascii_3x5_o,
                            ascii_3x5_p,
                            ascii_3x5_q,
                            ascii_3x5_r,
                            ascii_3x5_s,
                            ascii_3x5_t,
                            ascii_3x5_u,
                            ascii_3x5_v,
                            ascii_3x5_w,
                            ascii_3x5_x,
                            ascii_3x5_y,
                            ascii_3x5_z};


int ASCII_to_index_3x5
(
    int ASCII_CODE
)
{
    if(ASCII_CODE >= 48 && ASCII_CODE <= 57){
        return ASCII_CODE - 48;
    }
    else if(ASCII_CODE >= 65 && ASCII_CODE <= 90){
        return ASCII_CODE - 55;
    }
    else if(ASCII_CODE >= 97 && ASCII_CODE <= 122){
        return ASCII_CODE - 87;
    }
    else{
        return -1;
    }
}

uint8_t * ascii_3x5_get_alpha
(
    void
)
{
    return ascii_3x5_alpha;
}

uint8_t * ascii_3x5_get_alpha_border
(
    void
)
{
    return ascii_3x5_alpha_border;
}

uint8_t * ascii_3x5_with_border
(
    int ascii_3x5_index
)
{
    static uint8_t border_char[] = {   0b00000000,
                                0b00000000,
                                0b00000000,
                                0b00000000,
                                0b00000000};
    for(int i = 0; i < 3; i++){
        border_char[i+1] = ascii_3x5[ascii_3x5_index][i] << 1;
    }
    return border_char;
}
