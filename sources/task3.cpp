#include "../includes/tetripic.hpp"


void draw_tetris(tetri_map game, const char *filename, int flag) {
    BMP_FILE file;
    int white_part_height;
    int i;
    int j;
    int k = 0;

    white_part_height = 40;

    file.filename = strdup(filename);
    file.BMP_FILEINFO.width = game.width * 10;
    file.BMP_FILEINFO.height = game.height * 10 + white_part_height;

    // cout << file.BMP_FILEINFO.height <<endl;

    file.BMP_COLORS = new bmp_pixelcolor *[file.BMP_FILEINFO.height];
    for(i = 0; i < file.BMP_FILEINFO.height; i++)
        file.BMP_COLORS[i] = new bmp_pixelcolor[file.BMP_FILEINFO.width];

    k = file.BMP_FILEINFO.height - 1;
    for (i = 0; i < white_part_height; i++) {
        for (j = 0; j < file.BMP_FILEINFO.width; j++)
            white(file.BMP_COLORS[k][j]);
        k--;
    }

    for ( i = white_part_height;  i < file.BMP_FILEINFO.height; i++) {
        for (j = 0; j < file.BMP_FILEINFO.width; j++)
            parse_color(file.BMP_COLORS[k][j], game.map[(i - white_part_height) / 10][j / 10]);
        k--;
    }
    writeBMP(file);
    freeMatrix(game.map, game.height);
}

void task3(const char *filename) {
    char    **input; // Contine fisierul citit de la input
    char    **params; // Contine cuvintele dintr-o linie oarecare din tabelul input
    char    name;  // Numele piesei
    tetri_map game; // Harta de tetris
    int     i;
    int     moves_nbr = 0; // Nr de miscari de piese
    int     rot = 0; // Rotatia necesara piesei;
    int     col = 0; // Coloana pe care trebuie sa pozitionam piesa; 

    read_input(filename, input);
 
    params = ft_split(input[0]); //Impartim in cuvinte randul
    game.height = atoi(params[1]);
    game.width = atoi(params[2]);
    moves_nbr = atoi(params[0]);
    
    freeMatrix(params, 3);

    allocMatrix(game.map, game.height, game.width);

    // cout << "Map Height : " << game.height << endl << "Map Width : " << game.width << endl << "Nr de miscari : " \
            << moves_nbr << endl;

    // print_map(game);

    for(i = 0; i < moves_nbr; i++) {
        params = ft_split(input[i + 1]);
        name = params[0][0];
        rot = atoi(params[1]);
        col = atoi(params[2]);
        // cout << "Name : " << name << " Rot : " << rot << " Col : " << col << endl;
        if(solve_tetris(game, name, rot, col))
            break;
    }
    // cout << "AICI\n";
    draw_tetris(game, "task3.bmp", 0);
}

