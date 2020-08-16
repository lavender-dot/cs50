#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool prepare_key(string user_key);
string build_ciphertext(string user_key, string a1);

int main(int argc, string argv[])
{
    string key;

    if (argc != 2)
    {
        printf("Usage: substitute key_string\n");
        return 1;
    }

    key = argv[1];

    if (prepare_key(key))
    {
        return 1;
    }

    // Prompt user for input parms.
    string plaintext = get_string("plaintext: ");
    // printf("XXX Plain text is: %s\n",plaintext);

    build_ciphertext(key, plaintext);
}

bool prepare_key(string user_key)
{
    // printf("XXX We made it to Prepare Key %s!\n", user_key);

    int valid_key_length = 26;

    if (strlen(user_key) != valid_key_length)
    {
        printf("Key must contain %d characters.\n", valid_key_length);
        return 1;
    }

    // Convert user provided key (user_key) to upper case, to make it easier to map plaintext to ciphertext.

    for (int i = 0; i < valid_key_length; i++)
    {
        user_key[i] = toupper(user_key[i]);
    }
    // printf("XXX The cipher code converted to uppercase is %s\n",user_key);

    // Check that the ciphercode is all alpha AND has zero duplicates.

    for (int i = 0; i < valid_key_length; i++)
    {
        if (user_key[i] >= 'A' && user_key[i] <= 'Z')
        {
            ;  // printf("XXX Good, we have an alpha char: %c .\n", user_key[i]);
        }
        else
        {
            printf("Key must be %d ALPHA characters.\n", valid_key_length);
            return 1;
        }

        for (int j = 0; j < i; j++)
        {
            if (user_key[j] == user_key[i])
            {
                printf("Key must not contain duplicate characters. Duplicate found: %c at position %d\n", user_key[i], i);
                return 1;
            }
        }
    }
    return 0;
}

string build_ciphertext(string user_key, string a1)
{
    int lookup_index;
    // printf("XXX We made it to Build_Ciphertext and our plaintext is %s and our user_crypto_key is %s !\n", a1, user_key);

    for (int i = 0; i < strlen(a1); i++)
    {
        lookup_index = 99;
        if (a1[i] >= 'A' && a1[i] <= 'Z')
        {
            lookup_index = a1[i] - 65;              // Calc the index of this letter within the 26 letter alphabet
        }
        else if (a1[i] >= 'a' && a1[i] <= 'z')
        {
            lookup_index = a1[i] - 32 - 65;         // Convert to uppercase and then calc the index of this letter within the 26 letter alphabet
        }

        // Our encryption algorithm only converts alphabetic characters. If lookup_index is still 99, then a1[i] is NOT an alpha char.
        if (lookup_index != 99)
        {
            if (a1[i] >= 'A' && a1[i] <= 'Z')
            {
                a1[i] = user_key[lookup_index];
            }

            else if (a1[i] >= 'a' && a1[i] <= 'z')
            {
                a1[i] = tolower(user_key[lookup_index]);
            }
        }
    }
    printf("ciphertext: %s\n", a1);
    return 0;
}

