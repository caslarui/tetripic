#include "../includes/tetripic.hpp"

void blue(bmp_pixelcolor &pixel) {
    pixel.B = 255;
    pixel.G = 0;
    pixel.R = 0;
}

void green(bmp_pixelcolor &pixel) {
    pixel.B = 0;
    pixel.G = 255;
    pixel.R = 0;
}

void red(bmp_pixelcolor &pixel) {
    pixel.B = 0;
    pixel.G = 0;
    pixel.R = 255;
}

void yellow(bmp_pixelcolor &pixel) {
    pixel.B = 0;
    pixel.G = 255;
    pixel.R = 255;
}

void orange(bmp_pixelcolor &pixel) {
    pixel.B = 0;
    pixel.G = 140;
    pixel.R = 255;
}

void pink(bmp_pixelcolor &pixel) {
    pixel.B = 255;
    pixel.G = 0;
    pixel.R = 255;
}

void purple(bmp_pixelcolor &pixel) {
    pixel.B = 255;
    pixel.G = 0;
    pixel.R = 130;
}

void black(bmp_pixelcolor &pixel) {
    pixel.B = 0;
    pixel.G = 0;
    pixel.R = 0;
}

void white(bmp_pixelcolor &pixel) {
    pixel.B = 255;
    pixel.G = 255; 
    pixel.R = 255;
}


void parse_color(bmp_pixelcolor &pixel, int8_t color_index) {
    switch(color_index) {
        case 0 : black(pixel); break;
        case 1 : white(pixel); break;
        case 2 : yellow(pixel); break;
        case 3 : blue(pixel); break;
        case 4 : red(pixel); break;
        case 5 : green(pixel); break;
        case 6 : orange(pixel); break;
        case 7 : pink(pixel); break;
        case 8 : purple(pixel); break;
    }
}

uint8_t color_index(bmp_pixelcolor pixel) {
    if (pixel.B == 0 && pixel.G == 0 && pixel.R == 0)
        return 0;
    if (pixel.B == 0 && pixel.G == 255 && pixel.R == 255)
        return 2;
    if (pixel.B == 255 && pixel.G == 0 && pixel.R == 0)
        return 3;
    if (pixel.B == 0 && pixel.G == 0 && pixel.R == 255)
        return 4;
    if (pixel.B == 0 && pixel.G == 255 && pixel.R == 0)
        return 5;
    if (pixel.B == 0 && pixel.G == 140 && pixel.R == 255)
        return 6;
    if (pixel.B == 255 && pixel.G == 0 && pixel.R == 255)
        return 7;
    if (pixel.B == 255 && pixel.G == 0 && pixel.R == 130)
        return 8;
    return 1;
}