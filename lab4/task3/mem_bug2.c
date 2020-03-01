#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int i, *a;

  a = calloc(10, sizeof(int));


  for(i=0;i <= 10; i++){
    
a[i] = i;
  free(a);
    return 0;  
  }
  for(i=0;i <= 10; i++){
    
    printf("%d\n", a[i]);

      free(a);
      return 0;
  }


}
