#include <stdio.h>
int main()
{void func(int[]);
 int a[5] = {1,2,3,4,5}, i;
 printf("a��%p\n", a);
 func (a);
 for (i = 0;  i<=4; i++)
   printf("%3d", a[i]);
 printf("\n");
 printf("a��%p\n", a);
 return 0;
}
void func (int x[])
{int i;
 printf("x��%p\n", x);
 for( i = 0; i<=4; i++)
   x[i]++;
 x++;
 printf("x��%p\n", x);
}

