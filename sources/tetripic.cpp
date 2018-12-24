#include "../includes/tetripic.hpp"

int main(int ac, char **av) {

    if(strcmp(av[1], "1") == 0)
        task1();
    if(strcmp(av[1], "2") == 0)
        task2();
    if(strcmp(av[1], "3") == 0)
        task3("cerinta3.in");
    if(strcmp(av[1], "4") == 0)
        task4("cerinta4.bmp", "cerinta4.in");
    return(0);
}