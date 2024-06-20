#include<stdio.h>
void main()
{
    int available[3],work[5],max[5][3],allocation[5][3],need[5][3],safe[5],totalres[5];
    char finish[5];
    int i,j,k,totalloc=0,state,value=0;
    printf("Enter Instances of each Resource");
    for(i=0;i<3;i++)
    {
        scanf("%d",&totalres[i]);
    }
    printf("Enter Maximum resources for each processes:");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\n Enter process %d Resource %d:",i,(j+1));
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter number of resources allocated to each Process");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\n Enter the resource of R%d allocated to process %d:",(j+1),i);
            scanf("%d",&allocation[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        finish[i]='f';
    }
    for(i=0;i<3;i++)
    {
        totalloc=0;
        for(j=0;j<5;j++)
        {
            totalloc=totalloc+allocation[j][i];
        }
        available[i]=totalres[i]-totalloc;
        work[i]=available[i];
    }
    printf("\n Allocated Resources \n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n Maximum Resources \n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",max[i][j]);
        }
        printf("\n");
    }
    printf("\n Needed Reources \n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    printf("\n Available Reources");
    for(i=0;i<3;i++)
    {
        printf("%d",available[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            if((finish[i]=='f')&&(need[i][j]<=work[j]))
            {
                state=1;
                continue;
            }
            else
            {
                state=0;
                break;
            }
        }
        if(state==1)
        {
            for(j=0;j<3;j++)
            {
                work[j]=work[j]+allocation[i][j];
            }
            finish[i]='t';
            safe[value]=i;
            ++value;
        }
        if(i==4)
        {
            if(value==5)
            {
                break;
            }
            else
            {
                i=-1;
            }
        }
    }
    printf("\n Safe States are");
    for(i=0;i<5;i++)
    {
        printf("P%d",safe[i]);
    }
}
