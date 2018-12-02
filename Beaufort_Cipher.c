#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

int i, j, text_length, key_length;
char text[100], key[100], final_key[100], cipher[100], option;

int main()
{
    loop_main:
    printf("Please specify the desired method:\n");
    printf("1.Encryption[E]    2.Decryption[D]\n\n");
    scanf(" %c", &option);

    if((option=='1')||(option=='E')||(option=='e'))
    {
        printf("\nYou have chosen the encryption method.");
        loop_encrypt_text:
        printf("\nPlease enter a plain text to encrypt: ");
        scanf(" %s", text);
        text_length = strlen(text);
        for(i = 0; i < text_length; ++i)
        {
            if(isalpha(text[i]) == false)
            {
                printf("The text you have entered contains characters that are not allowed. Please enter alphabet letters only.\n");
                goto loop_encrypt_text;
            }
            else
            {
                /*Do nothing*/
            }
        }
        loop_encryption_key:
        printf("\nPlease enter an encryption key: ");
        scanf(" %s", key);
        key_length = strlen(key);
        for(j = 0; j < key_length; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("The key you have entered contains characters that are not allowed. Please enter alphabet letters only.\n");
                goto loop_encryption_key;
            }
            else
            {
                /*Do nothing*/
            }
        }

        for(i = 0, j = 0; i < text_length; ++i, ++j)
        {
            if(j == key_length)
            {
                j = 0;
            }
            else
            {
                /*Do nothing*/
            }

            final_key[i] = key[j];
        }

        final_key[i] = '\0';
        i = 0;

        while(i < text_length)
        {
            cipher[i] = (26 + toupper(final_key[i]) -  (toupper(text[i]))) % 26 + 'A';
            i += 1;
        }

        cipher[i] = '\0';
        printf("\nThe plain text is: %s\n", text);
        printf("The encryption key is: %s\n", key);
        printf("The cipher text is: %s\n", cipher);
    }
    else if((option=='2')||(option=='D')||(option=='d'))
    {
        printf("\nYou have chosen the decryption method.");
        loop_decrypt_text:
        printf("\nPlease enter a cipher text to decrypt: ");
        scanf(" %s", text);
        text_length = strlen(text);
        for(i = 0; i < text_length; ++i)
        {
            if(isalpha(text[i]) == false)
            {
                printf("The text you have entered contains characters that are not allowed. Please enter alphabet letters only.\n");
                goto loop_decrypt_text;
            }
            else
            {
                /*Do nothing*/
            }
        }
        loop_decryption_key:
        printf("\nPlease enter a decryption key: ");
        scanf(" %s", key);
        key_length = strlen(key);
        for(j = 0; j < key_length; ++j)
        {
            if(isalpha(key[j]) == false)
            {
                printf("The key you have entered contains characters that are not allowed. Please enter alphabet letters only.\n");
                goto loop_decryption_key;
            }
            else
            {
                /*Do nothing*/
            }
        }

        for(i = 0, j = 0; i < text_length; ++i, ++j)
        {
            if(j == key_length)
            {
                j = 0;
            }
            else
            {
                /*Do nothing*/
            }

            final_key[i] = key[j];
        }

        final_key[i] = '\0';
        i = 0;

        while(i < text_length)
        {
            cipher[i] = (26 + toupper(final_key[i]) -  (toupper(text[i]))) % 26 + 'A';
            i += 1;
        }

        cipher[i] = '\0';
        printf("\nThe cipher text is: %s\n", text);
        printf("The decryption key is: %s\n", key);
        printf("The plain text is: %s\n", cipher);
    }
    else
    {
        printf("\nThe chosen option is not valid.\n");
        goto loop_main;
    }

    printf("\nPress any key to try again...");
    getch();
    printf("\n\n");
    goto loop_main;
}
