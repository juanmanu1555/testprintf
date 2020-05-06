#include "ft_printf.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

//00111.01s
size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void    ft_putnbr(int numb)
{
    if (numb > 9)
        ft_putnbr(numb / 10);

    ft_putchar((numb % 10) + '0'); 
}

int     ft_nbrlen(int numb)
{
    int z;

    if (numb >= 0)
        z = 1;
    else
        return (0);
    while (numb > 9)
    {
        numb /= 10;
        z++;
    }    
    return (z);
}

unsigned long int ft_nbrlenlong (unsigned long int numb)
{
    unsigned long int z;
    if (numb >= 0)
        z = 1;
    else
        return (0);
    while (numb > 9)
    {
        numb /= 10;
        z++;
    }    
    return (z);
}

void    ft_putnbrlong(unsigned long int numb)
{
    if (numb > 9)
        ft_putnbr(numb / 10);

    ft_putchar((numb % 10) + '0'); 
}


char 		*ft_strdup(const char *s1)
{
	size_t		count;
	size_t		len;
	char		*s2;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc((len + 1) * sizeof(const char))))
		return (NULL);
	count = 0;
	while (count <= len)
	{
		s2[count] = s1[count];
		count++;
	}
	s2[count] = '\0';
	return (s2);
}

char    *ft_strinv(char *s1)
{
    long long int len;
    char *s2;
    size_t j;

    j = 0;
    len = ft_strlen(s1);
    //printf("\n%llu\n", len);
    //printf("\n%s\n", s1);
    if (!(s2 = malloc(sizeof(char) * (len + 1))))
      return (NULL);
    while (len > 0)
    {
        //printf("\n%c\n", *s1++);
        s2[j] = s1[len - 1];
        j++;
        len--;
    }
    s2[j] = 0;
    //printf("\n%s\n", s2);
    return (s2);
}

char    *ft_utohex(unsigned long int numb, char flag)
{
    char *s1;
    char *s2;
    unsigned long int res;
    unsigned long int div;
    char *hexa_array;
    int j;

    
    if (numb == 0)
    {
        s1  = malloc(2);
        s1[0] = '0';
        s1[1] = '\0';
        return (s1);
    }
    s1  = malloc(4000);
    res = numb;
    div = 0;
    j = 0;
    //printf("\n%lu\n", res);

    if (flag == 'x')
        hexa_array = ft_strdup("0123456789abcdef");
    else if (flag = 'X')
        hexa_array = ft_strdup("0123456789ABCDEF");
    while (res > 0)
    {
            if (numb > 15)
            {
                div = numb % 16;
                numb /= 16;
                s1[j] = hexa_array[div];
                res = numb;
            }
            else 
            {
                div = numb;
                s1[j ] = hexa_array[div];
                res = 0;
                // numb = 0;
            }
            // // if (numb > 15)
            
            // //printf("\n%lu\n", div);
            // //printf("\n%lu\n", numb);
            // // numb = res;
          
            // if (numb > 15)
                
            // else 
               
            // div = 0;
            // // printf("\n%lu\n", numb);
            j++;
        
    }
    //printf("\n%lu\n", res);
    s2 = ft_strinv(s1);
    //printf("\n%s\n", s1);
    return (s2);
}

void get_number_in_range(int *index, char *s1, int *property, int *property_len)
{
    // printf("entra en get number\n");
    // printf("index:%d\n", *index);   
    // printf("Entrada Desde get number:%d\n", *property_len);
    while (s1[*index] && (s1[*index] >= '0' && s1[*index] <= '9'))
    {
        if (*property == 0)
            *property += (s1[*index] - '0');
        else
            *property = (s1[*index] - '0') + 10 * (*property);
        *index += 1;
        *property_len += 1;
    }
    // printf("Salida Desde get number:%d\n", *property_len);
}

int validate_cero_or_minus( int *index, char *s1, t_config *config)
{       
    if (!(s1[*index] || s1[*index] == '0' || s1[*index] == '-'))
        return (0);
    while (s1[*index] == '0' || s1[*index] == '-')
    {
        if (s1[*index] == '0' && config->is_minus == 0 && config->width_char == ' ')
        {
            config->width_char = '0';
            config->is_cero = 1;
        }
        if (s1[*index] == '-' && config->is_minus == 0) 
        {
            config->width_char = ' ';
             config->is_minus = 1;
        }
        *index += 1;
    }
    return (1);   
}

