*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c;

  printf("Enter radius (in mm):\n");
  scanf("%f", &r);

  while (r != 0) {
    r = r / 25.4;
    a = r * r *PI;
    c = r * 2 * PI;

    printf("Circle's area is %3.2f (sq in).\n", a);
    printf("Its circumference is %.2f (in)\n", c);

    printf("Enter radius (in mm):\n");
    scanf("%f", &r);
  }
}
