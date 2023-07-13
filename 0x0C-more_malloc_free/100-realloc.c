#include "main.h"
/**
 * _realloc - 
 * @ptr: 
 * @old_size: 
 * @new_size: 
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (ptr != NULL && new_size == 0)
		free(ptr);
	free(ptr);
	return (ptr);
}