int validate_width(int *index, char *s1, t_config *config)
{   
    if (!(s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9')))
        return (0);
    get_number_in_range(index, s1, &config->width, &config->width_len);
    return (1);
}

int validate_precision(int *index, char *s1, t_config *config)
{
    // printf("entra en precision\n");
    // printf("%d\n", *index);
    
    while (s1[*index] == '0')
        *index += 1;
    if (s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9'))
        get_number_in_range(index, s1, &config->precision, &config->precision_len);
    // if (!(s1[*index] && (s1[*index] >= '1' && s1[*index] <= '9')))
    //     return (0);
    // get_number_in_range(index, s1, &config->precision, &config->precision_len);
    return (1);
}


int validate_flag(int *index, char *s1, t_config *config)
{
    // printf("entra en flag\n");
    // printf("%d\n", *index);
    if (!s1[*index])
        return (0);
    if (s1[*index] != 'c' && s1[*index] != 's' && s1[*index] != 'p' && 
    s1[*index] != 'd' && s1[*index] != 'i' && s1[*index] != 'i' && s1[*index] != 'u' && 
    s1[*index] != 'x' && s1[*index] != 'X')
        return (0);
    config->flag = s1[*index];
    return (1);
}


int regex_validate(int *index, char *s1, t_config *config)
{
   // int     index;

    // es facil la implementacion para el * de sustitucion de valor de width o precision
    //index = 0;
    if (s1[*index] == '0' || s1[*index] == '-')
    {    
        //printf("entra en 0 or minus\n");
        if (!(validate_cero_or_minus(index, s1, config)))
            return (0);
        // if (!(validate_width(&index, s1, config)))
        //     return (0);
    }
    
    if (s1[*index] == '*')
    {
        config->is_width_arg = 1;
        *index += 1;
    }
    else
    {      
        if (s1[*index] >= '1' && s1[*index] <= '9')
        { 
            //printf("entra en width\n");
            if (!(validate_width(index, s1, config)))
            return (0);
        }

    }
    //printf("Lleaga a punto");
    if (s1[*index] == '.')
    {
        //printf("entra en precision\n");
        *index += 1;
        config->precision = 0;
        //printf("%c", s1[*index]);
        if (s1[*index] == '*')
        {
            config->is_precision_arg = 1;
            *index += 1;
        }
        else if (s1[*index] && (s1[*index] >= '0' && s1[*index] <= '9'))
        {
            if (!(validate_precision(index, s1, config)))
                return (0);
        }
        else
        {
            //printf("entra en precision\n");
            if (!(validate_flag(index, s1, config)))
                return (0);
            return (1);
        }

    }

    //printf("entra en flag\n");
    if (!(validate_flag(index, s1, config)))
        return (0);
    //*index += 1;
    //printf("sale correcto en flag\n");
    return (1);
}


// int    flag_s(t_config, *config, va_list *args)
// {
//     char    *s2;     
//     char    *s3;

//     z = 0;
//     // esto no va a funcionar xq si le metes width
//     // necesita poner los espacios y esto no lo hace.
//     // lo suyo seria solo hacer la carga de (null)
//     // y seguir con la funcion como siempre.
//     if ((s3 = va_arg(*args, char *)) == NULL)
//     {
//         int c;

//         s3 = ft_strdup("(null)");
//         c = 0;
//         while(c < 7)
//         {
//             ft_putchar(s3[c]);
//             c++;
//         }
//         free(s3);
//         config->width = 6;
//         return (1);
//     }
//     s2 = ft_strdup(s3);
//     len = (int)ft_strlen(s2);
//     return (0);
// }

// int    flag_d(t_config, *config, va_list *args)
// {

// }

// int cases_flags(t_config, *config, va_list *args)
// {
//     if (config->flag == 's')
//         return (flag_s(config, args));
//     if (config->flag == 'd')
//         return (flag_d(config, args))
// }

void   printf_arg(t_config *config, va_list *args, int arg_count)
{
    //printf("entra en printf arg");
    int z;
    int len; 
    char    *s2;     
    char    *s3;
    int     p;

    z = 0;
    arg_count = arg_count + 1;

    if (config->is_width_arg == 1)
    {   
        config->width = va_arg(*args, int);
        if (config->width < 0)
        {
            config->width *= -1;
            config->is_minus = 1;
        }
    }
    if (config->is_precision_arg == 1)
        config->precision = va_arg(*args, int);

    //printf("Este es el valor de width por argumento:%d", p);

    // Aqui extraemos el argumento que nos pasan lo que voy a hacer es una funcion donde pille todos los casos
    // de si es string int hexadecimal decimal float etc y meterlo todo en string asi es mucho mas facil trabajar con ello.
    if ((s3 = va_arg(*args, char *)) == NULL)
    {  
        
        //s3 = ft_strdup("(null)"); 

        // nose si esto es necesario dado que en este momento no tengo lo test. y no estoy en MAC
        // en linux si te pasan NULL y precision menor de 6 el "(null)" nose escribe ni cuenta.
        if (config->precision >= 6 || config->precision == -1)
            s3 = ft_strdup("(null)");
        else    
            s3 = ft_strdup("");
        // config->width += 6;    
        //printf("%d\n", config->width);
    }

    s2 = ft_strdup(s3);
    len = (int)ft_strlen(s2);
  

    if (config->precision > len || config->precision == -1)
        config->precision = len;

    if ((config->width == 0) || (config->width < config->precision))   
        config->width = config->precision;

// printf("config width:%d\n", config->width);
// printf("config precision:%d\n", config->precision);


    if (config->width > config->precision)
    {
        if (config->is_minus)
        {
            while(z < config->precision)
            {
                ft_putchar(s2[z]);
                z++;
            }

            while (z < config->width)
            {
                ft_putchar(config->width_char);
                z++;
            }
        }
        else
        {
             while (z < config->width - config->precision)
            {
                ft_putchar(config->width_char);
                z++;
            }
            z = 0;
            while(z < config->precision)
            {
                ft_putchar(s2[z]);
                z++;
            }
        }
    }
    else 
    {
         while(z < config->precision)                                                                                                                                               
        {
            ft_putchar(s2[z]);
            z++;
        }
    }
    free(s2);
}



void   printf_arg_int(t_config *config, va_list *args, int arg_count)
{
    // Posdata usar long en ints y unsigned long int en unsigned
    int z;
    int len;
    long numb;
    int is_negative;
    int ceros;

    z = 0;
    ceros = 0;
    is_negative = 0;
    arg_count = arg_count + 1; 
    numb =  (long)va_arg(*args, int);
    if (numb < 0)
    {
        numb *= -1;
        is_negative = 1;
    }
    len = ft_nbrlen(numb);  
    //config->width_char = ' ';

    // printf("\nprecision:%d\n", config->precision);

    // if (config->precision == -1 && config->width > len)
    //     ceros = config->width - len;
    if (config->precision > len)
        ceros = config->precision - len;
    else if (config->precision < len  && config->precision > 0 || config->precision == -1 )
        config->precision = len;

    if (is_negative && config->precision != 0)
    {    
        len += 1;
        config->precision += 1;
    }
    
    if (config->is_minus == 1 && config->precision == 0)
        config->is_minus = 0;

    //printf("\nTelica%d\n", ceros);
    if ((config->width == 0) || (config->width < config->precision))   
        config->width = config->precision;
    else if (config->width < len)
        config->width = len;


    //printf("\n%c\n", config->width_char);

    if (config->width > config->precision)
    {
        if (config->is_minus)
        {
            z += len;
            if (is_negative == 1)  
            {  
                ft_putchar('-');
   
            }
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
                z++;
            }


            // El error es que printeo el numero entero sin
            // x caracteres y lo que necesito es decidir 
            // cuantos quiero 3 5 o el valor que sea.
            if (config->precision > 0)
                ft_putnbr(numb);
           
           
            while (z < config->width)
            {
                ft_putchar(config->width_char);
                z++;
            }
        }
        else
        {
            if (config->width_char != '0')
            {
                while (z < config->width - config->precision)
                {
                    ft_putchar(config->width_char);
                    z++;
                }
                 if (is_negative == 1)  
                    ft_putchar('-');
            }
            else
            {
                if (is_negative == 1)  
                ft_putchar('-');
                while (z < config->width - config->precision)
                {
                    ft_putchar(config->width_char);
                    z++;
                }
            }
            z = 0;
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
            }   
            if (config->precision > 0)
                ft_putnbr(numb);
        }
    }
    else 
    {
        if (is_negative == 1)  
            ft_putchar('-');
        while (ceros > 0)
        {
            ft_putchar('0');
            ceros--;
        }   
       
        // printf("\n%d\n", len);
        if (config->precision > 0)
            ft_putnbr(numb);
    }
}


void printf_arg_unsigned_int(t_config *config, va_list *args, int arg_count)
{
     // Posdata usar long en ints y unsigned long int en unsigned
    int z;
    int len;
    unsigned long int numb;
    int is_negative;
    int ceros;

    z = 0;
    ceros = 0;
    is_negative = 0;
    arg_count = arg_count + 1; 
    numb =  va_arg(*args, unsigned int);
    if (numb < 0)
    {
        numb *= -1;
        is_negative = 1;
    }
  
    len = ft_nbrlenlong(numb);  
    //config->width_char = ' ';

    //printf("\nlen:%d\n", len);
    //printf("\n%d\n", config->precision);
    // if (config->precision == -1 && config->width > 0)
    //printf("\n%c\n", config->width_char);
    if (config->width > config->precision && config->precision != -1)
        config->width_char = ' ';
    if (config->precision > len)
        ceros = config->precision - len;
    else if (config->precision < len  && config->precision > 0 || config->precision == -1 )
        config->precision = len;
    //printf("\nprecision:%d\n", config->precision);
  
    //if (config->precsion)

    if (is_negative && config->precision != 0)
    {    
        len += 1;
        config->precision += 1;
    }
    
    if (config->is_minus == 1 && config->precision == 0)
        config->is_minus = 0;

    //printf("\nTelica%d\n", ceros);
    if ((config->width == 0) || (config->width < config->precision))   
        config->width = config->precision;
    else if (config->width < len)
        config->width = len;

    if (config->width > config->precision)
    {
        //config->width_char = ' ';
        if (config->is_minus)
        {
            z += len;
            if (is_negative == 1)  
            {  
                ft_putchar('-');
   
            }
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
                z++;
            }


            // El error es que printeo el numero entero sin
            // x caracteres y lo que necesito es decidir 
            // cuantos quiero 3 5 o el valor que sea.
            if (config->precision > 0)
                ft_putnbrlong(numb);
           
           
            while (z < config->width)
            {
                ft_putchar(config->width_char);
                z++;
            }
        }
        else
        {
            
            while (z < config->width - config->precision)
            {
                ft_putchar(config->width_char);
                z++;
            }

            z = 0;
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
            }   
            if (config->precision > 0)
                ft_putnbrlong(numb);
        }
    }
    else 
    {
        while (ceros > 0)
        {
            ft_putchar('0');
            ceros--;
        }   
        if (config->precision > 0)
            ft_putnbrlong(numb);
    }
}

