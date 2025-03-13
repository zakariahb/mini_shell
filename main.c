/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:49:50 by zalaksya          #+#    #+#             */
/*   Updated: 2025/03/13 08:57:52 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
typedef enum e_token_type
{
	WORD,
	PIPE,
	R_OUT,
	R_IN,
	AEPPEND,
	HERDOK,
}	t_token_type;

typedef struct s_token {
    t_token_type type;
    char *value;
} t_token;

typedef struct s_shell
{
	t_token *type;	
} t_shell;

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int find_qoute(char *str, t_shell *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|' && str[i + 2] != '|')
		{
			input->or += 1;
			j++;
			if (j == 2)
				return (0);	
		}
		i++;
	}
	if (j == 0)
		return (0);
	return (1);
	
}
int check_user_input(char **ar)
{
	int	i;
	t_shell *input = NULL;
	i = 0;
	while(ar[i])
	{
		printf("ar[%d]	:%s\n", i, ar[i]);
		if (find_qoute(ar[i], input))
			return (1);
		i++;
	}
	return (0);
}

void create_tokens(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while(str[i] && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] == '|')
			ft_strcpy()
		
	}
	
}
int main (void)
{
	char *line = NULL;
	while ((line = readline("shell> ")))
	{
		add_history(line);
	}
	create_tokens(line); 
	printf("line :%s\n",line);
	// char **ar = ft_split(line ,'|');
	// if (check_user_input(ar))
	// 	return (1);
	return (0);
}
