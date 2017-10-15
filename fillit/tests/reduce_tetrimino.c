#include <stdio.h>
#include "fillit.h"

char    *reduce_tetrimino(char *t);

int main(void)
{
    char *t = "..#.\n..#.\n..#.\n..#.";

    printf("%s\n", reduce_tetrimino(t));
    return (0);
}