void    printf_arg_hex(t_config *config, va_list *args, int arg_count)
{
    int z;
    int len;
    unsigned long int numb;
    char *s1;
    int is_negative;
    int ceros;
    int j;

    j = 0;
    z = 0;
    ceros = 0;
    is_negative = 0;
    arg_count = arg_count + 1; 
    numb =  va_arg(*args, unsigned int);
    if (numb < 0)
    {
        numb *= -1;
        is_negative = 1;
    }
  
    s1 = ft_utohex(numb, config->flag);
    len = ft_strlen(s1);  

    if (config->width > config->precision && config->precision != -1)
        config->width_char = ' ';

    if (config->precision > len)
        ceros = config->precision - len;
    else if (config->precision < len  && config->precision > 0 || config->precision == -1 )
        config->precision = len;


    if (is_negative && config->precision != 0)
    {    
        len += 1;
        config->precision += 1;
    }
    
    if (config->is_minus == 1 && config->precision == 0)
        config->is_minus = 0;

    //printf("\nTelica%d\n", ceros);
    if ((config->width == 0) || (config->width < config->precision))   
        config->width = config->precision;
    else if (config->width < len)
        config->width = len;

    if (config->width > config->precision)
    {
        //config->width_char = ' ';
        if (config->is_minus)
        {
            z += len;
          
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
                z++;
            }


            // El error es que printeo el numero entero sin
            // x caracteres y lo que necesito es decidir 
            // cuantos quiero 3 5 o el valor que sea.
            if (config->precision > 0)
            {
                if (config->flag == 'p')
                {
                    ft_putchar('0');
                    ft_putchar('x');
                    config->width += 2;
                }
                while (j < len)
                {
                    ft_putchar(s1[j]);
                    j++;

                }
            }
           
           
            while (z < config->width)
            {
                ft_putchar(config->width_char);
                z++;
            }
        }
        else
        {
            if (config->flag == 'p')
                config->width -= 2;
            
            while (z < config->width - config->precision)
            {
                ft_putchar(config->width_char);
                z++;
            }

            z = 0;
            if (config->flag == 'p')
                {
                    ft_putchar('0');
                    ft_putchar('x');
                    config->width += 2;
                }
            while (ceros > 0)
            {
                ft_putchar('0');
                ceros--;
            }   
            if (config->precision > 0)
            {
                while (j < len)
                {
                    ft_putchar(s1[j]);
                     j++;
                    
                }
            }
        }
    }
    else 
    {
        if (config->flag == 'p')
            ceros -= 2;
        while (ceros > 0)
        {
            ft_putchar('0');
            ceros--;
        }   
        if (config->precision > 0)
        {
            if (config->flag == 'p')
            {
                ft_putchar('0');
                ft_putchar('x');
                //config->width += 2;
            }
            //j += 2;
            while (j < len)
            {
                ft_putchar(s1[j]);
                j++;

            }
        }
    }
}

