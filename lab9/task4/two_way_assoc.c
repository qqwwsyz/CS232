#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )
{
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while (fscanf(fp, "%x", &addr) > 0) {
        /********* YOUR CODE HERE ************/

      accesses++;
      int ind = (addr>>2)&3;
      int n;
      int taag = addr | 0xf;
  
  
     for(n=0; n<2; n++){
  if(tag[ind][n] == taag){
  printf("Oh it is a hit");
       mru[ind] = n;
       hits++;
       break;
    }
}
  if ( n ==2){
    printf("Oh it is a miss");
    int x = (mru[ind] + 1)%2;
    tag[ind][x] = taag;
    mru[ind] = x;
}
    for(int k = 0; k <4; k++){
     printf("%d", mru[k]);
    printf("\n");
}
    }
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
