#include <stdio.h>

int avl_stamp_10 = 5;
int avl_stamp_15 = 5;
int avl_stamp_25 = 10;

int avl_coin_5 = 4;
int avl_coin_10 = 5;
int avl_coin_25 = 2;
int avl_coin_50 = 10;

extern void available_stamps()
{
    extern int tender_amount, out_stamp, balance, exc_status;
    extern int avl_stamp_10, avl_stamp_15, avl_stamp_25;
    extern int avl_coin_5, avl_coin_10, avl_coin_25, avl_coin_50;

    switch (out_stamp)
    {
        case 10:
            avl_stamp_10 -= 1;
            break;
        
        case 15:
            avl_stamp_15 -= 1;
            break;

        case 25:
            avl_stamp_25 -= 1;
            break;
    }

    printf("\n\t--- Available Stamps ---\n\n");
    printf("\tStamp 10 : %d\n", avl_stamp_10);
    printf("\tStamp 15 : %d\n", avl_stamp_15);
    printf("\tStamp 25 : %d\n", avl_stamp_25);

    printf("\n\t--- Available Coins ---\n\n");
    printf("\tCoin 5  : %d\n", avl_coin_5);
    printf("\tCoin 10 : %d\n", avl_coin_10);
    printf("\tCoin 25 : %d\n", avl_coin_25);
    printf("\tCoin 50 : %d\n\n", avl_coin_50);
}