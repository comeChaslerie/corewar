/*
** EPITECH PROJECT, 2025
** my_intlen
** File description:
** Return len of an integer
*/

int my_intlen(int nb)
{
    int res = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        res++;
    while (nb != 0){
        res++;
        nb = nb / 10;
    }
    return res;
}

int my_intlen_u(unsigned int nb)
{
    int res = 0;

    if (nb == 0)
        return 1;
    while (nb != 0){
        res++;
        nb = nb / 10;
    }
    return res;
}
