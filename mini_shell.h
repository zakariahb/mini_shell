/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:41:54 by zalaksya          #+#    #+#             */
/*   Updated: 2025/03/09 14:41:45 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H


#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "readline/readline.h"

typedef struct s_shell
{
	int pipe;
	int	or;
	int o_prts;
	int c_prts;
	int s_qoute;
	int d_qoute;
	
} t_shell;

char	**ft_split(char const *s, char c);

#endif