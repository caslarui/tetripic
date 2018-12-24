#include "../includes/tetripic.hpp"

void rotate(tetrimon input, tetrimon &output,  int angle) {
    int i, j; 

    if(angle == 0 || angle == 360) {
        if(allocMatrix(output.piece, input.rows, input.cols)) {
            output.rows = input.rows;
            output.cols = input.cols;
            output.color = input.color;
            for(i = 0; i < input.rows; i++) {
                for(j = 0; j < input.cols; j++) {
                    output.piece[i][j] = input.piece[i][j];
                }
            }
        }
    }
    if(angle == 270) {
       if(allocMatrix(output.piece, input.cols, input.rows)) {
           output.rows = input.cols;
           output.cols = input.rows;
           output.color = input.color;
            for(i = 0; i < input.cols; i++) {
                for(j = 0; j < input.rows; j++) {
                    output.piece[i][j] = input.piece[j][input.cols - 1 - i];
                }
            }
       }
    }
    if(angle == 180) {
        if(allocMatrix(output.piece, input.rows, input.cols)) {
            output.rows = input.rows;
            output.cols = input.cols;
            output.color = input.color;
            for(i = 0; i < input.rows; i++) {
                for(j = 0; j < input.cols; j++) {
                    output.piece[i][j] = input.piece[input.rows - 1 - i] \
                                                    [input.cols - 1 - j];
                }
            }
        }
    }
    if(angle == 90) {
        if(allocMatrix(output.piece, input.cols, input.rows)) {
            output.rows = input.cols;
            output.cols = input.rows;
            output.color = input.color;
            for(i = 0; i < input.cols; i++) {
                for(j = 0; j < input.rows; j++) {
                    output.piece[i][j] = input.piece[input.rows - 1 - j][i];
                }
            }
        }
    }
}