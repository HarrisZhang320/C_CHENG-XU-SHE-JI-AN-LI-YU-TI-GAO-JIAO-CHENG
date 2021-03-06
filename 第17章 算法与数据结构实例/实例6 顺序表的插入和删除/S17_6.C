#define ListSize 10    /* 假定表空间大小为100 */
#include <stdio.h>
#include <stdlib.h>

void Error(char * message)
{
 printf("Error:%s\n",message);
 exit(1);
}

struct Seqlist{
  int  data[ListSize];/* 向量data用于存放表结点 */
  int length; /*  当前的表长度 */
};

/* ------------以下为两个主要算法---------- */
void InsertList(struct Seqlist *L, int x, int i)
{
 /* 将新结点x插入L所指的顺序表的第i个结点ai的位置上 */
 int j;
 if ( i < 0 || i > L -> length )
   Error("position error");/* 非法位置，退出 */
 if ( L->length>=ListSize )
   Error("overflow");
 for ( j=L->length-1 ; j >= i ; j --)
   L->data[j+1]=L->data [j];
 L->data[i]=x ;
 L->length++ ;
}

void DeleteList ( struct Seqlist *L, int i )
{/* 从L所指的顺序表中删除第i个结点ai */
 int j;
 if ( i< 0 || i > L-> length-1)
   Error( " position error" ) ;
 for ( j = i+1 ; j < L-> length ; j++ )
    L->data [ j-1 ]=L->data [ j]; /* 结点前移 */
 L-> length-- ; /* 表长减小 */
}

/* ===========以下为验证算法而加======= */
void Initlist(struct Seqlist *L)
{
 L->length=0;
}

int main()
{struct Seqlist *SEQA;
 int i;
 SEQA = (struct Seqlist *)malloc(sizeof(struct Seqlist));
 if(!SEQA)
	 Error("no space.\n");
 Initlist(SEQA);
 for (i=0;i<ListSize;i++)
   {InsertList (SEQA,i*10,i);
    printf("%3d",SEQA->data[i]);
   }
 printf("\n");
 DeleteList(SEQA,9);
 DeleteList(SEQA,0);
 DeleteList(SEQA,5);
 for (i=0;i<SEQA->length;i++)
    printf("%3d",SEQA->data[i]);
 printf("\n");
 InsertList (SEQA, 1, 0);
 InsertList (SEQA, 2, 3);
 InsertList (SEQA, 3, 9);
 for (i=0;i<SEQA->length;i++)
    printf("%3d",SEQA->data[i]);
 free(SEQA);
 getch();
 return 0;
}