/*
** EPITECH PROJECT, 2025
** is_something
** File description:
** check if char is a number or a letter
*/
int is_nbr(char chara)
{
    if (chara >= '0' && chara <= '9')
        return 1;
    return 0;
}

int is_char(char chara)
{
    if ((chara >= 'a' && chara <= 'z') ||
        (chara >= 'A' && chara <= 'Z'))
        return 1;
    return 0;
}
