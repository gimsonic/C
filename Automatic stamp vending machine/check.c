#include <stdio.h>

extern int same_denom_of_coins(int bal)

{   
    extern int tender_amount, balance, exc_status;
    extern int avl_coin_5, avl_coin_10, avl_coin_25, avl_coin_50; 

    if(bal == 0){
        return 0;
    }
    else if(bal == 10 && avl_coin_10 > 0){
        return 0;

    }else if(bal == 15 && avl_coin_10 > 0 && avl_coin_5 > 0){
        return 0;

    }else if(bal == 25 && avl_coin_25 > 0){
        return 0;

    }else if(bal == 35 && avl_coin_25 > 0 && avl_coin_10 > 0){
        return 0;

    }else if(bal == 40 && avl_coin_25 > 0 && avl_coin_10 > 0 && avl_coin_5 > 0){
        return 0;

    }else{
        printf("\t[RETURNING] : (%d Rupees/=)\n", tender_amount);
        printf("\n\t  -----------------\n");
        printf("\t      NO CHANGE \n");
        printf("\t  -----------------\n\n");
        return 1;
    }
}