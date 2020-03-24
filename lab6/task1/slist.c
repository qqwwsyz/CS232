#include <stdio.h>
#include "snode.h"
#include "slist.h"
#include <string.h>
#include <stdlib.h>

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
struct slist *slist_create(){
	struct slist * my_list = (struct slist*)malloc(sizeof(struct slist));
	return my_list;
}

/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */

struct snode* slist_add_back(struct slist *l, char *str){
	struct snode * p = snode_create(str);
	if(l->front == NULL && l->back == NULL){
	l->front = p;
	l->back = p;
        l->size++;
	}else{
	l->back->next = p;
	l->back = p;
        l->size++;
	}	
	return p;
}

/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str){
	struct snode * p = snode_create(str);
	p->next = l->front;
	l->front = p;
        l->size++;
	return p;
 
}

/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str){
        int temp_size2 = 1;
	struct snode *search = l->front;
	while(search != NULL && strcmp(search->str, str) != 0){
		search = search->next;
                temp_size2++;
	}	
	if(search == NULL)
	return 	NULL;
	return search;
}

/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(struct slist *l){
	struct snode * temp = l->front;
	while(temp->next != NULL){
	temp = l->front;
	l->front = l->front->next;
	snode_destroy(temp);

	}
l->size = 0;
	
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
        int temp_size = 1;
	struct snode * temp = l->front;
	while(temp != NULL){
	printf("%s , %d/n", temp->str, (int)strlen(temp->str));
	temp = temp->next;
        temp_size++;
	}while(temp_size <= l->size);
}

/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
	return l->size;
}
/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_delete(struct slist *l, char *str){
	struct snode *temp = l->front;
	struct snode *previous = NULL;
	while(temp != NULL && strcmp(temp->str, str) != 0){
		previous = temp;
		temp = temp->next;
	}	
	if(temp == NULL)
	return NULL;
	previous->next = temp->next;
	//free(temp);
	return temp;
}
