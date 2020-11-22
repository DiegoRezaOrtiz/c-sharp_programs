//include libraries
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int main(void)
{
    //introduction of "add" which is later used in the validation process of the cards where we sum the digits after the calculations.
    int add = 1;
    //we start with the card not being verified, it must pass the tests to become verified.
    bool verified = false;

    //we look for user input with "get_long" to find the varible "ccn" which stands for credit card number.    
    long ccn = get_long("Number: ");
    
    //we assign a variable to each of the digits of the variable "ccn". Escalating from "n1 - n16" where "n" stands for number.
    int n1 = ccn % 10;
    int n2 = ccn / 10 % 10;
    int n3 = ccn / 100 % 10;
    int n4 = ccn / 1000 % 10;
    int n5 = ccn / 10000 % 10;
    int n6 = ccn / 100000 % 10;
    int n7 = ccn / 1000000 % 10;
    int n8 = ccn / 10000000 % 10;
    int n9 = ccn / 100000000 % 10;
    int n10 = ccn / 1000000000 % 10;
    int n11 = ccn / 10000000000 % 10;
    int n12 = ccn / 100000000000 % 10;
    int n13 = ccn / 1000000000000 % 10;
    int n14 = ccn / 10000000000000 % 10;
    int n15 = ccn / 100000000000000 % 10;
    int n16 = ccn / 1000000000000000 % 10;
    
    // if the input "ccn" is 13 OR 15 digits, this function will be used. This is part of the VERIFIER Test, to check if the card is valid or not.
    if ((9999999999999 > ccn && ccn > 1000000000000) || (999999999999999 > ccn && ccn > 100000000000000))
    {
        //this function multiplies the correct digits by two and separates each digit of the result.
        int m1 = (n1 * 2) % 10;
        int m1a = (n1 * 2) / 10 % 10;
        int m2 = (n3 * 2) % 10;
        int m2a = (n3 * 2) / 10 % 10;
        int m3 = (n5 * 2) % 10;
        int m3a = (n5 * 2) / 10 % 10;
        int m4 = (n7 * 2) % 10;
        int m4a = (n7 * 2) / 10 % 10;
        int m5 = (n9 * 2) % 10;
        int m5a = (n9 * 2) / 10 % 10;
        int m6 = (n11 * 2) % 10;
        int m6a = (n11 * 2) / 10 % 10;
        int m7 = (n13 * 2) % 10;
        int m7a = (n13 * 2) / 10 % 10;
        int m8 = (n15 * 2) % 10;
        int m8a = (n15 * 2) / 10 % 10;

        // The "add" variable introduced earlier adds all the respective digits together to continue with the testing process.
        add = m1a + m1 + n2 + m2a + m2 + n4 + m3a + m3 + n6 + m4a + m4 + n8 + m5a + m5 + n10 + m6a + m6 + n12 + m7a + m7 + n14 + m8a + m8 +
              n16;
    }
    // this function will be used if input "ccn" is 14 or 16 digits. This is part of the VERIFIER Test, to check if the card is valid or not.
    else if ((99999999999999 > ccn && ccn > 10000000000000) || (9999999999999999 > ccn && ccn > 1000000000000000))
    {
        int m1 = (n2 * 2) % 10;
        int m1a = (n2 * 2) / 10 % 10;
        int m2 = (n4 * 2) % 10;
        int m2a = (n4 * 2) / 10 % 10;
        int m3 = (n6 * 2) % 10;
        int m3a = (n6 * 2) / 10 % 10;
        int m4 = (n8 * 2) % 10;
        int m4a = (n8 * 2) / 10 % 10;
        int m5 = (n10 * 2) % 10;
        int m5a = (n10 * 2) / 10 % 10;
        int m6 = (n12 * 2) % 10;
        int m6a = (n12 * 2) / 10 % 10;
        int m7 = (n14 * 2) % 10;
        int m7a = (n14 * 2) / 10 % 10;
        int m8 = (n16 * 2) % 10;
        int m8a = (n16 * 2) / 10 % 10;

        // The "add" variable introduced earlier adds all the respective digits together to continue with the testing process.
        add = m1a + m1 + n1 + m2a + m2 + n3 + m3a + m3 + n5 + m4a + m4 + n7 + m5a + m5 + n9 + m6a + m6 + n11 + m7a + m7 + n13 + m8a + m8 +
              n15;
    }
    
    //indroduction of varible "verifier" that tests if the last digit of the "add" variable is 0, if not, test fails. This is the VERIFIER Test,      to check if the card is valid or not.
    int verifier = add % 10;

    //if the VERIFIER test is passed, this function sets the "ccn" status as "verified" and can now proceed to the IDENTITY Test.
    if (verifier == 0)
    {
        verified = true;
    }
    // if the test fails, Output INVALID appears
    else
    {
        printf("INVALID\n");
    }

    //if the card status is verified, this function will be used. This is the IDENTITY Test, to identify which bank do they belong to.
    if (verified == true)
    {
        //this function checks if the "ccn" is 15 digits that starts with "34" or "37", since its verified and it has the starting numbers of             American Express, output AMEX appears
        if (n16 == 0 && n15 == 3 && (n14 == 4 || n14 == 7))
        {
            printf("AMEX\n");
        }
        //this function checks if the "ccn" is 16 digits that starts with "51 - 55", since its verified and it has the starting numbers of                MasterCard, output MASTERCARD appears
        else if (n16 == 5 && (n15 <= 5 && n15 >= 1))
        {
            printf("MASTERCARD\n");
        }
        //this function checks if "ccn" is a 16 or 13 digits that starts with "4", since its verified and it has the starting numbers of Visa,            output VISA appears
        else if (n16 == 4 || (n13 == 4 && n14 == 0 && n15 == 0 && n16 == 0))
        {
            printf("VISA\n");
        }
        // if the "ccn" passed the test an gained verified status, but failed to be identified as Visa, MasterCard or American Express, Output            INVALID appears
        else
        {
            printf("INVALID\n");
        }
    }
}
