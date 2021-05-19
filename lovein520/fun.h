#ifndef _FUN_H_
#define _FUN_H_

typedef struct loveNumber
{
    int number;
    char * dataptr;
}loveNumber;

void setSinglePersion(int number);
void getLovePersion(void);

typedef void (*printfLove)(loveNumber * ptr);

void PrintfFirstLove(loveNumber * ptr);
void PrintfSecondLove(loveNumber * ptr);
void PrintfThridLove(loveNumber * ptr);
void PrintfFourLove(loveNumber * ptr);
void PrintfFiveLove(loveNumber * ptr);

#endif
