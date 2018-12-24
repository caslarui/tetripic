#include "../includes/tetripic.hpp"

void delete_full_line(tetri_map &game, int row) {
    int i;
    int j;

    for ( i = row; i > 0; i--) {
        for (j = 0; j < game.width; j++)
            game.map[i][j] = game.map[i - 1][j];
    }
    for (j = 0; j < game.width; j++)
        game.map[0][j] = 0;
}

void check_full_lines(tetri_map &game) {
    int i;
    int j;

    for (i = 0; i < game.height; i++) {
        j = 0;
        while(j < game.width) {
            if(game.map[i][j] == 0 )
                break;
            j++;
        }
        if (j == game.width)
            delete_full_line(game, i); 
    }
}

void store_piece(int** &map, tetrimon piece, int row, int col) {
    int i1;
    int i2;
    int j1;
    int j2;

    for (i1 = row, i2 = 0; i1 < row + piece.rows; i1++, i2++) {
        for (j1 = col, j2 = 0; j1 < col + piece.cols; j1++, j2++) {
            if(piece.piece[i2][j2] != 0)
                map[i1][j1] = piece.piece[i2][j2];
        }
    }
}

int check_colision(int row, int col, tetrimon piece, tetri_map game) {
    int i1; // Pozitia orizontala fata de mapa
    int i2; // Pozitia orizontala fata de figura
    int j1; // Pozitia verticala fata de mapa 
    int j2; // Pozitia verticala fata de figura

    for (i1 = row, i2 = 0; i1 < row + piece.rows; i1++, i2++) {
        for (j1 = col, j2 = 0; j1 < col + piece.cols; j1++, j2++) {
            if ((i1 < 0) || (i1 > game.height - 1) || (j1 > game.width - 1)) {
                if (piece.piece[i2][j2] != 0) {
                    return 1;
                }
            }
            if (j1 >= 0) {
                if ((piece.piece[i2][j2] != 0) && (game.map[i1][j1] != 0)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void add_last_piece(tetri_map &game, tetrimon piece, int row, int col) {
    int **tmp;
    int i;
    int j;
    copy_array(game, tmp);

    freeMatrix(game.map, game.height);
    game.height += 4;
    allocMatrix(game.map, game.height, game.width);

    for(i = 0; i < 4; i++) {
        for(j = 0; j < game.width; j++)
            game.map[i][j] = 1;
    }
    for(i = 4; i < game.height; i++) {
        for (j = 0; j < game.width; j++)
            game.map[i][j] = tmp[i - 4][j];
    }
    store_piece(game.map, piece, row, col);
}

int solve_tetris(tetri_map &game, const char c, int rot,  int col) {
    tetrimon piece; // Piesa curenta din joc
    tetrimon piece_r; // Piesa dupa rotire
    int      j = 0;

    init_piece(piece,c);
    rotate(piece, piece_r, rot);
    freeMatrix(piece.piece, piece.rows);

    // cout << endl;
    // print_piece(piece_r);
    // cout << "Rows : " << piece_r.rows << " Cols : "<< piece_r.cols << endl << endl;


    while(1) {
        if (check_colision(j, col, piece_r, game) == 0) {
            j++;
        } else
        break;
    }
    if(j == 0) {
        add_last_piece(game, piece_r, j, col);
        return(1);
    }
    store_piece(game.map, piece_r, j - 1, col);
    check_full_lines(game);
    return(0);
}