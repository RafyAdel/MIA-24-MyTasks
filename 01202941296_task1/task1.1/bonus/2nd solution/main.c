#include <stdio.h>
#include <stdlib.h>


int main()
{
    int row=1;
    switch(row)
    {
    case 1:
        for(int i=0;i<5;i++)printf("*");
        printf("\t");
        for(int i=0;i<4;i++)printf("*");
        for(int i=0;i<2;i++)printf(" ");
        printf("\t");
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("*\n");
    case 2:
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("\t");
        printf("*");
        for(int i=0;i<3;i++)printf(" ");
        printf("*");
        printf("\t");
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("*\n");
    case 3:
        printf("*");
        for(int i=0;i<2;i++)printf(" ");
        for(int i=0;i<2;i++)printf("*");
        printf("\t");
        for(int i=0;i<5;i++)printf("*");
        printf("\t");
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("*\n");
    case 4:
        printf("*");
        for(int i=0;i<3;i++)printf(" ");
        printf("*");
        printf("\t");
        printf("*");
        for(int i=0;i<3;i++)printf(" ");
        printf("*");
        printf("\t");
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("*\n");
    case 5:
        for(int i=0;i<5;i++)printf("*");
        printf("\t");
        printf("*");
        for(int i=0;i<4;i++)printf(" ");
        printf("*");
        printf("\t");
        for(int i=0;i<6;i++)printf("*");

    }
    return 0;
}
