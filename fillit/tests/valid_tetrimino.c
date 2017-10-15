#include <stdio.h>
#include <stdlib.h>

char    **ft_darraynew(int i, int j)
{
    int n;
    char **darray;

    n = 0;
    darray = (char **)malloc(sizeof(char*) * i);
    while (n < i)
    {
        darray[n++] = (char *)malloc(sizeof(char) * j);
    }
    return (darray);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*destcpy;

	destcpy = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (destcpy);
}

char	**valid_tetriminos(void)
//run through and strcmp everything
{
    char    **valids;

    valids = ft_darraynew(19, 14);
    ft_strcpy(valids[0], "####");
    ft_strcpy(valids[1], "##..##");
    ft_strcpy(valids[2], "#...#...#...#");
    ft_strcpy(valids[3], "##..#...#");
    ft_strcpy(valids[4], "#...##..#");
    ft_strcpy(valids[5], "#...#...##");
    ft_strcpy(valids[6], "#...#..##");
    ft_strcpy(valids[7], "##...#...#");
    ft_strcpy(valids[8], "#...###");
    ft_strcpy(valids[9], "#.###");
    ft_strcpy(valids[10], "###.#");
    ft_strcpy(valids[11], "###...#");
    ft_strcpy(valids[12], "##.##");
    ft_strcpy(valids[13], "#..##..#");
    ft_strcpy(valids[14], "###..#");
    ft_strcpy(valids[15], "#..##...#");
    ft_strcpy(valids[16], "###..#");
    ft_strcpy(valids[17], "#..###");
    ft_strcpy(valids[18], "##...##");
    valids[19] = NULL;
    return (valids);
}

int main(void)
{
    char    **tets;

    tets = valid_tetriminos();
    printf("%s\n", tets[18]);
    return (0);
}
