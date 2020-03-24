#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _snode_H_
#define _snode_H_

struct snode {
  char *str;
  struct snode *next;
};

struct snode *snode_create(char *s) ; 
void snode_destroy(struct snode * s) ;
char *snode_get_str(struct snode * s);
struct snode *snode_get_next(struct snode * s); 
#endif 
