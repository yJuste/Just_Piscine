/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Read a line from a file.                                               */
/* ************************************************************************** */
#include "../includes/main.h"
#include "../includes/ft_get_next_line.h"

// --------------------PROTOTYPE-------------------
char	*ft_get_next_line(int fd);
int		ft_read_buffer(t_buf *buf, int fd);
// ------------------------------------------------

char	*ft_get_next_line(int fd)
{
	static t_buf	buf;
	char			line[50000];
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf.buf_pos >= buf.buf_read)
		{
			if (ft_read_buffer(&buf, fd) == -1)
				return (NULL);
			if (buf.buf_read == 0)
				break ;
		}
		line[i++] = buf.buffer[buf.buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	ft_read_buffer(t_buf *buf, int fd)
{
	buf->buf_read = read(fd, buf->buffer, BUFFER_SIZE);
	buf->buf_pos = 0;
	if (buf->buf_read == -1)
	{
		buf->buf_read = 0;
		buf->buf_pos = 0;
		return (-1);
	}
	return (buf->buf_read);
}
