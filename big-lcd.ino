#include <math.h>

#include <LiquidCrystal.h>
#include "deps.h"


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char frame[] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', '0', '0', '0', '0',
};


#define RAD2DEG M_PI/360.0*2.0
#define DEG2RAD 360.0/M_PI/2.0


void setup() {
    lcd.begin(16, 2);
}

static void customclear()  {
    // ensures all custom character slots are clear before new custom
    // characters can be defined. 
    byte blank[8] = {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000};
    for(int i = 0; i < 8; i++) {
        lcd.createChar(i, blank);
    }
}

// int RENDER_TOGGLE = 0;
static int RENDER_STATE = 0;
// #define RENDER_TOP_START (RENDER_STATE == 0)
// #define RENDER_TOP_END (RENDER_STATE == 1)
// #define RENDER_BOT_START (RENDER_STATE == 2)
// #define RENDER_BOT_END (RENDER_STATE == 3)


static void run_top_left() {
    lcd.createChar(byte(0), top_character_01);
    lcd.createChar(byte(1), top_character_02);
    lcd.createChar(byte(2), top_character_03);
    lcd.createChar(byte(3), top_character_04);
    lcd.createChar(byte(4), top_character_05);
    lcd.createChar(byte(5), top_character_06);
    lcd.createChar(byte(6), top_character_07);
    lcd.createChar(byte(7), top_character_08);
    
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.write(byte(6));
    lcd.write(byte(7));
}

static void run_top_right() {
    lcd.createChar(byte(0), top_character_09);
    lcd.createChar(byte(1), top_character_10);
    lcd.createChar(byte(2), top_character_11);
    lcd.createChar(byte(3), top_character_12);
    lcd.createChar(byte(4), top_character_13);
    lcd.createChar(byte(5), top_character_14);
    lcd.createChar(byte(6), top_character_15);
    lcd.createChar(byte(7), top_character_16);
    
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.write(byte(6));
    lcd.write(byte(7));
}

static void run_bot_left() {
    lcd.createChar(byte(0), bot_character_01);
    lcd.createChar(byte(1), bot_character_02);
    lcd.createChar(byte(2), bot_character_03);
    lcd.createChar(byte(3), bot_character_04);
    lcd.createChar(byte(4), bot_character_05);
    lcd.createChar(byte(5), bot_character_06);
    lcd.createChar(byte(6), bot_character_07);
    lcd.createChar(byte(7), bot_character_08);
    
    lcd.setCursor(0, 1);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.write(byte(6));
    lcd.write(byte(7));
}

static void run_bot_right() {
    lcd.createChar(byte(0), bot_character_09);
    lcd.createChar(byte(1), bot_character_10);
    lcd.createChar(byte(2), bot_character_11);
    lcd.createChar(byte(3), bot_character_12);
    lcd.createChar(byte(4), bot_character_13);
    lcd.createChar(byte(5), bot_character_14);
    lcd.createChar(byte(6), bot_character_15);
    lcd.createChar(byte(7), bot_character_16);
    
    lcd.setCursor(8, 1);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.write(byte(5));
    lcd.write(byte(6));
    lcd.write(byte(7));
}

static void finalize() {
    delay(40);
    lcd.clear();
    update_char_buffers();
}

void loop() {
    if (RENDER_STATE == 0) {
        RENDER_STATE = 1;
        run_top_left();
        finalize();
        return;
    }
    if (RENDER_STATE == 1) {
        RENDER_STATE = 2;
        run_top_right();
        finalize();
        return;
    }
    if (RENDER_STATE == 2) {
        RENDER_STATE = 3;
        run_bot_left();
        finalize();
        return;
    }
    if (RENDER_STATE == 3) {
        RENDER_STATE = 4;
        run_bot_right();
        finalize();
        return;
    }
    if (RENDER_STATE == 4) {
        RENDER_STATE = 0;
        // delay(1000);
        return;
    }
}
