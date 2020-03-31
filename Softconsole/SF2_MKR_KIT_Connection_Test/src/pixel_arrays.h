/*
 * pixel_arrays.h
 *
 *  Created on: Mar 29, 2020
 *      Author: Phoenix136
 */

#ifndef SRC_PIXEL_ARRAYS_H_
#define SRC_PIXEL_ARRAYS_H_

#ifdef __cplusplus
extern "C" {
#endif

unsigned int * pix_ar_create
(
    unsigned int num_pixels
);

void pix_ar_destroy
(
    unsigned int * pixel_array
);


void pix_ar_set_pix
(
    unsigned int * pixel_array,
    unsigned int pix_pos,
    unsigned int pix_val
);

void pix_ar_set_pix_byte
(
    unsigned int * pixel_array,
    unsigned int pix_pos,
    unsigned char pix_val
);



#ifdef __cplusplus
}
#endif

#endif /* SRC_PIXEL_ARRAYS_H_ */
