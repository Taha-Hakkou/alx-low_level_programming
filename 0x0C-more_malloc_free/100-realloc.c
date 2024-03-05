#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 * Return: the reallocated space with memory copied from ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *alloc;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	alloc = malloc(new_size);
	memcpy(alloc, ptr, new_size > old_size ? old_size : new_size);
	if (new_size > old_size)
		memset((char *)alloc + old_size, 0, new_size - old_size);
	free(ptr);
	return (alloc);
}
