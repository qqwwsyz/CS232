/* Overwrites an inputted string with 232 is awesome! if there is room.
 * * Does nothing if there is not. */
#include <stdlib.h>
#include <stdio.h>
void CS232(char *src, int len) {
     char *srcptr, *replaceptr; 
     // char *srcptr, *replaceptr;
     char replacement[15] = "232 is awesome!";
     srcptr = src;
     replaceptr = replacement;
     if (len >= 15) {
         for (int i = 0; i < 15; i++)
	      *srcptr++ = *replaceptr++;
     }
}

char * replace_string() {
    char *str = (char*)malloc(15 * sizeof(char));
    CS232(str, 15);
    return str;
}

int main(int argc, char ** argv) {
    char * ret = replace_string();
    printf("replaced string = %s\n", ret);
    return 0;
}
