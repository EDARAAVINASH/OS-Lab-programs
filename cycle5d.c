#include<stdio.h>
#include<string.h>
struct node
{
    char N[25];
    int df;
    struct node *ptr;
};
struct node *A[20];
int in=0;c=0;
void display()
{
    int i;
    struct node *P;
    for(i=0;i<c;i++)
    {
        P = A[i];
        printf("\n%s(%d)",P->N,P->df);
        P = P->ptr;
        while(P!= NULL)
        {
            printf("->%s(%d)",P->N,P->df);
            P = P->ptr;
        }
    }
}
void DAG()
{
    struct node *T,*P,*Tmp;
    int i,j,Flag,nv;
    for(in=0;in<c;in++)
    {
        P = A[in];
        printf("\n enter no.of adjacent vertices for %s:",A[in]->N);
        scanf("%d",&nv);
        for(i=0;i<nv;i++)
        {
            T = malloc(sizeof(struct node));
            printf("enter name");
            scanf("%s",T->N);
            printf("enter dir(1) or file(0):");
            scanf("%d",&T->df);
            T->ptr = T;
            P=T;
            if(T->df==1)
            {
                Flag = 1;
                for(j=0;j<c;j++)
                {
                    if(strcmp(A[j]->N,T->N)==0)
                    {
                        Flag = 0;
                        break;
                    }
                }
                if(Flag==1)
                {
                    Tmp = malloc(sizeof(struct node));
                    strcpy(Tmp->N,T->N);
                    Tmp->df = T->df;
                    Tmp->ptr = NULL;
                    A[c] = Tmp;
                    c++;
                }
            }
        }
    }
 }
 void create(int N)
 {
    int i;
    struct node *T;
    for(i=0;i<N;i++)
    {
         T = malloc(sizeof(struct node));
         printf("enter name:");
         scanf("%s",T->N);
         printf("enter dir(1) or file(0):");
         scanf("%d",&T->df);
         T->ptr=NULL;
         A[c]=T;
         c++;
    }
}
void main()
{
    int nu;
    printf("enter no.of users:");
    scanf("%d",&nu);
    create(nu);
    DAG();
    printf("\n DAG - adjancey list representation\n");
    display();
}
