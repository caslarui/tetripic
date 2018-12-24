#include "../includes/tetripic.hpp"

void copy_array(tetrimon src, int** &dest) {
    int i, j;

    allocMatrix(dest, src.rows, src.cols);
    
    for (i = 0; i < src.rows; i++)
        for (j = 0; j < src.cols; j++)
            dest[i][j] = src.piece[i][j];
}

void copy_array(tetri_map src, int** &dest) {
    int i, j;

    allocMatrix(dest, src.height, src.width);
    
    for (i = 0; i < src.height; i++)
        for (j = 0; j < src.width; j++)
            dest[i][j] = src.map[i][j];
}

void init_s_piece(int** &piece) {
    piece[0][0] = 0;
    piece[0][1] = 4;
    piece[0][2] = 4;
    piece[1][0] = 4;
    piece[1][1] = 4;
    piece[1][2] = 0;
}

void init_o_piece(int** &piece) {
    piece[0][0] = 2;
    piece[0][1] = 2;
    piece[1][0] = 2;
    piece[1][1] = 2;
}

void init_i_piece(int** &piece) {
    piece[0][0] = 3;
    piece[1][0] = 3;
    piece[2][0] = 3;
    piece[3][0] = 3;
}

void init_z_piece(int** &piece) {
    piece[0][0] = 5;
    piece[0][1] = 5;
    piece[0][2] = 0;
    piece[1][0] = 0;
    piece[1][1] = 5;
    piece[1][2] = 5;
}

void init_l_piece(int** &piece) {
    piece[0][0] = 6;
    piece[1][0] = 6;
    piece[2][0] = 6;
    piece[0][1] = 0;
    piece[1][1] = 0;
    piece[2][1] = 6;
}

void init_j_piece(int** &piece) {
    piece[0][1] = 7;
    piece[1][1] = 7;
    piece[2][1] = 7;
    piece[0][0] = 0;
    piece[1][0] = 0;
    piece[2][0] = 7;
}

void init_t_piece(int** &piece) {
    piece[0][0] = 8;
    piece[0][1] = 8;
    piece[0][2] = 8;
    piece[1][0] = 0;
    piece[1][1] = 8;
    piece[1][2] = 0;
}

void init_piece(tetrimon &input, char piece_type) {

    switch(piece_type) {
       case 'O' : 
            input.rows = 2;
            input.cols = 2;
            input.color = &yellow;
            allocMatrix(input.piece, input.rows, input.cols);
            init_o_piece(input.piece);
            break;
        case 'I' :
            input.rows = 4;
            input.cols = 1;
            input.color = &blue;
            allocMatrix(input.piece, input.rows, input.cols);
            init_i_piece(input.piece);
            break;
        case 'S' :
            input.rows = 2;
            input.cols = 3;
            input.color = &red;
            allocMatrix(input.piece, input.rows, input.cols);
            init_s_piece(input.piece);
            break;
        case 'Z' :
            input.rows = 2;
            input.cols = 3;
            input.color = &green;
            allocMatrix(input.piece, input.rows, input.cols);
            init_z_piece(input.piece);
            break;
        case 'L' :
            input.rows = 3;
            input.cols = 2;
            input.color = &orange;
            allocMatrix(input.piece, input.rows, input.cols);
            init_l_piece(input.piece);
            break;
        case 'J' :
            input.rows = 3;
            input.cols = 2;
            input.color = &pink;
            allocMatrix(input.piece, input.rows, input.cols);
            init_j_piece(input.piece);
            break;
        case 'T' :
            input.rows = 2;
            input.cols = 3;
            input.color = &purple;
            allocMatrix(input.piece, input.rows, input.cols);
            init_t_piece(input.piece);
            break;
    }
}
