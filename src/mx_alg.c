#include "../inc/header.h"

void output(int dist, int ex) {
    write(1,"dist=",5);
    mx_printint(dist);
    write(1,"\n",1);
    write(1,"exit=",5);
    mx_printint(ex);
    write(1,"\n",1); 
}

void mx_alg(int x1, int y1, int x2, int y2, int point, int row, int col, int ( *num_arr )[col]) {
    num_arr[y1][x1] = 0;
    point = point-1;
    int in = 0;
    for (int point_now = 0; point_now < point;) {
        for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++) {
               if(num_arr[i][j] >= 0) {
                    if ((i - 1 >= 0) && (num_arr[i - 1][j] == -1)) {
                       num_arr[i - 1][j] = num_arr[i][j] + 1;
                       point_now++;
                       in = 1;
                    }
                    if ((i + 1 != row) && (num_arr[i + 1][j] == -1)) {
                       num_arr[i + 1][j] = num_arr[i][j] + 1;
                       point_now++;
                       in = 1;
                    }
                    if ((j - 1 >= 0) && (num_arr[i][j - 1] == -1)) {
                       num_arr[i][j - 1] = num_arr[i][j] + 1;
                       point_now++;
                       in = 1;
                    }
                    if ((j + 1 != col) && (num_arr[i][j + 1] == -1)) {
                       num_arr[i][j + 1] = num_arr[i][j] + 1;
                       point_now++;
                       in = 1;
                    }
               }
           }
        }
        if (in == 0) {
            break;
        }
        in = 0;
    }
    int ex = num_arr[y2][x2];
    check_route(ex);
    int dist = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (num_arr[i][j] != -2 && dist < num_arr[i][j])
                dist = num_arr[i][j];
        }
    } 
    output(dist, ex);
}
