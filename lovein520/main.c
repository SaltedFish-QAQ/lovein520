#include "fun.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
    int number = 0;

    numberInit();
    for(;;)
    {
        printf("请输入你的序列号\n");
        scanf("%d",&number);
        setSinglePersion(number);
        getLovePersion();

        system("pause");
    }
}
