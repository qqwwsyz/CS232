
#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
	int len = strlen(s) + 1;
	struct snode * my_snode = NULL;
	my_snode = malloc(sizeof(struct snode));
	my_snode->str = (char*)malloc(len * sizeof(char));
	strcpy(my_snode->str, s);
	my_snode->next = NULL;
	return my_snode;  
}
void snode_destroy(struct snode * s) 
{
free(s->str);
free(s);
}

char *snode_get_str(struct snode * s){
return s->str;
}

struct snode *snode_get_next(struct snode * s){
return s->next;
}
