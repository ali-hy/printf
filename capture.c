#include "main.h"

int capture_int(va_list l)
{
    return (va_arg(l,int));
}
long capture_long(va_list l)
{
    return (va_arg(l,long));
}
long capture_num(conversion_data *c_data, va_list l)
{
    if (*(c_data->len_mod) == 'l')
        return (capture_long(l));

    if (c_data->code == 'i' || c_data->code == 'd')
        return (capture_int(l));

    return (capture_uint(l));
}

unsigned int capture_uint(va_list l)
{
    return (va_arg(l,unsigned int));
}