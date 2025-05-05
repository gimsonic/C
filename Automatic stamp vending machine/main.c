#include <stdio.h>
#include <stdlib.h>

extern void input();
extern void stamp_dispense();
extern void calculate_coins();
extern void output();



int main()
{   
    extern int tender_amount, exc_status, balance;

    do
    {   
        input();

        if(tender_amount == 0){
            break;
        }

        stamp_dispense();

        calculate_coins();

        output();

        exc_status = 0;
        balance = 0;

    } while (1);
    

    return 0;
}