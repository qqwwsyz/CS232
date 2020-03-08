#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task2
    node_t * head ;

    struct snode *node1 = NULL;
    struct snode *node2 = NULL;
    struct snode *node3 = NULL;
    head = NULL;
    node1 = (struct snode *)malloc(sizeof(node_t));
    node2 = (struct snode *)malloc(sizeof(node_t));
    node3 = (struct snode *)malloc(sizeof(node_t));

    head = node1;

    strcpy(node1->str, "hello");
    node1->length = 5;
    node1->next = node2;
    strcpy(node2->str, "there");
    node2->length = 5;
    node2->next = node3;
    strcpy(node3->str, "prof");
    node3->length = 4;
    node3->next = NULL;

   return head;
}

void teardown(node_t **head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
	struct snode * temp = *head;
	while(*head != NULL){
	temp = *head;
	*head = (*head)->next;
	free(temp);
	}
}

void add(node_t ** head, char * str, int length){
    //TODO: copy add func from task2

    struct snode *newNode = NULL;
    newNode = (struct snode *)malloc(sizeof(node_t));
    strcpy(newNode->str, "hi");
    newNode->length = 2;
    newNode->next = (*head);
    (*head) = newNode;
}
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
	struct snode *traverse = *head;
	int count = 0;
	if(count == idx){
		*head = traverse->next;
		free(traverse);
		return;
	}
	while(traverse != NULL && count < idx - 1){
		traverse = traverse->next;
		count++;
	}
	struct snode * temp = traverse->next->next;
	free(traverse->next);
	traverse->next = temp;
	free(traverse);
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
	struct snode *traverse = *head;
	struct snode *previous = NULL;
	while(traverse != NULL && strcmp(traverse->str, key) != 0){
		previous = traverse;
		traverse = traverse->next;
	}	
	if(traverse == NULL)
	return;
	previous->next = traverse->next;
	free(traverse);
}
//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(&head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
