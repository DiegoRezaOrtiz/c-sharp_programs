#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string text = get_string("Text: ");
    // introduction of variables to which will be used in the analysis of the text.
    int space = 0;
    int sentence = 0;
    int letter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //this checks the text for the number of spaces, used to count the ammount of words in the text later on.
        if (text[i] == 32)
        {
            space = space + 1;
            
        }
        // this checks for the number of periods, question marks and exclamation points which normally mark the end of a sentence.
        else if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            sentence = sentence + 1;
        }
        //this checks for letters, if it is between "A - Z" or "a - z"
        else if ((text[i] <= 'Z' && text [i] >= 'A') || (text[i] <= 'z' && text[i] >= 'a'))
        {
            letter = letter + 1;
        }
        
    }
    // there is always 1 more word, than there are spaces in average.
    int word = space + 1;
    // get the average of letters in 100 words for the index calculation.
    float L = ((float)letter / word) * 100;
    // get the average of sentences in 100 words for the index calculation.
    float S = ((float)sentence / word) * 100;

    //index formula supplied by excersize, used float instead of integal so i can round to the nearest number.
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
