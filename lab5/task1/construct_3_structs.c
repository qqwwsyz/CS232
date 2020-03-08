#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head ;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
    
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
	struct snode *temp = *head;
	struct snode *tempNext = NULL;
	while(temp != NULL){
	tempNext = temp->next;
	free(temp);
	temp = tempNext;
	}
	*head = NULL;
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
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
