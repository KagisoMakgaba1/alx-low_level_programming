#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_map;

	if (!size)
		return (NULL);

	hash_map = malloc(sizeof(hash_table_t));
	if (hash_map == NULL)
		return (NULL);

	hash_map->size = size;

	hash_map->array = calloc(hash_map->size, sizeof(hash_node_t *));
	if (hash_map->array == NULL)
	{
		free(hash_map);
		hash_map = NULL;
		return (NULL);
	}
	return (hash_map);
}
