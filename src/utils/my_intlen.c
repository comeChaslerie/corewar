/*
** EPITECH PROJECT, 2025
** my_intlen
** File description:
** Return the len of an int
*/

int my_intlen(int nb)
{
    int res = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        res += 1;
    while (nb != 0){
        res += 1;
        nb = nb / 10;
    }
    return res;
}
