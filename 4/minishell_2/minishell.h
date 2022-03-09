/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkolle <nkolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:54:19 by nmichael          #+#    #+#             */
/*   Updated: 2022/03/04 16:02:34 by nkolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
#define MINISHELL

#include "./libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

enum operator {
	NOTHING,
	INFILE, // <
	HEREDOC, // <<
	OUT_TRUNCATE, // >
	OUT_APPEND, // >>
};


typedef struct s_argv_list
{
	char				*content;
	struct s_argv_list	*next;
}	t_argv_list;

typedef struct s_input
{
	char			**cmd;		//cmd
	char			*txt;		//for quoted strings
	int				oprt;		//operator-flag
	struct s_input	*next;		
	char			*file_in;	// file_path
	char			*file_out;	// file_path
}	t_input;

// Lexer

void	save_line(void);
int		main(void);

#endif

// test<test1

// <Makefile echo smtg | echo lal test1 > random_file // split until operator and put the stuff before into a token


// ---------------
// Implement a series of builtins: echo, cd, setenv, unsetenv, env, exit


// Manage the errors without using errno, by displaying a message adapted to the error output 


// if (str[i] == "<")
// 	str[i] = oprt
// < > << >> | 


// Can only use these standard library functions:
// malloc, free
// access
// open, close, read, write
// opendir, readdir, closedir
// getcwd, chdir
// stat, lstat, fstat
// fork, execve
// wait, waitpid, wait3, wait4
// signal, kill
// exit

// values


// oper