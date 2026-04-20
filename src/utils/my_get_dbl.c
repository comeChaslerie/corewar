/*
** EPITECH PROJECT, 2025
** my_getnbr.c
** File description:
** return number
*/

static int get_sign_dbl(char const *str, int i)
{
    int sign = 1;

    while (i >= 0) {
        if (str[i] == '-')
            sign *= -1;
        i--;
    }
    return (sign);
}

static int get_start(char const *str, int *i, int *sign)
{
    while (str[*i] < '0' || str[*i] > '9')
        if (str[*i] == '\0')
            return 0;
        else
            *i += 1;
    if (*i > 0)
        if (str[*i - 1] == '-' || str[*i - 1] == '+')
            *sign = get_sign_dbl(str, *i);
    return 1;
}

static void get_after_coma(double *result, char const *str, int i)
{
    int pos_deci = 10;

    while (str[i] >= '0' && str[i] <= '9') {
        *result += (double)(str[i] - 48) / pos_deci;
        pos_deci *= 10;
        i++;
    }
}

double my_get_dbl(char const *str, int start)
{
    int i = start;
    int sign = 1;
    double result = 0;

    get_start(str, &i, &sign);
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    if (str[i] == '.' || str[i] == ',')
        get_after_coma(&result, str, i + 1);
    return (result * sign);
}
