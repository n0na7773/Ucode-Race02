#include "../inc/header.h"

int main(int argc, char* argv[]){
    check_args(argc);
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);
    char *str = mx_file_to_str(argv[1]);
    check_file(str);
    check_ark(str);
    check_symbols(str);
    int row = 0;
    int col = 0;
    int dot = 0;
    reading_data(str, &dot, &row, &col);
    check_range(row, col, x1, x2, y1, y2);
    char sym_arr[row][col];
    input_symb_arr(row, col, str, sym_arr);
    check_point_in(sym_arr[y1][x1]);
    check_point_ex(sym_arr[y2][x2]);
    int num_arr[row][col];
    input_num_arr(row, col, sym_arr, num_arr);
    mx_alg(x1, y1, x2, y2, dot, row, col,num_arr);
    input_in_file(str);
}
