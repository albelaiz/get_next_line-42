/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:09:52 by albelaiz          #+#    #+#             */
/*   Updated: 2024/12/13 10:46:57 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *get_next_line(int fd)
{
	static char  *copy;
	if (fd < 0 || BUFFER_SEZE <= 0 || raed(fd,0,0) <= 0)
	{
		return(NULL);
	}
}