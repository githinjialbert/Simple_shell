#include "main.h"
/**
*bfree - it frees a pointer
*@ptr: address of the ptr
*Return: 0 if successful 1 if otherwise
*/
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
