/*
** EPITECH PROJECT, 2026
** project
** File description:
** file
*/

unsigned int uctoui(unsigned char *arg, int type)
{
    unsigned int result = 0;
    unsigned int pow = 1;

    for (int i = type; type > 0; i++){
        result += arg[i - 1] * pow;
        pow *= 256;
    }
    return result;
}
