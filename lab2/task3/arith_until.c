#include <stdio.h>
#define PI 3.14159


int main()
{
  float r, a, b, c;

  printf("Enter radius (in mm):\n");
  scanf("%f", &r);
if (r!=0){
  b = r *0.0393700;
  a = PI * b * b  ;

  printf("Circle's area is %3.2f (sq in).\n", a);
  c = 2 * PI * b;
  printf("Its circumference is %3.2f (in).\n", c);
}
  else{
  printf("Exit\n");
}

}
