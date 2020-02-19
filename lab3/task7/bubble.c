/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */
int comparison(char *s1, char *s2){
do{
 if(*s1<*s2){
    return 0;
  }else if(*s1>*s2){
 return 1;
 }
 s1++;
 s2++;
  }while(*s1!= '\0');

return 0;
}

void copy(char *src, char *dst) {
do {
*dst++ = *src++;
}while(*src != '\0');
    *dst = *src;
}
int main()
{
  char Strings[NUM][LEN];

  printf("Please enter %d strings, one per line:\n", NUM);
for(int i=0; i<NUM; i++) {
        fgets(Strings[i], LEN, stdin);
    }

  /* Write a for loop here to read NUM strings.
     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");
for(int i = 0; i < NUM; i++) {
        char *n = Strings[i];
        while (*n != '\0') {
            printf("%c", *n++);
        }
    }

    char temp[LEN];
    for(int i = NUM - 1; i > 0; i--) {
        int done = 1;
        for (int j = 0; j < i; j++) {
            if (comparison(Strings[j], Strings[j+1]) == 1) {
                // puts(Strings[j]);
                // puts(Strings[j + 1]);
                copy(Strings[j], temp);
                copy(Strings[j+1], Strings[j]);
                copy(temp, Strings[j+1]);
                done = 0;
            }
        }
        if (done == 1) break;
    }
  /* Write a for loop here to print all the strings. */

  
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order
     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) The swap of two strings must be done by copying them 
            (using a temp variable of your choice) one character at a time,
            without using any C string library functions.
            That is, write your own while/for loop to do this.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */

  
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
for(int i=0; i<NUM; i++) {
  char *n = Strings[i];
   while (*n != '\0') {
      printf("%c", *n++);
        }
    }

    return 0;

}



