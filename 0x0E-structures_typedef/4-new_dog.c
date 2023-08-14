#include <stdlib.h>
#include "dog.h"

/**
*new_dog - creates a new dog
*@name: name of dog
*@age: age of dog
*@owner: onwer's name
*
*Return: NULL if functions fails
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	int name1 = 0, owner1 = 0, c;
	dog_t *dog2;

	while (name[name1] != '\0')
		name1++;

	while (owner[owner1] != '\0')
		owner1++;

	dog2 = malloc(sizeof(dog_t));

	if (dog2 == NULL)
	{
		free(dog2);
		return (NULL);
	}

	dog2->name = malloc(name1 * sizeof(dog2->name));

	if (dog2->name == NULL)
	{
		free(dog2->name);
		free(dog2);
		return (NULL);
	}
	for (c = 0; c <= name1; c++)
		dog2->name[c] = name[c];

	dog2->age = age;
	dog2->owner = malloc(owner1 * sizeof(dog2->owner));
	if (dog2->owner == NULL)
	{
		free(dog2->owner);
		free(dog2->name);
		free(dog2);
		return (NULL);
	}
	for (c = 0; c <= owner1; c++)
		dog2->owner[c] = owner[c];
	return (dog2);
}
