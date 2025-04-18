/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:28:35 by zalaksya          #+#    #+#             */
/*   Updated: 2025/04/18 15:12:13 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

static char	**ft_free(char **ft_split_res, int count)
{
	while (count--)
	{
		free(ft_split_res[count]);
	}
	free(ft_split_res);
	return (NULL);
}

static size_t	ft_strlenword(char *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++; 
		i++;
	}
	return (len);
}

int ft_find(char c)
{
	char	*str;
	int		i;
	
	i = 0;
	str = " <>|";
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (0);
}
static int	count_word(char const *str)
{
	int	i;
	int	j;
	int	k;
	char *str;
	str = " <>|";
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i] == c))
		{
			j++;
			k = 0;
		}
		else if (k == 0)
		{
			k = 1;
			j++;
		}
		i++;
	}
	return (j);
}
wdwqdwq
static char	*ft_strndup(char const *str, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s)
{
	int		i;
	int		index;
	char	**p;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **)malloc((count_word(s) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	index = 0;
	while (s[i])
	{
		while (s[i])
		{
			if (ft_find(s[i]))
				p[index] = ft_strndup(&s[i], ft_strlenword((char *)&s[i], c));
		}
			i++;
		if (!s[i])
			break ;
		p[index] = ft_strndup(&s[i], ft_strlenword((char *)&s[i], c));
		if (!p[index])
			return (ft_free(p, index));
		i += ft_strlenword((char *)&s[i], c);
		index++;
	}
	p[index] = NULL;
	return (p);
}
