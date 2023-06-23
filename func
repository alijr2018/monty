#include "monty.h"

/**
 * _getline - Read line of input from a file stream.
 *
 * @lineptr: Pointer to the buffer where the input will be store.
 * @n: Pointer to the buffer size.
 * @stream: Pointer to the file stream.
 *
 * Return: The number of characters read replacing null terminator with newline
 * Returns -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t i = 0;
	size_t bufsize = 0;
	static char *buf = NULL, c;
	int rd = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);
	while (1)
	{
		if (bufsize - i < BUFSIZE)
		{
			bufsize += BUFSIZE;
			buf = _realloc(buf, bufsize - BUFSIZE, bufsize);
			if (buf == NULL)
				return (-1);
		}

		rd = read(_fileno(stream), &c, 1);
		if (rd == -1)
			return (-1);
		else if (rd == 0)
			break;

		buf[i++] = c;

		if (c == '\n')
			break;
	}
	if (i == 0)
	{
		if (buf)
			free(buf);
		return (-1);
	}
	buf[i] = '\0';
	*lineptr = buf;
	*n = bufsize;

	return (i);
}

/**
 * _fileno - get the file descriptor associated with a stream
 *
 * @stream: pointer to a FILE structure
 * Return: the file descriptor associated with the stream, or -1 on error
 */
int _fileno(FILE *stream)
{
	if (stream == NULL)
		return (-1);

	return (stream->_fileno);
}


