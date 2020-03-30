
#include "cpu_types.h"

const int ascii_3x5_size = 36;


uint8_t spacer[] = {0b10000000};
uint8_t spacer_mask[] = {0b01111111};

uint8_t ascii_3x5_alpha[] = {0b01111111, 0b01111111, 0b01111111};
uint8_t ascii_3x5_0[] = {0b00111110, 0b00100010, 0b00111110};
uint8_t ascii_3x5_1[] = {0b00000000, 0b00000100, 0b00111110};
uint8_t ascii_3x5_2[] = {0b00110010, 0b00101010, 0b00100100};
uint8_t ascii_3x5_3[] = {0b00101010, 0b00101010, 0b00111110};
uint8_t ascii_3x5_4[] = {0b00001110, 0b00001000, 0b00111110};
uint8_t ascii_3x5_5[] = {0b00101110, 0b00101010, 0b00111010};
uint8_t ascii_3x5_6[] = {0b00111110, 0b00101010, 0b00111010};
uint8_t ascii_3x5_7[] = {0b00000010, 0b00111010, 0b00000110};
uint8_t ascii_3x5_8[] = {0b00111110, 0b00101010, 0b00111110};
uint8_t ascii_3x5_9[] = {0b00001110, 0b00001010, 0b00111110};
uint8_t ascii_3x5_a[] = {0b00111100, 0b00001010, 0b00111100};
uint8_t ascii_3x5_b[] = {0b00111110, 0b00101010, 0b00010100};
uint8_t ascii_3x5_c[] = {0b00011100, 0b00100010, 0b00100010};
uint8_t ascii_3x5_d[] = {0b00111110, 0b00100010, 0b00011100};
uint8_t ascii_3x5_e[] = {0b00111110, 0b00101010, 0b00101010};
uint8_t ascii_3x5_f[] = {0b00111110, 0b00001010, 0b00001010};
uint8_t ascii_3x5_g[] = {0b00111110, 0b00001010, 0b00001010};
uint8_t ascii_3x5_h[] = {0b00111110, 0b00001000, 0b00111110};
uint8_t ascii_3x5_i[] = {0b00100010, 0b00111110, 0b00100010};
uint8_t ascii_3x5_j[] = {0b00100010, 0b00111110, 0b00000010};
uint8_t ascii_3x5_k[] = {0b00111110, 0b00001000, 0b00110110};
uint8_t ascii_3x5_l[] = {0b00100000, 0b00100000, 0b00111110};
uint8_t ascii_3x5_m[] = {0b00111110, 0b00000100, 0b00111110};
uint8_t ascii_3x5_n[] = {0b00111110, 0b00000010, 0b00111100};
uint8_t ascii_3x5_o[] = {0b00011100, 0b00100010, 0b00011100};
uint8_t ascii_3x5_p[] = {0b00111110, 0b00001010, 0b00000100};
uint8_t ascii_3x5_q[] = {0b00011100, 0b00110010, 0b00111100};
uint8_t ascii_3x5_r[] = {0b00111110, 0b00001010, 0b00110100};
uint8_t ascii_3x5_s[] = {0b00100100, 0b00101010, 0b00010010};
uint8_t ascii_3x5_t[] = {0b00000010, 0b00111110, 0b00000010};
uint8_t ascii_3x5_u[] = {0b00111110, 0b00100000, 0b00111110};
uint8_t ascii_3x5_v[] = {0b00011110, 0b00100000, 0b00011110};
uint8_t ascii_3x5_w[] = {0b00111110, 0b00010000, 0b00111110};
uint8_t ascii_3x5_x[] = {0b00110110, 0b00001000, 0b00110110};
uint8_t ascii_3x5_y[] = {0b00001110, 0b00111000, 0b00001110};
uint8_t ascii_3x5_z[] = {0b00110010, 0b00101010, 0b00100110};

uint8_t * ascii_3x5[] = {   ascii_3x5_0,
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
);