int ft_search(char *s1, t_config *config, va_list *args)
{
    int index;
    int arg_count;
    //gint validate;
    int total_width;

    index = 0;
    arg_count = 0;
    //validate = 0;
    total_width = 0;
    // char *s4;

    // s4 = va_arg(*args, char *);
    while (s1[index])
    {
        if (s1[index] == '%')
        {
            index++;
             arg_count++;
            //total_width++;
            if (regex_validate(&index, s1, config) == 1)
            {         
                if (config->flag == 's')
                    printf_arg(config, args, arg_count);
                if (config->flag == 'd' || config->flag == 'i')
                    printf_arg_int(config, args, arg_count);
                if (config->flag == 'u')
                    printf_arg_unsigned_int(config, args, arg_count);
                if (config->flag == 'x' || config->flag == 'X' || config->flag == 'p')
                    printf_arg_hex(config, args, arg_count);
                total_width += config->width;
            }
            *config = t_config_default;
            // else
            //     ft_putchar(s1[index]);
        }
        else
        // {
           ft_putchar(s1[index]);
        //     index++;
        // }       
        index++;
        total_width++;
    }
    return (total_width - arg_count);
}

int ft_printf(const char *s1, ...)
{
    //char *s1 = (char *)malloc(sizeof(char) * 100);
    // int index;
    int total;
    // index = 0;
    //s1 = "05.3s";
    total = 0;
    t_config config;
    config = t_config_default;
    va_list args;

    va_start(args, s1);
    total = ft_search((char *)s1, &config, &args);
    va_end(args);
    return (total);
    // printf("is_valid:%d\n", regex_validate((char*)s1, &config));
    // printf("width:%d\n", config.width);
    // printf("width_length:%d\n", config.width_len);
    // printf("precision:%d\n", config.precision); 
    // printf("precision length:%d\n", config.precision_len);
    // printf("flag:%c\n", config.flag); 

    //char *s2 = "jose";

    //int width = 0;
   // int precision = 3;
    // width = (width >= config.width) ? config.width : width;
    // width = config.width;
    // if (precision > config.precision && config.precision > 0)
    //     precision = config.precision;

    // int z;

    // z = 0;
    // ft_putchar('|');
    // if (width > precision)
    // {
    //     if (config.is_minus)
    //     {
    //         while(z < precision)
    //         {
    //             ft_putchar(s2[z]);
    //             z++;
    //         }
    //         while (z < width)
    //         {
    //             ft_putchar(config.width_char);
    //             z++;
    //         }
    //     }
    //     else
    //     {
    //          while (z < width - precision)
    //         {
    //             ft_putchar(config.width_char);
    //             z++;
    //         }
    //         z = 0;
    //         while(z < precision)
    //         {
    //             ft_putchar(s2[z]);
    //             z++;
    //         }
    //     }
    // }
    // else 
    // {
    //      while(z < precision)                                                                                                                                               
    //     {
    //         ft_putchar(s2[z]);
    //         z++;
    //     }
    // }
    // ft_putchar('|');
    // ft_putchar('\n');
    //return (0);
}


