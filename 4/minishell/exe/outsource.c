/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outsource.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:50:24 by nkolle            #+#    #+#             */
/*   Updated: 2022/08/04 19:50:44 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_child_fds(t_exe_locals *locals, int fd[2])
{
	if (locals->fd_in != STDIN_FILENO)
	{
		dup2(locals->fd_in, STDIN_FILENO);
		close(locals->fd_in);
	}
	if (locals->fd_out != STDOUT_FILENO)
		dup2(locals->fd_out, STDOUT_FILENO);
	else if (locals->i != locals->j - 1)
		dup2(fd[1], STDOUT_FILENO);
	else if (locals->i == locals->j - 1)
	{
		close(STDOUT_FILENO);
		dup2(locals->fd_standard_out, STDOUT_FILENO);
	}
	protected_close(locals->fd_out);
	close(fd[0]);
	close(fd[1]);
}

void	fd_handle(t_exe_locals	*locals, int fd[2])
{
	locals->pa[locals->i] = locals->pid;
	close(fd[1]);
	protected_close(locals->fd_in);
	protected_close(locals->fd_out);
	if (locals->i != locals->j - 1 && locals->fd_next == 0)
		locals->fd_in = dup(fd[0]);
	close(fd[0]);
}

int	wrong_pid(void)
{
	write(1, "ERRORPIPE", 10);
	return (-1);
}

int	init_child(t_input *input, t_exe_locals	*locals, t_env2 **env2, int fd[2])
{
	exec_redir(input, locals, 1);
	handle_child_fds(locals, fd);
	return (child_proc(input, locals, env2));
}

int	redir_routine(t_input *input, t_exe_locals *locals, int set)
{
	if (input->operator->redir_type == INFILE)
	{
		if (redirct_stdin(input, locals, set) == 0)
			return (1);
	}
	else if (input->operator->redir_type == HEREDOC)
	{
		if (redirct_std_type_in(input, locals, set) == 0)
			return (1);
	}
	else if (input->operator->redir_type == OUT_TRUNCATE)
	{
		if (redirct_trunc(input, locals, set) == 0)
			return (1);
	}
	else if (input->operator->redir_type == OUT_APPEND)
	{
		if (redirct_app(input, locals, set) == 0)
			return (1);
	}
	return (0);
}
