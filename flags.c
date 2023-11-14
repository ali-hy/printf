#include "main.h"

/**
 * flag_is_active - checks if conversion data has a flag marked as active
 * @c_data: pointer to conversion data
 * @flag: flag to check for
 * Return: 1 if flag is active, 0 if flag isn't active
 */
int flag_is_active(conversion_data *c_data, flag_t flag)
{
	if ((c_data->flag_comb & flag) > 0)
		return (1);

	return (0);
}

/**
 * activate_flag - activates a flag in conversion data
 * @c_data: pointer to conversion data
 * @flag: flag to activate
 */
void activate_flag(conversion_data *c_data, flag_t flag)
{
	c_data->flag_comb = c_data->flag_comb | flag;
}

/*char *apply_concat_flags(conversion_data *c_data, const char *current)
{
	char *res;


}*/