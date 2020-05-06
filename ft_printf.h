#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

typedef struct      s_config {
    int     width;
    int     width_len;
    char    width_char;
    int     precision;
    int     precision_len;
    char    flag;
    int     is_width_arg;
    int     is_precision_arg;
    int     is_minus;
    int     is_cero;
    int     is_width;
    int     is_precision;
}                   t_config;

#define t_config_default (t_config){0, 0,' ', -1, 0, 0, 0, 0 ,0, 0, 0, 0}

int ft_printf(const char *s1, ...);

#endif

