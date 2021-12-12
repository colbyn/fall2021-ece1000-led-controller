#ifdef DESKTOP_DEBUG_MODE

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define byte uint8_t

#include "desktop/binary.h"
#include "deps.h"

void print_history() {
    for (int i = 0; i < 80; i++) {
        printf("%d ", history[i]);
    }
    printf("\n");
}


// static byte set_bit(byte bitstr, int index, int new_value) {
//     return bitstr ^= (-new_value ^ bitstr) & (1UL << index);
// }


int main() {
    printf("RUNNING:\n");
    // print_history();
    // tick_history(0);
    // print_history();

    // byte top_character[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
    // byte bottom_character[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};

    // get_character(14, top_character, bottom_character);

    // print_5_bits(top_character[0]);
    // print_5_bits(top_character[1]);
    // print_5_bits(top_character[2]);
    // print_5_bits(top_character[3]);
    // print_5_bits(top_character[4]);
    // print_5_bits(top_character[5]);
    // print_5_bits(top_character[6]);
    // print_5_bits(top_character[7]);

    // printf("\nRESULKT: %hhu\n", top_character[0]);
    // printf("%hhx", top_character[0]);

    byte top_character[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
    byte bottom_character[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};

    get_character(0, top_character, bottom_character);

    print_5_bits(top_character[0]);
    print_5_bits(top_character[1]);
    print_5_bits(top_character[2]);
    print_5_bits(top_character[3]);
    print_5_bits(top_character[4]);
    print_5_bits(top_character[5]);
    print_5_bits(top_character[6]);
    print_5_bits(top_character[7]);


    // for (uint8_t i = 0; i < 16; i++) {
    //     printf("%hhu\n", (uint8_t)(i));
    //     printf("%hhu\n", (uint8_t)(255 - i));
    // }

    // int state = 0;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);
    // state = (state + 1) % 4;
    // printf("%d\n", state);

    int a = -2;
    int b = 8;

    // printf("%d\n", modulo_euclidean(a, b));

    printf("\n");
    return 0;
}

#endif /* DESKTOP_DEBUG_MODE */
