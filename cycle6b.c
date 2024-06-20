#include<stdio.h>
#include<conio.h>
void main()
{
    int nort,nopro,avail[20],req[20][20],i,j,k,flag=0;
    printf("\n enter the no of resource types:");
    scanf("%d",&nort);
    printf("\n enter the no of instances of each resource type:");
    for(i=0;i<nort;i++)
    {
        scanf("%d",&avail[i]);
        printf("\n enter the no of processes:");
        scanf("%d",&nopro);
        printf("\n enter the requests of each process:");
        for(i=0;i<nopro;i++)
            for(j=0;j<nort;j++)
                scanf("%d",&req[i][j]);
                for(i=0;i<nopro;i++)
                {
                    flag=0;
                    for(j=0;j<nort;j++)
                    {
                        if(req[i][j]>avail[j])
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        printf("\n resources for process p%d cannot be allocated to prevent deadlock",i);
                    }
                    else
                    {
                        for(k=0;k<nort;k++)
                        {
                            avail[k]=avail[k]-req[i][k];
                            printf("\n%d instances of resource type R%d are allocated to process P%d",req[i][k],k,i);
                        }
                    }
                }
                printf("\n remaining resources after allocation are");
                for(i=0;i<nort;i++)
                printf("\n %d",avail[i]);
            }
}
