/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:41:54 by zalaksya          #+#    #+#             */
/*   Updated: 2025/04/18 12:45:18 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H


#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "readline/readline.h"
#include "readline/history.h"

typedef enum e_token_type
{
	WORD,
	PIPE,
	R_OUT,
	R_IN,
	AEPPEND,
	HERDOK
}	t_token_type;

typedef struct s_token {
    t_token_type type;
    char *value;
} t_token;

typedef struct s_shell
{
	t_token *type;	
} t_shell;

char	**ft_split(char const *s);
int	ft_strcmp(char *s1, char *s2);

#endif