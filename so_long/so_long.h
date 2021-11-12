#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void);
#endif