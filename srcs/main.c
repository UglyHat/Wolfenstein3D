/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:32:27 by adespond          #+#    #+#             */
/*   Updated: 2017/10/14 09:40:01 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				main(int argc, char **argv)
{
	t_env	*e;

	e = init_env();
	if (argc != 2)
		error_arg();
	if (open_file(e, argv[1]) == 0)
		error_map();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT,
			"Wolf3D");
	mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, ft_loop_hook, e);
	mlx_hook(e->mlx.win, KEYPRESS, KEYPRESSMASK, ft_key_move, e);
	mlx_key_hook(e->mlx.win, ft_key_move, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
