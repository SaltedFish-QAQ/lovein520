#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static loveNumber people[] = {
    0, "����",
    1, "��ޱ",
    2, "ľ��",
    3, "������",
    4, "Ҷ��",
    5, "����",
    6, "������",
    7, "����",
    8, "�������ֲ���ʶ",
    9, "����",
    10, "С����",
    11, "СԲ",
    12, "����",
    13, "ƿ��",
    14, "����",
    15, "��",
    16, "��",
    17, "975",
    18, "����",
    19, "����",
    20, "���",
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
    printf("%s����\n��������,����δ������㵱����.���û�б���¡�ֻ�������ˡ�����\n%s����\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfSecondLove(loveNumber * ptr)
{
    printf("%s����\n������ʶ�������࣬������һ�������԰��á�����������������⡣��Щ������Ļ����´λ��浱�潲�ա�\n%s��\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfThridLove(loveNumber * ptr)
{
    printf("%s,�������ã�\n�������Ǿó�ʱ�������ڳ���ĺĺ����Ե�Ի��ټ�������\n%s��\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfFourLove(loveNumber * ptr)
{
    printf("%s\n��һ������һ���ᶨ��Ψ�������ߣ�Ψ������ϣ��������\n%s\n", lovePtr->dataptr, singlePtr->dataptr);
}

void PrintfFiveLove(loveNumber * ptr)
{
    printf("%s����\n��ѩʱ�磬���밲�ơ�δ��Ϊ�������Ρ�%s���ס�\n%s\n", lovePtr->dataptr, lovePtr->dataptr, singlePtr->dataptr);
}
