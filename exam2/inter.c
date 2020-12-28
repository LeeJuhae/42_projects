#include <unistd.h>

int     check(char *str, char c, int len)
{
    int     i;

    i = 0;
    while (str[i] && (i < len || len == -1))
	{
        if (str[i] == c)
            return (1);
		++i;
	}
    return (0);
}

int     main(int argc, char *argv[])
{
    int     i;

    if (argc == 3)
    {
        i = 0;
        while(argv[1][i])
        {
            if (!check(argv[1], argv[1][i], i) && check(argv[2], argv[1][i], -1))
                write(1, &argv[1][i], 1);
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}
