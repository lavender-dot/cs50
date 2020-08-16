#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Week 1 Lab, Part 3: Credit program (the 'feeling more comfy' vsn)

//Prompt user for credit card #; Then calc checksum to validate; Test if card has correct length and starting digit (ie, for Visa/Amex/MC);
int main(void)
{
    string credit_card_brand;
    long credit_card_no;

    //Ask user to provide credit card #

    credit_card_no = get_long("Enter your credit card # (enter digits only, ignore spaces, dashes etc.) >\n");
    if ((credit_card_no >= 340000000000000 && credit_card_no < 350000000000000) ||
        (credit_card_no >= 370000000000000 && credit_card_no < 380000000000000))
    {
        credit_card_brand = "AMEX";
    }
    else if (credit_card_no >= 5100000000000000 && credit_card_no < 5600000000000000)
    {
        credit_card_brand = "MASTERCARD";
    }
    else if ((credit_card_no >= 4000000000000 && credit_card_no < 5000000000000) || 
        (credit_card_no >= 4000000000000000 && credit_card_no < 5000000000000000))
    {
        credit_card_brand = "VISA";
    }
    else
    {
        credit_card_brand = "INVALID";
    }

    // printf("credit card:%s number,%ld\n", credit_card_brand, credit_card_no);


    if (strcmp(credit_card_brand, "INVALID") != 0) 
    {

        //Apply Luhn's Checksum Algorithm
        long drl;  //digits_remaining_to_left of the credit card number currently being processed
        int check_digit;
        int doubler_toggle = 0;
        int reg_sum = 0;
        int double_sum = 0;

        for (drl = credit_card_no; drl > 0; drl = drl / 10)
        {
            check_digit = drl % 10;
            if (doubler_toggle == 0)
            {
                reg_sum = reg_sum + check_digit;
            }
            else 
            {
                int double_check_digit = 2 * check_digit;
                double_sum = double_sum + (double_check_digit % 10) + (double_check_digit / 10);
            }
            
            doubler_toggle = (doubler_toggle + 1) % 2;
            // printf("%ld, %d, %d, %d \n",drl, check_digit, reg_sum, double_sum);
        }

        int check_sum_test = (reg_sum + double_sum) % 10;
        if (check_sum_test != 0)
        {
            credit_card_brand = "INVALID";
        }
    }

    printf("%s\n", credit_card_brand);

    // printf("credit card:%s number,%ld\n", credit_card_brand, credit_card_no);
}