#include "rsa_factoring.h"

/**
 * key_index - Entry point
 * Description: return index of key
 * @key: key
 * @size: size of the array
 * Return: index of the key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2((unsigned char *)key) % size);
}

/**
 * hash_djb2 - djb2 algorithm
 * @str: input data
 *
 * Return: coded number.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * hash_table_create - Entry point
 * Description: Create a new hash table
 * @size: size of the array
 * Return: pointer newly created hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hashtb = NULL;
	unsigned long int i = 0;

	hashtb = malloc(sizeof(hash_table_t));
	if (!hashtb)
		return (NULL);
	hashtb->array = malloc(sizeof(hash_node_t *) * size);
	if (!(hashtb->array))
	{
		free(hashtb);
		return (NULL);
	}
	for (; i < size; i++)
		hashtb->array[i] = NULL;
	hashtb->size = size;
	return (hashtb);
}

/**
 * hash_table_get - Entry point
 * Description: retrieves a value associated with a key
 * @key: key
 * @ht: hash table
 * Return: value
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *curr;

	if (!ht || !key || strlen(key) == 0)
		return (NULL);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx])
	{
		for (curr = ht->array[idx]; curr; curr = curr->next)
		{
			if (strcmp(curr->key, key) == 0)
				return (curr->value);
		}
	}
	return (NULL);
}

/**
 * hash_table_check - Entry point
 * Description: retrieves a value associated with a key
 * @key: key
 * @ht: hash table
 * Return: value
 */

int hash_table_check(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *curr;

	if (!ht || !key || strlen(key) == 0)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	if (!ht->array[idx])
		return (1);
	else
	{
		for (curr = ht->array[idx]; curr; curr = curr->next)
		{
			if (strcmp(curr->key, key) == 0)
				return (0);
		}
	}
	return (1);
}

/**
 * hash_table_set - Entry point
 * Description: adds an element to the hash table
 * @key: key
 * @ht: hast table
 * @value: value
 * Return: index of the key
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *hnode;

	if (!ht || !key || !*key || !value)
		return (0);
	idx = key_index((unsigned char *)key, ht->size);
	if (ht->array[idx])
	{
		for (hnode = ht->array[idx]; hnode; hnode = hnode->next)
		{
			if (strcmp(hnode->key, key) == 0)
			{
				free(hnode->value);
				hnode->value = strdup(value);
				return (1);
			}
		}
	}
	hnode = malloc(sizeof(hash_node_t));
	if (!hnode)
		return (0);
	hnode->key = strdup(key);
	hnode->value = strdup(value);
	hnode->next = ht->array[idx];
	ht->array[idx] = hnode;
	return (1);
}

/**
 * hash_table_print - Entry point
 * Description: prints a hash table in the order that they appear
 * @ht: hash table
 * Return: nothing
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	int sign = 0;
	hash_node_t *curr;

	if (!ht)
		return;
	printf("{");
	for (idx = 0; idx < ht->size; idx++)
		if (ht->array[idx])
		{
			for (curr = ht->array[idx]; curr; curr = curr->next)
			{
				if (sign == 0)
				{
					printf("'%s': '%s'", curr->key, curr->value);
					sign = 1;
				}
				else
					printf(", '%s': '%s'", curr->key, curr->value);
			}
		}
	printf("}\n");
}
