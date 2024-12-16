/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Read a line from a file.                                               */
/* ************************************************************************** */
#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

// Buffer

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60 // BUFFER_MIN = 50 | BUFFER_MAX = 100
# endif

// Structure

typedef struct s_buf
{
	char	buffer[BUFFER_SIZE];
	int		buf_read;
	int		buf_pos;
}	t_buf;

// ft_get_next_line.c

char	*get_next_line(int fd);
int		ft_read_buffer(t_buf *buf, int fd);

#endif
