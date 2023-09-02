#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start;
    printf("how many seconds will the expedition launched after?\n");
    scanf("%d",&start);
    for(int i=start;i>0;i--){printf("%d\n",i);sleep(1);}
    printf("blast off to the moon!!");
    return 0;
}
