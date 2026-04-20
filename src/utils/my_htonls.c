/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

short my_htons(short val)
{
    short result = 0;

    result = val >> 8 & 0xFF;
    result += val << 8 & 0xFF00;
    return result;
}

int my_htonl(int val)
{
    int result = 0;

    result = (val >> 24) & 0xFF;
    result += (val >> 8) & 0xFF00;
    result += (val << 8) & 0xFF0000;
    result += (val << 24) & 0xFF000000;
    return result;
}
