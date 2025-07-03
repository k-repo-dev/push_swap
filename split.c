/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krepo <krepo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:56:03 by krepo             #+#    #+#             */
/*   Updated: 2025/07/03 13:21:55 by krepo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char c);
static char	*get_next_word(char *str, char c, int *pos);

char	**ft_split(char *str, char c)
{
	int		word_count;
	char	**split;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	word_count = count_words(str, c);
	if (!word_count && str[0] == '\0')
		return (NULL);
	if (!word_count && str[0] != '\0')
		exit(1);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	while (i < word_count)
		split[i++] = get_next_word(str, c, &pos);
	split[i] = NULL;
	return (split);
}

static int	count_words(char *str, char c)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*str)
	{
		if (*str == c)
			in_word = false;
		else if (!in_word)
		{
			count++;
			in_word = true;
		}
		str++;
	}
	return (count);
}

static char	*get_next_word(char *str, char c, int *pos)
{
	char	*word;
	int		start;
	int		len;
	int		i;

	i = 0;
	while (str[*pos] == c)
		(*pos)++;
	start = *pos;
	while (str[*pos] && str[*pos] != c)
		(*pos)++;
	len = *pos - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}
