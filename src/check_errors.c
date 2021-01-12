#include "../inc/header.h"

void check_args(int argc) {
    if(argc != 6){ 
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(-1);
    }
}

void check_file(char *str) {
    if (!str) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }

    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] != '#' && str[i] != ',' && str[i] != '.' && str[i] != '\n') {
            mx_printerr("map error\n");
            exit(-1);
        }
    }
}

void check_ark(char *str) {
    int count = 0;
    int new_count = 0;
    for (int i = 0; i < mx_strlen(str); i++) { 
        while (str[i] != '\n') {
            new_count++;
            i++;
        }
        if(count != 0) {
            if (count != new_count) {
                mx_printerr("map error\n");
                exit(-1);
            }
        }
        count = new_count;
        new_count = 0;
    }
}


void check_symbols(char *str) {
    char t;
    char t1;
    for (int i = 1; i < mx_strlen(str); i++){
        t1 = str[i - 1];
        t = str[i];
        if (t1 == t) {
            mx_printerr("error\n");
            exit(-1);
        }
    }
}

void check_range(int row, int col, int x1, int x2, int y1, int y2) {
    if (x1 >= col || y1 >= row || x2 >= col || y2 >= row) {
        mx_printerr("points are out of map range\n");
        exit(-1);
    }
}

void check_route(int ex) {
    if (ex == -1) {
        mx_printerr("route not found\n");
        exit(-1);
    }
}

void check_point_in(char entry_point) {
    if (entry_point == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(-1);
    }
}

void check_point_ex(char exit_point) {
    if (exit_point == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(-1);
    }
}
