#include "../inc/header.h"

void reading_data(char *str, int *dot, int *row, int *col) {
    int sym = 0;
    int sym_2 = 0;
    int col_temp = 0;


    for (int i = 0; i < mx_strlen(str); i++) {
        if(str[i] == '.')
            *dot = *dot + 1;
        if (str[i] == ',')
            col_temp++;
        if (str[i] != '\n')
            sym++;
        if (str[i] == '\n') {
            if (sym_2 != 0 && sym_2 != sym) {
                mx_printerr("map error\n");
                exit(-1);
            }
            *row = *row+1;
            sym_2 = sym;
            sym = 0;
            *col = col_temp;
            col_temp = 0;
        }
    }

    if (str[mx_strlen(str) - 1] != '\n') {
        *row = *row+1;
    }
    *col = *col+1;
}


void input_symb_arr(int row, int col, char *str, char sym_arr[row][col]) {
    int it = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (str[it] == '\n' || str[it] ==',') {
                it++;
                
            }
            sym_arr[i][j] = str[it];
            it++;
        }
    }
}

void input_num_arr(int row, int col, char sym_arr[row][col], int num_arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (sym_arr[i][j] == '#') {
                num_arr[i][j] = -2;
                continue;
            }
            if (sym_arr[i][j] == '.') {
                num_arr[i][j] = -1;
                continue;
            }
            
        }
    }
}

