
#include "cpu_types.h"



#define ASCII_3x5_SIZE 36


int ASCII_to_index_3x5
(
    int ASCII_CODE
);

uint8_t * ascii_3x5_get_alpha
(
    void
);

uint8_t * ascii_3x5_get_alpha_border
(
    void
);

uint8_t * ascii_3x5_with_border
(
    int ascii_3x5_index
);