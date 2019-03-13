#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter integer value: ");
    scanf("%d", &n);
    int row,col;

    if(n<1) //|| n>9)
    {
        printf("Enter a value greater that 0");
        return 0;
    }


    for(i=1; i<=n; i++)
    {
        printf("\t%d", i);
    }
    printf("\n\t+");
    for(i=1;i<(n*8);i++)
    {
        printf("-");
    }
    printf ("\n");

    for (row=1; row<=n;row++)
    {

        printf("%d\t|", row);
        for(col=1; col<=n;col++)
        {
            printf("%d\t", col*row);
        }

        if (row!=n)
            printf("\n");
    }
    printf("\n");
    return 0;
}
