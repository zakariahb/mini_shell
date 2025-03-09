/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalaksya <zalaksya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:41:54 by zalaksya          #+#    #+#             */
/*   Updated: 2025/03/09 07:52:35 by zalaksya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
#define MINI_SHELL_H


#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "readline/readline.h"

char	**ft_split(char const *s, char c);

#endif