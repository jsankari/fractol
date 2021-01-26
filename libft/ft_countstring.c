/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsankari <jsankari@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:33:40 by jsankari          #+#    #+#             */
/*   Updated: 2020/10/22 17:00:58 by jsankari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countstring(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}
