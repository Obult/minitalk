#include <unistd.h>

int		ft_strlen(unsigned char *str)
{
	int	i;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		sum = sum * 10 + str[i] - 48;
		i++;
	}
	return (sum);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
		write(1, "-1", 2);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + 48);		
	}
	else
		ft_putchar(nbr + 48);
}