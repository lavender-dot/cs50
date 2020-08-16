#include <stdio.h>
#include <cs50.h>

// Week 1 Lab, Part 2: Mario program (the 'feeling less comfy' vsn)

//Prompt for height and then build a pyramid of that height
int main(void)
{
    int pyramid_height;

    //Ask user to provide a height for the pyramid
    do
    {
        pyramid_height = get_int("How high do you want your pyramid to be? (choose any integer height between 1 and 8)>\n");
    }
    while (pyramid_height < 1 || pyramid_height > 8);

    // Now build the pyramid.
    printf("\n");
    for (int i = 0; i < pyramid_height; i++)
    {
        int number_of_spacepadding = pyramid_height - i - 1;
        for (int k = 0; k < number_of_spacepadding; k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

