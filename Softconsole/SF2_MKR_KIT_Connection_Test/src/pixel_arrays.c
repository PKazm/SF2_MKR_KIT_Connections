/*
 * pixel_arrays.c
 *
 *  Created on: Mar 29, 2020
 *      Author: Phoenix136
 */

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif


unsigned int * pix_ar_create
(
    unsigned int num_pixels
)
{
    return calloc(num_pixels, sizeof(int));
}

void pix_ar_destroy
(
    unsigned int * pixel_array
)
{
    free(pixel_array);
}

void pix_ar_set_pix
(
    unsigned int * pixel_array,
    unsigned int pix_pos,
    unsigned int pix_val
)
{
    //unsigned int pixel_mask;
    unsigned int array_sub_int;
    unsigned int sub_pos;
    array_sub_int = pix_pos / (sizeof(unsigned int) * 8);
    sub_pos = (pix_pos % (sizeof(unsigned int) * 8));
    //pixel_mask = 1u << sub_pos;

    pixel_array[array_sub_int] &= ~(1u << sub_pos);
    pixel_array[array_sub_int] |= pix_val << sub_pos;
}

void pix_ar_set_pix_char
(
    unsigned int * pixel_array,
    unsigned int pix_pos,
    unsigned char pix_val
)
{
    unsigned int pixel_mask;
    unsigned int array_sub_int;
    array_sub_int = pix_pos / (sizeof(unsigned int) * 8);
    pixel_mask = pix_val << (pix_pos % (sizeof(unsigned int) * 8));
}



#ifdef __cplusplus
}
#endif
