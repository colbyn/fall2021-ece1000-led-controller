#ifdef DESKTOP_DEBUG_MODE
#include <stdio.h>
#include <assert.h>
#endif /* MACRO */

#define GET_BIT(bitstr,index) ((bitstr >> index) & 1)
#define SET_BIT(bitstr,index,new_value) (bitstr ^= (-new_value ^ bitstr) & (1UL << index))

int modulo_euclidean(int a, int b) {
    int m = a % b;
    if (m < 0) {
        // m += (b < 0) ? -b : b; // avoid this form: it is UB when b == INT_MIN
        m = (b < 0) ? m - b : m + b;
    }
    return m;
}

#ifdef DESKTOP_DEBUG_MODE
void print_5_bits(byte state) {
    printf(
        "RESULT: %d %d %d %d %d\n",
        GET_BIT(state, 4),
        GET_BIT(state, 3),
        GET_BIT(state, 2),
        GET_BIT(state, 1),
        GET_BIT(state, 0)
    );
}
#endif /* MACRO */

int history[80] = {
    0,-1,-2,-3,-4,-5,-6,-7,-8,-7,-6,-5,-4,-3,-2,-1,
    0,1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,1,2,3,4,4,3,2,1,0,0,0,1,1,0,
};

byte top_character_01[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_02[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_03[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_04[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_05[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_06[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_08[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_09[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_10[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_11[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_12[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_13[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_14[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_15[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte top_character_16[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};

byte bot_character_01[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_02[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_03[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_04[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_05[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_06[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_07[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_08[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_09[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_10[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_11[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_12[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_13[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_14[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_15[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
byte bot_character_16[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};


static void update_history_at_index(byte top_character[8], byte bot_character[8], int _start) {
    int start = start;
    int end = start + 5;
    for (int i = start; i < end; i++) {
        // SET_BIT(bot_character[7], i, 1);
        switch (history[0])
        {
        case 8:
            top_character[0] = SET_BIT(top_character[0], i, 1);
            break;
        case 7:
            top_character[1] = SET_BIT(top_character[1], i, 1);
            break;
        case 6:
            top_character[2] = SET_BIT(top_character[2], i, 1);
            break;
        case 5:
            top_character[3] = SET_BIT(top_character[3], i, 1);
            break;
        case 4:
            top_character[4] = SET_BIT(top_character[4], i, 1);
            break;
        case 3:
            top_character[5] = SET_BIT(top_character[5], i, 1);
            break;
        case 2:
            top_character[6] = SET_BIT(top_character[6], i, 1);
            break;
        case 1:
            top_character[7] = SET_BIT(top_character[7], i, 1);
            break;
        case 0:
            top_character[7] = SET_BIT(top_character[7], i, 1);
            bot_character[0] = SET_BIT(bot_character[0], i, 1);
            break;
        case -1:
            bot_character[0] = SET_BIT(bot_character[0], i, 1);
            break;
        case -2:
            bot_character[1] = SET_BIT(bot_character[1], i, 1);
            break;
        case -3:
            bot_character[2] = SET_BIT(bot_character[2], i, 1);
            break;
        case -4:
            bot_character[3] = SET_BIT(bot_character[3], i, 1);
            break;
        case -5:
            bot_character[4] = SET_BIT(bot_character[4], i, 1);
            break;
        case -6:
            bot_character[5] = SET_BIT(bot_character[5], i, 1);
            break;
        case -7:
            bot_character[6] = SET_BIT(bot_character[6], i, 1);
            break;
        case -8:
            bot_character[7] = SET_BIT(bot_character[7], i, 1);
            break;
        }
    }
}

void update_char_buffers() {
    update_history_at_index(top_character_01, bot_character_01, 5 * 0);
    update_history_at_index(top_character_02, bot_character_02, 5 * 1);
    update_history_at_index(top_character_03, bot_character_03, 5 * 2);
    update_history_at_index(top_character_04, bot_character_04, 5 * 3);
    update_history_at_index(top_character_05, bot_character_05, 5 * 4);
    update_history_at_index(top_character_06, bot_character_06, 5 * 5);
    update_history_at_index(top_character_07, bot_character_07, 5 * 6);
    update_history_at_index(top_character_08, bot_character_08, 5 * 7);
    update_history_at_index(top_character_09, bot_character_09, 5 * 8);
    update_history_at_index(top_character_10, bot_character_10, 5 * 9);
    update_history_at_index(top_character_11, bot_character_11, 5 * 10);
    update_history_at_index(top_character_12, bot_character_12, 5 * 11);
    update_history_at_index(top_character_13, bot_character_13, 5 * 12);
    update_history_at_index(top_character_14, bot_character_14, 5 * 13);
    update_history_at_index(top_character_15, bot_character_15, 5 * 14);
    update_history_at_index(top_character_16, bot_character_16, 5 * 15);
}

void tick_history(int new_value) {
    int starting_value = history[0];
    for (int i = 0; i < 80; i++) {
        if (i == 80 - 1) {
            history[i] = new_value;
            continue;
        }
        history[i] = history[i + 1];
    }
}





// void tick_characters() {
//     if history[0] == 
// }


