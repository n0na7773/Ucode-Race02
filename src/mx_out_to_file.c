#include "../inc/header.h"

void input_in_file(char * str) {
    int file_descriptor = open("path.txt", O_CREAT | O_WRONLY | O_RDONLY, 0666);
    write(file_descriptor,str,mx_strlen(str));
	close(file_descriptor);
}
