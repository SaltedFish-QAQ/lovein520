#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static loveNumber people[] = {
    0, "天天",
    1, "凛薇",
    2, "木里",
    3, "基佬特",
    4, "叶空",
    5, "天子",
    6, "独角兽",
    7, "随心",
    8, "日文名字不认识",
    9, "咕咕",
    10, "小咸鱼",
    11, "小圆",
    12, "桂马",
    13, "瓶子",
    14, "火腿",
    15, "静",
    16, "川",
    17, "975",
    18, "阿索",
    19, "盐酥",
    20, "青菜",
};

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

    srand((unsigned)time(NULL));
    a = rand() % 5;

    loveFunPtr = loveFun[a];
    loveFunPtr(lovePtr);

}

void PrintfFirstLove(loveNumber * ptr)
{
    printf("%s顿首\n见字如面,数年未见想必你当安好.这次没有别的事。只是想你了。。。\n%s敬上\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfSecondLove(loveNumber * ptr)
{
    printf("%s您好\n你我相识三载有余，如今天各一方，各自安好。望你进来安康，如意。有些许讲不完的话，下次会面当面讲罢。\n%s书\n", lovePtr->dataptr, singlePtr->dataptr);
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
