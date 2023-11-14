#include "main.h"

conversion_data get_conversion_data(const char *s)
{
    conversion_data c_data;
    reset_conversion(&c_data);
    flag_t cur_flag = is_flag(*s);

    while (cur_flag)
    {
        activate_flag(&c_data, cur_flag);
        s++;
        cur_flag = is_flag(s);
    }
    c_data.min_width = stoi(&s);
    if (*s == '.')
    {
        s++;
        c_data.precision = stoi(&s);
    }
    if (is_len_mod(*s))
    {
        c_data.len_mod = s;
        s++;
    }
    c_data.code = *s;
}