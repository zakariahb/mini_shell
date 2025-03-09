/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:49:50 by zalaksya          #+#    #+#             */
/*   Updated: 2025/03/09 10:56:17 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int find_qoute(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == c)
		{
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

	i = 0;
	while(ar[i])
	{
		printf("ar[%d]	:%s\n", i, ar[i]);
		if (find_qoute(ar[i], '\'') || find_qoute(ar[i], '\"') || !ft_strcmp(ar[i], "<>") || !ft_strcmp(ar[i], "|||"))
			return (1);
		i++;
	}
	return (0);
}
int main (void)
{
	char *line = NULL;
	line = readline("mini_shell>");
	char **ar = ft_split(line ,' ');
	if (check_user_input(ar))
		return (write(2, "Error\n", 6),  1);
	return (0);
}
