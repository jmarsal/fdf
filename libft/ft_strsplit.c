/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:31:37 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 11:11:43 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne un tableau de chaines de caractères
**	“fraiches” (toutes terminées par un ’\0’, le tableau également donc)
**	résultant de la découpe de s selon le caractère c. Si l’allocation
**	echoue, la fonction retourne NULL.
**	Exemple : ft_strsplit("*salut*les***etudiants*", ’*’)
**	renvoie le tableau ["salut", "les", "etudiants"].
*/

static size_t	how_many_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			j++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char		*take_word_in_str(size_t *pointeur_i, char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = *pointeur_i;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	new_str = ft_strnew(len - *pointeur_i);
	if (new_str)
	{
		while (*pointeur_i < len)
		{
			new_str[i] = s[*pointeur_i];
			i++;
			*pointeur_i += 1;
		}
		return (new_str);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	*pointeur_i;
	size_t	j;

	i = 0;
	pointeur_i = &i;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char **)malloc(sizeof(char *) * (how_many_words(s, c) + 1));
	if (tab)
	{
		while (j < how_many_words(s, c))
		{
			while (s[*pointeur_i] == c)
				*pointeur_i += 1;
			if (s[*pointeur_i] != c && s[*pointeur_i])
				tab[j++] = take_word_in_str(pointeur_i, s, c);
		}
		tab[j] = 0;
		return (tab);
	}
	return (0);
}
