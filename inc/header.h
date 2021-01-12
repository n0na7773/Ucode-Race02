#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdbool.h"
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"
char *mx_file_to_str(const char *filename);
void mx_printerr(const char *s);
int mx_strlen(const char *str);
int mx_atoi(const char *str);
bool mx_isdigit(char c);
bool mx_isspace(char c); 
char *mx_strnew(const int size);
void mx_printint(int n);
void mx_printchar(char c);
void output(int dist, int ex);

void check_args(int argc);
void check_file(char* str);
void check_ark(char *str);
void check_symbols(char *str);
void check_range(int row, int col, int x1, int x2, int y1, int y2);
void check_route(int ex);
void check_point_in(char entry_point);
void check_point_ex(char exit_point);
void reading_data(char *str, int *dot, int *row, int *col);
void input_symb_arr(int row, int col, char *str, char sym_arr[row][col]);
void input_num_arr(int row, int col, char sym_arr[row][col], int num_arr[row][col]);
void input_in_file(char * str);
void mx_alg(int x1, int y1, int x2, int y2, int point, int row, int col, int ( *num_arr )[col]);

#endif