// int main(void)
// {
//     int result;

//     result = 0;
    // result = ft_printf("%7s%-5s", "hello", "world");
    // printf("\n%d\n", result);      
    // result = ft_printf("hello, %s.", "gavin");
    // printf("\n%d\n", result);    
    // result = ft_printf("this %s is empty", "");
    // printf("\n%d\n", result);   
    // result = ft_printf("%5s", "goes over"); 
    // printf("\n%d\n", result);
    // result = ft_printf("hello, %s.", NULL);
    // printf("\n%d\n", result);

    // int x = -281234567;
    // if (x < 0)
    //     x *= -1;
    // ft_putchar('-');
    // ft_putnbr(281234567);
    //result = ft_printf("%-6d", -12);
    //printf("\n%d\n", result);

    // Test in Main Manual for linux or Windows

    // STRINGS
    // result = ft_printf("|hello, %s.|", "gavin");
    // printf("\n%d\n", result -2);
    // printf("|%s|\n%d\n\n", "hello, gavin.", 13);

    // result = ft_printf("|%s|", "testing testing");
    // printf("\n%d\n", result -2);
    // printf("|%s|\n%d\n\n", "testing testing", 15);

    // result = ft_printf("|%s%s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%s%s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|..%s stuff %s|", "a", "b");
    // printf("\n%d\n", result -2);
    // printf("|..%s stuff %s|\n%d\n\n", "a", "b", 11);

    // result = ft_printf("|this %s is empty|", "");
    // printf("\n%d\n", result -2);
    // printf("|this %s is empty|\n%d\n\n", "", 14);

    // result = ft_printf("|this %s is %s|", "hello", "");
    // printf("\n%d\n", result -2);
    // printf("|this %s is %s|\n%d\n\n", "hello", "", 14);

    // result = ft_printf("|this %s is %s|", "", "hello");
    // printf("\n%d\n", result -2);
    // printf("|this %s is %s|\n%d\n\n", "", "hello", 14);

    // result = ft_printf("|%s%s%s|", "1", "2", "3's a charm");
    // printf("\n%d\n", result -2);
    // printf("|%s%s%s|\n%d\n\n", "1", "2", "3's a charm", 13);


    // result = ft_printf("|%32s|", "abc");
    // printf("\n%d\n", result -2);
    // printf("|%32s|\n%d\n\n", "abc", 32);

    // result = ft_printf("|%16s|", "nark nark");
    // printf("\n%d\n", result -2);
    // printf("|%16s|\n%d\n\n", "nark nark", 16);

    // result = ft_printf("|%5s|", "goes over");
    // printf("\n%d\n", result -2);
    // printf("|%5s|\n%d\n\n", "goes over", 9);

    // result = ft_printf("|%-32s|", "abc");
    // printf("\n%d\n", result -2);
    // printf("|%-32s|\n%d\n\n", "abc", 32);

    // result = ft_printf("|%-16s|", "nark nark");
    // printf("\n%d\n", result -2);
    // printf("|%-16s|\n%d\n\n", "nark nark", 16);

    // result = ft_printf("|%-5s|", "goes over");
    // printf("\n%d\n", result -2);
    // printf("|%-5s|\n%d\n\n", "goes over", 9);

    // result = ft_printf("|%.7s|", "hello");
    // printf("\n%d\n", result -2);
    // printf("|%.7s|\n%d\n\n", "hello", 5);

    // result = ft_printf("|%.3s|", "hello");
    // printf("\n%d\n", result -2);
    // printf("|%.3s|\n%d\n\n", "hello", 3);

    // result = ft_printf("|%.s|", "hello");
    // printf("\n%d\n", result -2);
    // printf("|%.s|\n%d\n\n", "hello", 0);

    // result = ft_printf("|%.0s|", "hello");
    // printf("\n%d\n", result -2);
    // printf("|%.0s|\n%d\n\n", "hello", 0);


    // result = ft_printf("|%.3s%.2s|", "holla", "bitch");
    // printf("\n%d\n", result -2);
    // printf("|%.3s%.2s|\n%d\n\n", "holla", "bitch", 5);

    // result = ft_printf("|%.2s%.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%.2s%.7s|\n%d\n\n", "hello", "world", 7);

    // result = ft_printf("|%.7s%.2s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%.7s%.2s|\n%d\n\n", "hello", "world", 7);

    // result = ft_printf("|%.5s%7s|", "yo", "boi");
    // printf("\n%d\n", result -2);
    // printf("|%.5s%7s|\n%d\n\n", "yo", "boi", 9);

    // result = ft_printf("|%7.5s|", "yolo");
    // printf("\n%d\n", result -2);
    // printf("|%7.5s|\n%d\n\n", "yolo", 7);

    // result = ft_printf("|%7.5s|", "bombastic");
    // printf("\n%d\n", result -2);
    // printf("|%7.5s|\n%d\n\n", "bombastic", 7);

    // result = ft_printf("|%-7.5s|", "yolo");
    // printf("\n%d\n", result -2);
    // printf("|%-7.5s|\n%d\n\n", "yolo", 7);

    // result = ft_printf("|%-7.5s|", "tubular");
    // printf("\n%d\n", result -2);
    // printf("|%-7.5s|\n%d\n\n", "tubular", 7);



    // result = ft_printf("|%7.7s%7.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.7s%7.7s|\n%d\n\n", "hello", "world", 14);

    // result = ft_printf("|%3.7s%7.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.7s%7.7s|\n%d\n\n", "hello", "world", 12);
    
    // result = ft_printf("|%7.7s%3.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.7s%3.7s|\n%d\n\n", "hello", "world", 12);

    // result = ft_printf("|%3.7s%3.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.7s%3.7s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%7.3s%7.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.3s%7.7s|\n%d\n\n", "hello", "world", 14);

    // result = ft_printf("|%3.3s%7.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.3s%7.7s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%7.3s%3.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.3s%3.7s|\n%d\n\n", "hello", "world", 12);

    // result = ft_printf("|%3.3s%3.7s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.3s%3.7s|\n%d\n\n", "hello", "world", 8);

    // result = ft_printf("|%7.7s%7.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.7s%7.3s|\n%d\n\n", "hello", "world", 14);

    // result = ft_printf("|%3.7s%7.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.7s%7.3s|\n%d\n\n", "hello", "world", 12);

    // result = ft_printf("|%7.7s%3.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.7s%3.3s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%3.7s%3.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.7s%3.3s|\n%d\n\n", "hello", "world", 8);

    // result = ft_printf("|%7.3s%7.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.3s%7.3s|\n%d\n\n", "hello", "world", 14);

    // result = ft_printf("|%3.3s%7.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.3s%7.3s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%7.3s%3.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7.3s%3.3s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%3.3s%3.3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3.3s%3.3s|\n%d\n\n", "hello", "world", 6);

    // result = ft_printf("|%3s%3s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%3s%3s|\n%d\n\n", "hello", "world", 10);

    // result = ft_printf("|%-7s%5s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%-7s%5s|\n%d\n\n", "hello", "world", 12);

    // result = ft_printf("|%7s%-5s|", "hello", "world");
    // printf("\n%d\n", result -2);
    // printf("|%7s%-5s|\n%d\n\n", "hello", "world", 12);

    // result = ft_printf("|hello, %s.|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|hello, %s.|\n%d\n\n", NULL, 14);

    // result = ft_printf("|%s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%32s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%32s|\n%d\n\n", NULL, 32);

    // result = ft_printf("|%2s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%2s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%-32s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-32s|\n%d\n\n", NULL, 32);

    // result = ft_printf("|%-16s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-16s|\n%d\n\n", NULL, 16);

    // result = ft_printf("|%-3s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-3s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%.9s|", "NULL");
    // printf("\n%d\n", result -2);
    // printf("|%.9s|\n%d\n\n", "NULL", 4);

    // result = ft_printf("|%.3s|", "NULL");
    // printf("\n%d\n", result -2);
    // printf("|%.3s|\n%d\n\n", "NULL", 3);

    // result = ft_printf("|%.s|", "NULL");
    // printf("\n%d\n", result -2);
    // printf("|%.s|\n%d\n\n", "NULL", 0);

    // result = ft_printf("|%.0s|", "NULL");
    // printf("\n%d\n", result -2);
    // printf("|%.0s|\n%d\n\n", "NULL", 0);

    // static char *s_hidden = "hi low\0don't print me lol\0";

    //De aqui a abajo funcionan x ahora
    // result = ft_printf("|%s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%3s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%3s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%9s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%9s|\n%d\n\n", s_hidden, 9);

    // result = ft_printf("|%.s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%.s|\n%d\n\n", s_hidden, 0);

    // result = ft_printf("|%.9s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%.9s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%.03s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%.03s|\n%d\n\n", s_hidden, 3);

    // result = ft_printf("|%.09s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%.09s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%.03s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%.03s|\n%d\n\n", NULL, 0);

    // result = ft_printf("|%.09s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%.09s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%.00s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%.00s|\n%d\n\n", "\0", 0);

    // result = ft_printf("|%.01s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%.01s|\n%d\n\n", "\0", 0);

    // result = ft_printf("|%.03s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%.03s|\n%d\n\n", "\0", 0);

    // result = ft_printf("|%.09s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%.09s|\n%d\n\n", "\0", 0);

    // result = ft_printf("|%3.s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%3.s|\n%d\n\n", s_hidden, 3);

    // result = ft_printf("|%10.s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%10.s|\n%d\n\n", s_hidden, 10);

    // result = ft_printf("|%3.s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%3.s|\n%d\n\n", NULL, 3);

    // result = ft_printf("|%10.s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%10.s|\n%d\n\n", NULL, 10);

    // result = ft_printf("|%1.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%1.s|\n%d\n\n", "\0", 1);

    // result = ft_printf("|%2.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%2.s|\n%d\n\n", "\0", 2);

    // result = ft_printf("|%9.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%9.s|\n%d\n\n", "\0", 9);

    // result = ft_printf("|%-3.s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-3.s|\n%d\n\n", s_hidden, 3);

    // result = ft_printf("|%-8.s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-8.s|\n%d\n\n", s_hidden, 8);

    // result = ft_printf("|%-3.s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-3.s|\n%d\n\n", NULL, 3);

    // result = ft_printf("|%-8.s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-8.s|\n%d\n\n", NULL, 8);

    // //Aqui otro comportamiento raro que nose si es xq estamos en linux.
    // //Me hace el padding del width aun sin parametro porque como podemos ver la precision se ignora xq no la pasan.
    // result = ft_printf("|%-8.0s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-8.0s|\n%d\n\n", NULL, 8);

    // result = ft_printf("|%-1.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%-1.s|\n%d\n\n", "\0", 1);

    // result = ft_printf("|%-2.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%-2.s|\n%d\n\n", "\0", 2);

    // result = ft_printf("|%-6.s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%-6.s|\n%d\n\n", "\0", 6);

    // result = ft_printf("|%3.1s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%3.1s|\n%d\n\n", s_hidden, 3);

    // result = ft_printf("|%10.1s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%10.1s|\n%d\n\n", s_hidden, 10);

    // result = ft_printf("|%3.1s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%3.1s|\n%d\n\n", NULL, 3);

    // result = ft_printf("|%9.1s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%9.1s|\n%d\n\n", NULL, 9);

    // result = ft_printf("|%-3.1s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-3.1s|\n%d\n\n", s_hidden, 3);

    // result = ft_printf("|%-10.1s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-10.1s|\n%d\n\n", s_hidden, 10);

    // result = ft_printf("|%-3.1s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-3.1s|\n%d\n\n", NULL, 3);

    // result = ft_printf("|%-9.1s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-9.1s|\n%d\n\n", NULL, 9);

    // result = ft_printf("|%-3.1s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%-3.1s|\n%d\n\n", "\0", 3);

    // result = ft_printf("|%-6.1s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%-6.1s|\n%d\n\n", "\0", 6);

    // result = ft_printf("|%3.6s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-3.6s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%20.6s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%20.6s|\n%d\n\n", s_hidden, 20);

    // result = ft_printf("|%3.6s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%3.6s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%20.6s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%20.6s|\n%d\n\n", NULL, 20);

    // result = ft_printf("|%3.6s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%3.6s|\n%d\n\n", "\0", 3);

    // result = ft_printf("|%6.6s|", "\0");
    // printf("\n%d\n", result -2);
    // printf("|%6.6s|\n%d\n\n", "\0", 6);

    // result = ft_printf("|%-3.6s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-3.6s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%-20.6s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-20.6s|\n%d\n\n", s_hidden, 20);

    // result = ft_printf("|%-3.8s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-3.8s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%-10.8s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-10.8s|\n%d\n\n", s_hidden, 10);

    // result = ft_printf("|%-3.8s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-3.8s|\n%d\n\n", NULL, 6);

    // result = ft_printf("|%-10.8s|", NULL);
    // printf("\n%d\n", result -2);
    // printf("|%-10.8s|\n%d\n\n", NULL, 10);

    // result = ft_printf("|%-.00s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-.00s|\n%d\n\n", s_hidden, 0);

    // result = ft_printf("|%-.09s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-.09s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%00s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%00s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%000s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%000s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%0000s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%0000s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%-00s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-00s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%0-0s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%0-0s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%00-s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%00-s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%03s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%03s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%00-s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%00-s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%09s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%09s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%-03s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-03s|\n%d\n\n", s_hidden, 6);

    // result = ft_printf("|%-09s|", s_hidden);
    // printf("\n%d\n", result -2);
    // printf("|%-09s|\n%d\n\n", s_hidden, 9);

    // Testings de String with arguments width and/or precision *
    // result = ft_printf("|%*.*s|", -7, 4, s_hidden);
    // printf("\n%d\n", result -2);

    // result = ft_printf("|%*.*s|", -7, s_hidden);
    // printf("\n%d\n", result -2);


    // INTEGERS TEST
    // result = ft_printf("|%20d|", -10);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %i number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %i number|", -267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %i number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%i|", 3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%i|", -1);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", -267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%i|", 2147483647);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%i|", -2147483678);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7i|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7i|", -14);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5i|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5i|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4i|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4i|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4i|", -2464);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7i|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7i|", -14);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5i|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5i|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4i|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4i|", -2464);
    // printf("\n%d\n", result -2);
    // printf("\n");




    // result = ft_printf("|%.5i|", 2);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.6i|", -3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4i|", 5263);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4i|", -2372);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3i|", 13862);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3i|", -23646);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%05i|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%07i|", -54);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03i|", 634);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%04i|", -532);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%04i|", -4825);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5i|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%10.5i|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3i|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3i|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.7i|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.7i|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3i|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3i|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5i|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-10.5i|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3i|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3i|", -8473);
    // printf("\n%d\n", result -2);

    // result = ft_printf("|%-3.7i|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.7i|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3i|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3i|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5i|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%010.5i|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3i|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3i|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.7i|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.7i|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3i|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3i|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5i|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-10.5i|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3i|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3i|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7i|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7i|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3i|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3i|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // result = ft_printf("|%0-8.5i|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-10.5i|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3i|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3i|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7i|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7i|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3i|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3i|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    //  static int			i_pos_1 = 878023;

    // result = ft_printf("|[%5.0i] [%i]|", 123, i_pos_1);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|[%1.0i]|", 123, i_pos_1);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.0i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("[%i] [%i]", i_pos_1, i_pos_1);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.0i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.0i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.0i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.i|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", -267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %d number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%d|", 3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%d|", -1);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%d|", 2147483647);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%d|", (int)(-2147483678));
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7d|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7d|", -14);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5d|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5d|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4d|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4d|", -2464);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7d|", -14);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5d|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5d|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4d|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4d|", -2464);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7d|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7d|", -14);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5d|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5d|", -2562);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4d|", -94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4d|", -2464);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.5d|", 2);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.6d|", -3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4d|", 5263);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4d|", -2372);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3d|", 13862);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3d|",-23646);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%05d|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%07d|", -54);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03d|", 634);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%04d|", -532);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%04d|", -4825);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5d|",34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%10.5d|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3d|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3d|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.7d|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.7d|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3d|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3d|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5d|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-10.5d|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3d|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3d|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.7d|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.7d|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3d|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3d|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5d|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%010.5d|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3d|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3d|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.7d|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.7d|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3d|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3d|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5d|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5d|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5d|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-10.5d|", -216);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3d|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3d|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3d|", -8473);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7d|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7d|", -2375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3d|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3d|", -8462);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.0d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.0d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.0d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.d|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // UNSIGNED INTEGERS
    
    // result = ft_printf("|this %u number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %u number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%u|", 3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %u number|", 4294967295u);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7u|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // result = ft_printf("|%3u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5u|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%4u|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7u|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5u|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4u|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.5u|", 2);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4u|", 5263);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3u|", 13862);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%05u|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // result = ft_printf("|%03u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03u|", 634);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5u|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3u|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.7u|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3u|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5u|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3u|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.7u|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3u|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5u|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3u|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.7u|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3u|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5u|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3u|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.7u|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3u|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.0u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.0u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.0u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.u|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // HEXADECIMALES

    //ft_utohex(1000000, 'x');
    // printf("%s", ft_utohex(1000, 'x'));

    // result = ft_printf("|%x|", 1000);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %x number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %x number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%x|", 3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%x|", 4294967295u);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%7x|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3x|",0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5x|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%2x|",94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%x|", 999);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7x|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5x|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4x|", 9648627);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.5x|", 21);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // result = ft_printf("|%05x|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");



    // result = ft_printf("|%.4x|", 5263);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3x|", 938862);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%05x|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03x|", 698334);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5x|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3x|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%2.7x|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3x|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5x|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3x|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-2.7x|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3.3x|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5x|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.5x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%08.3x|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%02.7x|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03.3x|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5x|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.5x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-8.3x|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-2.7x|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%0-3.3x|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.0x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.0x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5.x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.0x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5.x|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // // HEXADECIMAL UPPERCAP
    // result = ft_printf("|this %X number|", 17);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|this %X number|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%X|", 3);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%X|", 4294967295u);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // result = ft_printf("|%7X|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%5X|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%2X|", 94827);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-7X|", 33);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-3X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-5X|", 52625);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-4X|", 9648627);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.5X|", 21);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.4X|", 5263);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%.3X|", 938862);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%05X|", 43);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03X|", 698334);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5X|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.5X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%8.3X|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%2.7X|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%3.3X|", 6983);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%03X|", 698334);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5X|", 34);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.5X|", 0);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-8.3X|", 8375);
    // printf("\n%d\n", result -2);
    // printf("\n");

    // result = ft_printf("|%-2.7X|", 3267);
    // printf("\n%d\n", result -2);
    // printf("\n");

