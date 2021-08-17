#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef struct  s_decoding
{
    int     i;
    int     j;
    unsigned char   *string;
}               t_decoding;

int		ft_strlen(unsigned char *str);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);

#endif