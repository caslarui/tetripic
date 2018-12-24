#include "../includes/tetripic.hpp"

void task1(void) {
    const char pieces[7][2] = { "O", "I", "S", "Z",
                                  "L", "J", "T" };
    int i;

    for (i = 0; i < 7; i++) {
        draw_piece(0,pieces[i]);
    }
}

void task2(void) {
    const char  pieces[7][2]{ "O", "I", "S", "Z",
                                "L", "J", "T" };
    int         angles[3]{90,180,270};
    int         i,j;

    for (j = 0; j < 7; j++) {
        for (i = 0; i < 3; i++) {
            draw_piece(angles[i],pieces[j]);            
        }
    }
}