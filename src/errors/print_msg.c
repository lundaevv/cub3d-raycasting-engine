#include "../../includes/main.h"

int print_msg(const char *str, const char *detail, int exit_no)
{
    if (!detail)
        ft_printf(str, STR_PROG_NAME);
    else
        ft_printf(str, STR_PROG_NAME, detail);
    return (exit_no);
}
