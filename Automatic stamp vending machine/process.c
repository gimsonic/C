#include <stdio.h>

int tender_amount, requested_stamp, out_stamp;
int balance;
int exc_status;

extern void exeptional_cases();
extern void available_stamps();
extern int same_denom_of_coins(int );

extern void input()
{
    extern int tender_amount, requested_stamp;

    printf("\n******************************************************************\n");
    printf(" INSERT COIN & CHOOSE STAMP -->  (STAMP_10 | STAMP_15 | STAMP_25)      |Press 0 to exit|");
    printf("\n******************************************************************\n\n");
    printf("\tTendering Amount : ");
    scanf("%d", &tender_amount);
    if(tender_amount == 0){
        return;
    }
    printf("\tRequsting Stamp  : ");
    scanf("%d", &requested_stamp);
    printf("\n");
}

void calculate_coins()
{
    extern int balance, exc_status;
    extern int avl_coin_5, avl_coin_10, avl_coin_25, avl_coin_50;

    if(exc_status == 1){
        return;
    }

    switch (tender_amount)
    {
        case 5:
            avl_coin_5 += 1;
            break;
        
        case 10:
            avl_coin_10 += 1;
            break;

        case 25:
            avl_coin_25 += 1;
            break;

        case 50:
            avl_coin_50 += 1;
            break;
        
        default:
            break;
    }

    if(balance == 0){   
            printf("\n\t  --------------------------\n");
            printf("\t      NO CHANGE AVAILABLE \n");
            printf("\t  --------------------------\n\n");
            return;
    }else if(balance == 10 && avl_coin_10 > 0){
            avl_coin_10 -= 1;
            printf("\t[CHANGE] : (10 Rupees/=) \n\n");
            return;
    }else if(balance == 15 && avl_coin_10 > 0 && avl_coin_5 > 0){
            avl_coin_10 -= 1;
            avl_coin_5 -= 1;
            printf("\t[CHANGE] : (10 Rupees/=) + (5 Rupees/=) \n\n");
            return;
    }else if(balance == 25 && avl_coin_25 > 0){
            avl_coin_25 -= 1;
            printf("\t[CHANGE] : (25 Rupees/=) \n\n");
            return;
    }else if(balance == 35 && avl_coin_25 > 0 && avl_coin_10 > 0){
            avl_coin_25 -= 1;
            avl_coin_10 -= 1;
            printf("\t[CHANGE] : (25 Rupees/=) + (10 Rupees/=) \n\n");
            return;
    }else if(balance == 40 && avl_coin_25 > 0 && avl_coin_10 > 0 && avl_coin_5 > 0){
            avl_coin_25 -= 1;
            avl_coin_10 -= 1;
            avl_coin_5 -= 1;
            printf("[CHANGE]: (25 Rupees/=) + (10 Rupees/=) + (5 Rupees/=) \n\n");
            return;
    }else{
        exc_status == 1;
        printf("\n\t  -----------------\n");
        printf("\t      NO CHANGE \n");
        printf("\t  -----------------\n\n");
    }

}


extern void stamp_dispense()
{
    extern int tender_amount , out_stamp, requested_stamp, exc_status;
    extern int avl_stamp_10, avl_stamp_15, avl_stamp_25;

    // Checking if a valid coin is inserted
    if(tender_amount != 5 && tender_amount != 10 && tender_amount != 25 && tender_amount != 50){
        printf("\tInvalid Coin !\n\n");
        printf("\t[RETURNING COIN] \n\n");
        exc_status = 1;
        return;
    }

    // Checking if a valid stamp is requested
    if(requested_stamp != 10 && requested_stamp != 15 && requested_stamp != 25){
        printf("\tInvalid stamp denomination !\n\n");
        printf("\t[RETURNING] : (%d Rupees/=)\n", tender_amount);
        out_stamp = 0;
        tender_amount = 0;
        exc_status = 1;
        return;
    }

    if(requested_stamp >= 10 && tender_amount == 5 ){
        tender_amount = 0;
        out_stamp = 0;
        exc_status = 1;
        printf("\t* Insufficient amount! *\n\n");
        printf("\t[RETURNING] : (5 Rupees/=)\n");
        return;
    }else if(requested_stamp > 10 && tender_amount == 10 ){
        tender_amount = 0;
        out_stamp = 0;
        exc_status = 1;
        printf("\t* Insufficient amount! *\n\n");
        printf("\t[RETURNING] : (10 Rupees/=)\n");
        return;
    }else if(requested_stamp > 25 && tender_amount == 25 ){
        tender_amount = 0;
        out_stamp = 0;
        exc_status = 1;
        printf("\t* Insufficient amount! *\n\n");
        printf("\t[RETURNING] : (25 Rupees/=)\n");
        return;
        
    }else if(requested_stamp == 10 || requested_stamp == 15 || requested_stamp == 25){

        switch(requested_stamp){
            case 10 :
                if(avl_stamp_10 <= 0){
                    printf("\tSorry, no stamp available !\n\n");
                    exc_status = 1;
                    return;
                }
            
            case 15 :
                if(avl_stamp_15 <= 0){
                    printf("\tSorry, no stamp available !\n\n");
                    exc_status = 1;
                    return;
                }
    
            case 25 :
                if(avl_stamp_25 <= 0){
                    printf("\tSorry, no stamp available !\n\n");
                    exc_status = 1;
                    return;
                }
        }
        
        out_stamp = requested_stamp;
        balance   = tender_amount - out_stamp;

        exc_status = same_denom_of_coins(balance);  

    }else{
        
    }
}



extern void output()
{   
    extern int out_stamp, exc_status;

    if(exc_status == 1){
        printf("\n\t~ STAMP NOT DISPENCED ~  \n");
        return;
    }

    if(out_stamp == 10){
        printf("\t[REQUESTED STAMP]: STAMP_10 \n");
    }else if(out_stamp == 15){
        printf("\t[REQUESTED STAMP]: STAMP_15 \n");
    }else if(out_stamp == 25){
        printf("\t[REQUESTED STAMP]: STAMP_25 \n");
    }else if(out_stamp == 0){
        printf("\t~ STAMP NOT DISPENCED ~  \n");
        return;
    }else{
        printf("Invalid stamp denomination !\n");
        return;
    }
    
    printf("\n    ~ STAMP SUCCESSFULLY DISPENCED ~  \n");

    available_stamps();
}

