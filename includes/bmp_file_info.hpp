#ifndef BMP_FILEINFO_HPP
# define BMP_FILEINFO_HPP

#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#pragma pack(1)

typedef struct {
    uint16_t        filetype{0x4D42}; /* 'BM' */
    uint32_t        bfSize{0}; /* File's size */
    uint16_t        unused1{0};
    uint16_t        unused2{0};
    uint32_t        imageDataOffset; /* Offset to the start of image data */
}bmp_fileheader; //14bytes

typedef struct {
    uint32_t        biSize{40}; /* Size of the info header - 40 bytes */
    int32_t         width{0}; /* Width of the image */
    int32_t         height{0}; /* Height of the image */

    uint16_t        planes{1};
    uint16_t        bitPix{24};
    uint32_t        biCompression{0};
    uint32_t        biSizeImage{0}; /* Size of the image data */
    int32_t         biXPelsPerMeter{0};
    int32_t         biYPelsPerMeter{0};
    uint32_t        biClrUsed{0};
    uint32_t        biClrImportant{0};
}bmp_infoheader; //40bytes

#pragma pack()

typedef struct {
    uint8_t         B;
    uint8_t         G;
    uint8_t         R;
}bmp_pixelcolor;

#endif