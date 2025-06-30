/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:45:55 by krepo             #+#    #+#             */
/*   Updated: 2025/06/26 15:36:08 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char *str, char c);
static char		*ft_get_next_word(char *str, char c);

char	**ft_split(char *str, char c)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	word_count = ft_count_words(str, c);
	if (!word_count)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!result)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = ft_get_next_word(str, c);
	}
	result[i] = NULL;
	return (result);
}

static int	ft_count_words(char *str, char c)
{
	int	count;
	bool	in_word;

	count = 0;
	while (*str)
	{
		in_word = false; 
		while (*str == c)
			str++;
		while(*str != c && *str)
			if (!in_word)
			{
				count++;
				in_word = true;
			}
		str++;
	}
	return (count);
}

static char	*ft_get_next_word(char *str, char c)
{
	static int	position;
	char		*next_word;
	int			len;
	int			i;
	
	position = 0;
	len = 0;
	i = 0;
	while (str[position] == c)
		position++;
	while ((str[position + len] != c) && str[position + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((str[position] != c) && str[position])
		next_word[i++] = str[position++];
	next_word[i] = '\0';
	return (next_word);
}
