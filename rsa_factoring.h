#ifndef _RSA_FACTOR_
#define _RSA_FACTOR_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

unsigned long max;

typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

int stoi(char *str, unsigned long *array);
char *itos(unsigned long *array, int len);
int add(unsigned long *trial, unsigned long *root, int lr, unsigned long *bit, int lb);
int add_by_n(unsigned long *arr, int arr_len, unsigned long num);
int cmp(unsigned long *arr1, int l1, unsigned long *arr2, int l2);
int mul(unsigned long *ret_num, unsigned long *arr1, int l1,  unsigned long *arr2, int l2);
int div_by_n(unsigned long *arr, int len_num, int n);
int sub(unsigned long *ret_num, unsigned long *arr1, int l1, unsigned long *arr2, int l2);
int mul_by_n(unsigned long *ret_num, unsigned long * arr, int len, unsigned long num);
int _mod(unsigned long *ret_num, unsigned long *arr1, int l1,  unsigned long *arr2, int l2);
int _div(unsigned long *ret_num, unsigned long *arr1, int l1,  unsigned long *arr2, int l2);
int div_by_2(unsigned long *arr, int len_num);
void root(unsigned long *array, int arr_len, unsigned long *root, int *len_root);
int check_prime(unsigned long *num, int len, unsigned long *temp, int temp_len);
int prime_ret(char *str_num, unsigned long *ret_num);

/* for updating prime number in hash table */
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
char *hash_table_get(const hash_table_t *ht, const char *key);
int hash_table_check(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);

#endif