//    result = ft_printf("|%-3.3X|", 6983);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%08.5X|", 34);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%08.5X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%08.3X|", 8375);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%02.7X|", 3267);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%03.3X|", 6983);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%0-8.5X|", 34);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%0-8.5X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%0-8.3X|", 8375);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%0-2.7X|", 3267);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%0-3.3X|", 6983);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%.0X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%.X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%5.0X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%5.X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%-5.0X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

//     result = ft_printf("|%-5.X|", 0);
//     printf("\n%d\n", result -2);
//     printf("\n");

    //     result = ft_printf("|%x|", -52625);
    // printf("\n%d\n", result -2);
    // printf("\n");


    // POINTERS 

    // static char	a01;
    // static unsigned char a02;
    // static short a03;
    // static unsigned short a04;
    // static int a05;
    // static unsigned int a06;
    // static long a07;
    // static unsigned long a08;
    // static long long a09;
    // static unsigned long long a10;
    // static char *a11;
    // static void *a12;

    // // result = ft_printf("|%p|", NULL);
    // // printf("\n%d\n", result -2);
    // // printf("\n");

    // result = ft_printf("|%9.2p|", 1234);
    // printf("\n%d\n", result -2);
    // printf("\n");
    // return (0);   
// }



//Pointers - Basic
// static char	a01;
// static unsigned char a02;
// static short a03;
// static unsigned short a04;
// static int a05;
// static unsigned int a06;
// static long a07;
// static unsigned long a08;
// static long long a09;
// static unsigned long long a10;
// static char *a11;
// static void *a12;

// int p_null(void){return test("%p", NULL);}
// int p_null_width_fit(void){return test("%5p", NULL);}
// int p_null_width_nofit(void){return test("%2p", NULL);}

// int p_void(void){return test("%.p", NULL);}
// int p_void_width_fit(void){return test("%5.p", NULL);}
// int p_void_width_nofit(void){return test("%2.p", NULL);}

// int	p_ftfc_literal_9w_prec2_undefbehav(void){return test("%9.2p\n", 1234);}
// int	p_ftfc_literal_2w_prec9_undefbehav(void){return test("%2.9p\n", 1234);}
// int	p_ftfc_zero_prec5_undefbehav(void){return test("%.5p", 0);}
// int	p_ftfc_zero_prec0_undefbehav(void){return test("%.0p", 0);}
// int p_ftfc_5w_throwswarning(void){return test("%5p", 0);}