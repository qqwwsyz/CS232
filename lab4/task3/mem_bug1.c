/*memleak_example.c*/
#include <stdio.h>
#include <stdlib.h>


/*1. Definitly lost 32 bytes.
  2. Line_  int * a = malloc(sizeof(int *));
     Line_  a = calloc(3, sizeof(int *));
  3. 8 bytes in int * a = malloc(sizeof(int *));
     24 bytes in a = calloc(3, sizeof(int *));
  4. By adding free(a). 
*/

int main(int argc, char * argv[]){

  int * a = malloc(sizeof(int *));

  *a = 10;  
   
  free(a);
  printf("%d\n", *a);

  a = calloc(3, sizeof(int *));
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;
free(a);
  
  printf("%d %d %d\n", a[0], a[1], a[2]);
}
