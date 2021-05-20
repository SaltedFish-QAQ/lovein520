#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static loveNumber people[256];

static printfLove loveFun[] = {
    PrintfFirstLove,
    PrintfSecondLove,
    PrintfThridLove,
    PrintfFourLove,
    PrintfFiveLove,
};

static loveNumber * lovePtr = NULL;
static loveNumber * singlePtr = NULL;
static printfLove loveFunPtr = NULL;

static int getNumber(char * buff)
{
    char ptr[4];
    int i = 0;
    int number = 0;
    for(i; i < 4; i++)
    {
        if(buff[i] == ' ')
        {
            break;
        }
    }
    memcpy(ptr, buff, i);
    number = atoi(ptr);
    memmove(buff, &buff[i+1], 256 - (i + 1));
    return number;
}

static void getString(char * buff, char * string)
{
    int i = 0;

    for(i; i < 20; i++)
    {
        if(buff[i] == ' ')
        {
            break;
        }
    }
    memcpy(string, buff, i);
    memmove(buff, &buff[i+1], 256 - (i + 1));
}

void numberInit(void)
{
    FILE *fp = NULL;
    char buff[256] = {'\0'};

    fp = fopen("number.txt", "r");
    fgets(buff, 256, fp);
    fclose(fp);

    printf("读取到的群组成员名单如下：\n");
    printf("%s\n", buff);
    for(int i; i < 256; i++)
    {
        if(buff[0] == '\0')
        {
            break;
        }

        people[i].number = getNumber(buff);

        getString(buff, people[i].dataptr);
    }
}

void setSinglePersion(int number)
{
    singlePtr = &people[number];
}

void getLovePersion(void)
{
    int a = 0;

    srand((unsigned)time(NULL));
    a = rand() % 21;

    lovePtr = &people[a];

    if(singlePtr->number == lovePtr->number)
    {
        printf("%d个人随机抽一个都能抽到自己？你丫绝世寡王啊！%s\n", sizeof(people)/sizeof(people[0]), singlePtr->dataptr);
    }
    else
    {
        srand((unsigned)time(NULL));
        a = rand() % 5;

        loveFunPtr = loveFun[a];
        loveFunPtr(lovePtr);
    }
    

}

void PrintfFirstLove(loveNumber * ptr)
{
    printf("%s顿首\n见字如面,数年未见想必你当安好.这次没有别的事。只是想你了。。。\n%s敬上\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfSecondLove(loveNumber * ptr)
{
    printf("%s您好\n你我相识三载有余，如今天各一方，各自安好。望你近来安康，如意。有些许讲不完的话，下次会面当面讲罢。\n%s书\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfThridLove(loveNumber * ptr)
{
    printf("%s,近来安好？\n两情若是久长时，又岂在朝朝暮暮。有缘自会再见。。。\n%s留\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfFourLove(loveNumber * ptr)
{
    printf("%s\n我一生都是一个坚定的唯物主义者，唯有你我希望有来生\n%s\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfFiveLove(loveNumber * ptr)
{
    printf("%s顿首\n快雪时晴，佳想安善。未果为结力不次。%s顿首。\n%s\n", lovePtr->dataptr, lovePtr->dataptr, singlePtr->dataptr);
}
