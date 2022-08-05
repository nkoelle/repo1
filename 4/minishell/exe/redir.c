/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:09:47 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 16:00:42 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_redir(t_input *input, t_exe_locals *locals, int set)
{
	static int	i;

	while (input->operator != NULL)
	{
		if (input->operator->pos == 0)
			i = 0;
		if (redir_routine(input, locals, set == 1))
			return (1);
		if (input->operator != NULL && i == input->operator->pos)
			input->operator = input->operator->next;
		if (input->operator != NULL && i != input->operator->pos)
		{
			i++;
			return (0);
		}
	}
	return (0);
}

int	redirct_stdin(t_input *tmp, t_exe_locals *locals, int set)
{
	int	fd;

	fd = 0;
	if (set == 0)
	{
		locals->fd_in = open(tmp->operator->content, O_RDONLY, 0777);
		fd = locals->fd_in;
		if (locals->fd_in < 0)
			return (0);
	}
	else if (set == 1)
	{
		locals->fd_in = open(tmp->operator->content, O_WRONLY, 0777);
		safe_fd_set(&locals->fd_in, fd);
	}
	return (1);
}

int	redirct_std_type_in(t_input *tmp, t_exe_locals *locals, int set)
{
	int	pipe_fd;

	(void)set;
	pipe_fd = STDOUT_FILENO;
	safe_pipe(&pipe_fd, &locals->fd_in);
	write(pipe_fd, tmp->operator->content, strlen(tmp->operator->content));
	close(pipe_fd);
	return (1);
}

int	redirct_trunc(t_input *tmp, t_exe_locals *locals, int set)
{
	if (set == 0)
		locals->fd_out = open(tmp->operator->content,
				O_WRONLY | O_CREAT | O_RDONLY | O_TRUNC, 0777);
	else if (set == 1)
	{
		if (locals->fd_out > 1)
			close(locals->fd_out);
		return (safe_fd_set(&locals->fd_out, open(
					tmp->operator->content,
					O_WRONLY, 0777)));
	}
	return (1);
}

int	redirct_app(t_input *tmp, t_exe_locals *locals, int set)
{
	if (set == 0)
		locals->fd_out = open(tmp->operator->content,
				O_APPEND | O_CREAT | O_WRONLY, 0777);
	else if (set == 1)
	{
		if (locals->fd_out > 1)
			close(locals->fd_out);
		return (safe_fd_set(&locals->fd_out, open(
					tmp->operator->content,
					O_APPEND | O_CREAT | O_WRONLY, 0777)));
	}
	return (1);
}
