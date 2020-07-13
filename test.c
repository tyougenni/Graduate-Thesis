//
//  test.c
//  
//
//

#include <stdio.h>
#include <string.h>
int main(){
    int i = 0;
    char password[10]={0};
    for(i=0;i<3;i++)
    {
        scanf("%s",password);
        if(strcmp("123456",password)==0)
        {
            printf("yes\n");
        }else
        {
            printf("yes\n");
        }
    }
    return 0;
}
