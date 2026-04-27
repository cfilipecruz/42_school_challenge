/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarques <cmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:12:48 by cmarques          #+#    #+#             */
/*   Updated: 2026/02/17 15:58:07 by cmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i] && !is_sep(str[i], charset))
		{
			words++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}
	return (words);
}

int	word_length(char *str, char *charset, int start)
{
	int	len;

	len = 0;
	while (str[start + len] && !is_sep(str[start + len], charset))
		len++;
	return (len);
}

char	*dup_word(char *str, int start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	int		len;
	char	**res;
	int		i;
	int		w;

	words = count_words(str, charset);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	w = 0;
	while (w < words)
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		len = word_length(str, charset, i);
		res[w] = dup_word(str, i, len);
		i += len;
		w++;
	}
	res[w] = NULL;
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**res;
	int		i;

	i = 0;
	res = ft_split("hello!42,world", "!,");
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
}
*/