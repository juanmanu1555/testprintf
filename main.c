#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"

size_t ft_strlen(const char *s1)
{
    size_t z;

    z = 0;
    while (s1[z])
        z++;
    return (z);
}

int validate_is_cero_or_minus(char *s1, t_config *config)
{
    int     z;

    z = 0;
    while (s1[z] == '0' || s1[z] == '-') 
    {
        if (s1[z] == '0' && config->is_minus == 0 && config->width_char == ' ')
        {
            config->width_char = '0';
            config->is_cero = 1;
        }
        if (s1[z] == '-' && config->is_minus == 0) 
        {
            config->width_char = ' ';
             config->is_minus = 1;
        }
        z++;
    }
    return (z);   
}

int validate_is_number_in_range(int *z, char *s1, t_config *config)
{
   int width;
   int   index;

   width = 0;  
   index = 0;
//    printf("%d", s1[*z + 2] - '0');
   //printf("%d", (s1[*z] - '0') * 10 );
  while (s1[*z] && (s1[*z] >= '0' && s1[*z] <= '9'))
  {
    //   printf("%d\n", s1[*z] - '0');
    if (index == 0)
        width += (s1[*z] - '0');
    else
        width = (s1[*z] - '0') + 10 * width;
    //   config->width += s1[*z] - '0';
    index++;
    *z += 1;
  }
  //printf("%d", (s1[*z] - '0') * 10);
  config->width = width;
}

// void initConfig(t_config *config,)


int validate_is_point(int *z, char *s1, t_config config)
{
    if (s1[z] != '.')
        return (0);
    

    return (1);    
}


// -0111.01s
int validate_flag(char *s1)
{   
    int     z;
    t_config config;

    z = 0;
    config = t_config_default;

    if (!s1)
        return (-1);
    z = validate_is_cero_or_minus(s1, &config);
    // printf("%c", config.width_char);
    // printf("%d", z);
    validate_is_number_in_range(&z, s1, &config);
    //printf("%d", config.width);

    size_t y = 0;
    char s3[6] = "pepito";
    size_t len = ft_strlen(s3);
    // hay que comprobar tambien si tiene precision y si es mas pequeña que la longitud.
    // si es asi la longitud se recorta en caso de strings en los demas por ahora no lo se.
    config.width = (len >= config.width) ? len : config.width - len;
    printf("%d\n", config.width);

    if (config.is_minus)
    {
        while (y < len)
        {
            putchar(s3[y]);
            y++;
        }
        y = 0;
        // if (config.is_minus)
        //     config.width_char = ' ';
        while (y < config.width)
        {              
            putchar(config.width_char);
            y++;
        }
    }
    else
    {
        //  if (config.is_minus)
        //     config.width_char = ' ';
        while (y <= config.width)
        {   
            
        putchar(config.width_char);
            y++;
        }
        y = 0; if (s1[z] == '.')
        while (y <= len)
        {
            putchar(s3[y]);
            y++;
        }
        
    }



    // while (s1[z] == '0' || s1[z] == '-') 
    //     z++;   
    // while (s1[z] && (s1[z] >= '0' && s1[z] <= '9'))
    //     z++;
    // if ((s1[z] == '.')||(s1[z] == 's'))
    // {
    //     if (s1[z] == '.')
    //     {
    //         z++;
    //         while (s1[z] && s1[z] >= '0' && s1[z] <= '9')
    //             z++;
    //         if (s1[z] == 's')
    //             return (0);
    //         return (-1);
    //     }
    //     if (s1[z] == 's')
    //         return (0);
    //     return (-1);        
    // }
    // else 
    //     return (-1);







    //HASTA ANTES ESTA BIEN

    // while (s1[z] == '0' || s1[z] == '-') 
    //     z++;   
    // while (s1[z] && (s1[z]) >= '0' && s1[z] <= '9')
    //     z++;
    // // printf("%c", s1[z]);
    // if ( (s1[z] == '.') || (s1[z] == 's') )
    // {
    //         if (s1[z] == '.')
    //         {
    //             z++;
    //             while (s1[z] && s1[z] >= '0' && s1[z] <= '9')
    //                 z++;
    //             if (s1[z] == 's')
    //             {
    //                 // printf("%c", s1[z]);
    //                 return (0);
    //             }
    //             return (-1);
    //         }
    //         else
    //             return (0);        
    // }
    // return (-1);
    //     else 
    //         return (-1);
    //     min_char = '0';
    // }
    // else {
    // }
    // return (0);
    // while (s1[z] == '0' || s1[z] == '-') 
    //     z++;   
    // if (!(s1[z] && (s1[z] >= '1' && s1[z] <= '9')))
    //     return (-1);
    // z++;
    // while (s1[z] && (s1[z]) >= '0' && s1[z] <= '9')
    //     z++;
    // if ((s1[z] == '.') || (s1[z] == 's'))
    // {
    //     if (s1[z] == '.')
    //     {
    //         z++;
    //         while (s1[z] && s1[z] >= '0' && s1[z] <= '9')
    //             z++;
    //         if (s1[z] == 's')
    //             return (0);
    //         return (-1);
    //     }
    //     else
    //         return (0);        
    // }
    // else 
    //    return (-1);
    // min_char = '0';
    // }
    // else {
    // }
    // return (0);
    // if (s1[z] == '0')
    // {
    //     z++;
    //     if (!(s1[z] && (s1[z] >= '1' && s1[z] <= '9')))
    //         return (-1);
    //     z++;
    //     while (s1[z] && (s1[z]) >= '0' && s1[z] <= '9')
    //         z++;
    //     if ((s1[z] == '.') || (s1[z] == 's'))
    //     {
    //         if (s1[z] == '.')
    //         {
    //             z++;
    //             while (s1[z] && s1[z] >= '0' && s1[z] <= '9')
    //                 z++;
    //             if (s1[z] == 's')
    //                 return (0);
    //             return (-1);
    //         }
    //         else
    //             return (0);        
    //     }
    //     else 
    //         return (-1);
        
    // }
}

int main()
{   
    char *s1 = (char *)malloc(sizeof(char) * 100);

    s1 = "00111.01s";

    validate_flag(s1);
    // printf("%d", validate_flag(s1));
    // printf("|%-.d10ñb,.12s----00000----03.21%-.s|", 5, "pepe");
    //printf("|%-.01s|", "pepe");
    return (0);
}




     // if (s1[z] == 's')
        // {

        // }
        // else if (s1[z] == 's')
        // {
        //     (s1[z] == '')
        // }
        // else 
        // {
        //     return (-1);
        // }
            // if (!(s1[z] >= '1' && s1[z] <= '9') || (s1[z] == '.') || )
            // z++;