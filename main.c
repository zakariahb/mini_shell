/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:49:50 by zalaksya          #+#    #+#             */
/*   Updated: 2025/04/18 12:45:07 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
// typedef enum e_token_type
// {
// 	WORD,
// 	PIPE,
// 	R_OUT,
// 	R_IN,
// 	AEPPEND,
// 	HERDOK,
// }	t_token_type;

// typedef struct s_token {
//     t_token_type type;
//     char *value;
// } t_token;

// typedef struct s_shell
// {
// 	t_token *type;	
// } t_shell;

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// void create_tokens(t_shell *input, char *str)
// {
// 	if (!ft_strcmp(input->type, "PIPE"))
// 		input->type->value = ft_strdup;
	
// }
// void tokenazation(char *str, t_shell *input)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
//while(str[i] && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'))
//	i++;
//if (str[i] == '|')
//	create_tokens(PIPE, "|");
//else if (str[i] == '>' && str[i + 1] == '>')
//	create_tokens(AEPPEND, ">>");
//else if (str[i] == '<' && str[i + 1] == '<')
//	create_tokens(HERDOK, "<<");
//else if (str[i] == '>')
//	create_tokens(R_OUT, ">");
//else if (str[i] == '<')
//	create_tokens(R_IN, "<");
//else		
// 	}	
// }
void parsing(char *line)
{
	
		printf("line :%s\n",line);
}
int main (void)
{
	// t_shell *input = malloc(sizeof(t_shell));
	char *line = NULL;
	while ((line = readline("shell> ")))
	{
		add_history(line);
		parsing(line);
	}
	char **ar = ft_split(line);
	// create_tokens(line, input);
	// char **ar = ft_split(line ,'|');
	// if (check_user_input(ar))
	// 	return (1);
	return (0);
}
