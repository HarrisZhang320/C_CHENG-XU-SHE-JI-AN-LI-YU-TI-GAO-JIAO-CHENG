int main()
{int a[11] = {-2,0,3,8,11,15,17,20,24,32};
 int x, i, k;
 scanf("%d", &x);
 for(i = 9; i>=0 && a[i]>x; i--)
   a[i+1] = a[i];
 a[i+1] = x;

 for(i = 0; i<=10; i++)
   printf("%5d", a[i]);
 printf("\n");
 getch();
 return 0;
}
