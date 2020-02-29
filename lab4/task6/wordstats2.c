#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int frequency[7] = {0};
  int len, i;
  char buf[MAX_BUF];

  do {
    fgets(buf, MAX_BUF, stdin);
    len = strlen(buf);

        for(int i=0; i<len; i++){
           if (buf[i]>= 'A' && buf[i]<= 'Z'){
  //upper case: total charactor++ and upper case++
              frequency[0]++;
         frequency[4]++;
    }else if (buf[i]>= 'a' && buf[i]<= 'z'){
  //lower case: total charactor++ and lower case++
              frequency[0]++;
    frequency[5]++;
    }else if (buf[i] == ' ' || buf[i] == '\t'){
  //space and tab: total charactor++, white space++ and words++
  frequency[0]++;
  frequency[1]++;
  frequency[3]++;
    }else if(buf[i] == '\n'){
  //new line: total charactor++, words++, lines++
  frequency[0]++;
  frequency[1]++;
  frequency[2]++;
    }else if(buf[i]>= '0' && buf[i] <= '9'){
  //digits: total charactor++, digits++
  frequency[0]++;
  frequency[6]++;
           }
}

  } while (len > 1);
 //we should ignore the last \n charactor in inputs so:
 frequency[2]--;
 frequency[1]--;

  for (i = 0; i < 7; i++) {
 printf("%d ", frequency[i]);
  }
}
