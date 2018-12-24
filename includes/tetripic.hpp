#ifndef TETRIPIC_HPP
# define TETRIPIC_HPP

#include "bmp_file_info.hpp"

//MAIN STRUCT
typedef struct {
    bmp_fileheader BMP_HEADER;
    bmp_infoheader BMP_FILEINFO;
    bmp_pixelcolor **BMP_COLORS;
    char *filename;
}BMP_FILE;
/////////////////////////////////////////////////

typedef struct {
    int rows;
    int cols;
    int **piece;
    void (*color)(bmp_pixelcolor &pixel);
}tetrimon;


typedef struct {
    int **map;
    int height;
    int width;
}tetri_map;

//*************************************************************************

//COLOR_FUNCTIONS

void    blue(bmp_pixelcolor &pixel); // Coloram pixelul in albastru
void    green(bmp_pixelcolor &pixel); // Coloram pixelul in verde
void    red(bmp_pixelcolor &pixel); // Coloraram pixelul in rosu
void    yellow(bmp_pixelcolor &pixel); // Coloram pixelul in galben
void    orange(bmp_pixelcolor &pixel); // Coloram pixelul in portocaliu
void    pink(bmp_pixelcolor &pixel); // Coloram pixelul in roz
void    white(bmp_pixelcolor &pixel); // Coloram pixelul in alb
void    black(bmp_pixelcolor &pixel); // Coloram pixelul in negru
void    purple(bmp_pixelcolor &pixel); // Coloram pixelul in mov
void    parse_color(bmp_pixelcolor &pixel, int8_t color_index);
uint8_t color_index(bmp_pixelcolor pixel);

// Draw the picture
int     writeBMP(BMP_FILE file); // Initializeaza si creaza fisierul BMP
// Read the picture
int     readBMP(const char* filename, BMP_FILE &file);

//**************************************************************

// Memmory functions
int     allocMatrix(int** &matrix, int row, int col);
int     reallocMatrix(int** &matrix, int row, int col);
void    freeMatrix(int** &matrix, int row);
void    freeMatrix(char** &matrix, int row);

//*************************************************************

// Handle functions
void    rotate(tetrimon input, tetrimon &output,  int angle);
/*
    Functia de mai sus roteste figura de la input la unghiurile 
    0, 90, 180, 270, 360 de grade. In interiorul acesteia se aloca
    memorie pentru output care va contine figura deja rotita. 
    Figura rotita o returnam prin intermediul unei referinte. 
*/
void    copy_array(tetrimon src, int** &dest);
// Functia data returneaza o copie a figurei din sursa.
void    copy_array(tetri_map src, int** &dest);

int     read_input(const char* filename, char** &output);

void    init_piece(tetrimon &input, char piece_type);
//

void    print_bgr(bmp_pixelcolor pixel);
void    print_map(tetri_map game);
void    print_piece(tetrimon piece);

char    **ft_split(char *str);

int     count_lines(const char *filename);

void    parse_map(bmp_pixelcolor **pixel, tetri_map game);

//***********************************************************

//Task functions
void    draw_piece(unsigned int rot, const char piece_type[1]);
void    add_border(tetrimon &input);
int     solve_tetris(tetri_map &game, const char c, int rot,  int col);
void    draw_tetris(tetri_map game, const char *filename, int flag);


void    task1(void);
void    task2(void);
void    task3(const char *filename);
void    task4(const char *bmp_name, const char *input_name);

#endif // !TETRIPIC_HPP