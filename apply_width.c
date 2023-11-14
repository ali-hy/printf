#include "main.h"

char *apply_width(conversion_data *c_data, const char *s)
{
    int length = len(s);
    char *res,*temp;

    if (length >= c_data->min_width)
        return (s);
    
    if (c_data->code != 'c')
    {
        temp = blank(c_data, c_data->min_width - length);
        if (flag_is_active(c_data, F_LEFT))
            res = concat(s, temp);
        else
            res = concat(temp, s);
        free (temp);
        if (c_data->code != 's')
            free(s);
    }
    
    return (res);
}

char *blank(conversion_data *c_data, int n)
{
    char *res = malloc(n+1);
    char c = flag_is_active(c_data, F_ZERO) ? '0' : ' ';

    if (res == NULL)
        return (NULL);
    
    res[n] = '/0';
    while (--n >= 0)
    {
        res[n] = c;
    }
    return (res);
}