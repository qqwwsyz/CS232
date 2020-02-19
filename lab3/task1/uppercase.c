#include <stdio.h>
#include<string.h>


int main(int argc, char *argv[]) {

 char str[25];
   int ch, n=0;

   while ((ch = getchar()) != EOF ) {
      str[n] = ch;
      ++n;
   }
  for (int i = 0; i<=strlen(str);i++) 
{
    if ((str[i] >= 97) && (str[i] <= 122)) 
        str[i] = str[i]-32;      
        
  
}                                
printf("\nUpper Case String is: %s",str);

   return 0;
}

