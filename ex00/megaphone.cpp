#include <iostream>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_upper(char *s)
{
    int i;

    i = -1;
    while (++i < ft_strlen(s))
    {
        if (s[i] > 96 && s[i] < 123)
            s[i] -= 32;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (++i < ac)
        {
            ft_upper(av[i]);
            std::cout << av[i];
        }
        std::cout << std::endl;
    }
    return (0);
}
