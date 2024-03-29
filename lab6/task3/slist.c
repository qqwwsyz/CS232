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
	my_list->front = NULL;
	my_list->back = NULL;
	my_list->size = 0;
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
	if(l->front == NULL && l->back == NULL){
	l->front = p;
	l->back = p;	
	l->size++;
	}else{
	p->next = l->front;
	l->front = p;
	l->size++;
	}
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
	struct snode *search = l->front;
	while(search != NULL && strcmp(search->str, str) != 0){
		search = search->next;
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
	if(l->front == NULL){
	l = NULL;
	return;
	}	
	struct snode * temp = l->front;
	while(temp->next != NULL){	
	l->front = l->front->next;
	snode_destroy(temp);
	temp = l->front;
	}
	snode_destroy(l->back);
	l->size = 0;
	l = NULL;
	
}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
	struct snode * temp = l->front;
	while(temp != NULL){
	printf("%s , %d/n", temp->str, (int)strlen(temp->str));
	temp = temp->next;
	}
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
	if(l == NULL)
	return NULL;
	struct snode *temp = l->front;
	struct snode *previous = NULL;
	if(temp->next == NULL && strcmp(temp->str, str) == 0){
	snode_destroy(temp);
	l->size = 0;
	l->front = NULL;
	l->back = NULL;
	return NULL;
	}

	//if the first node to delete

	else if(temp!= NULL && strcmp(temp->str, str) == 0){
	l->front = temp->next;
	snode_destroy(temp);
	l->size--;	
	return NULL;
	}

	//find the node
	while(temp != NULL && strcmp(temp->str, str) != 0){
		previous = temp;
		temp = temp->next;
	}	
	if(temp == NULL)
	return NULL;
	previous->next = temp->next;
	snode_destroy(temp);
	l->size--;
	return NULL;
}
struct snode * slist_get_front(struct slist *l){
return l->front;
}
struct snode * slist_get_back(struct slist *l){
return l->back;
}
struct snode *slist_find_at(struct slist *list, int index){
struct snode *temp = list->front;
	int count = 0;
	if(index < 0)
	count = 0 - list->size;

	while(temp!= NULL && index != count){
		temp = temp->next;
		count++;
		}
	return temp;
}

void slist_delete_at(struct slist *list, int index){
	if(list == NULL)
	return;
	struct snode *temp = list->front;
	struct snode *previous = NULL;
	int count = 0;
	if(index < 0)
	count = 0 - list->size;


	if(temp->next == NULL && count == index){
	snode_destroy(temp);
	list->size = 0;
	list->front = NULL;
	list->back = NULL;
	return;
	}


	else if(temp!= NULL && count == index){
	list->front = temp->next;
	snode_destroy(temp);
	list->size--;	
	return;
	}

	//find the node
	while(temp != NULL && count != index){
		previous = temp;
		temp = temp->next;
		count++;
	}	
	if(temp == NULL)
	return;
	previous->next = temp->next;
	snode_destroy(temp);
	list->size--;
	return;

}

