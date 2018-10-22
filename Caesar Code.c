#include<stdio.h>
#include <conio.h>

int i, key;
char text[100], position, option;

int main()
{
    loop_main:
    printf("Please specify the desired method:\n");
    printf("1.Encryption[E]    2.Decryption[D]\n\n");
    scanf(" %c", &option);

    if((option=='1')||(option=='E')||(option=='e'))
    {
        printf("\nYou have chosen the encryption method.\n");
        printf("Please enter a plain text to encrypt: ");
        scanf(" %s", text);
        printf("\nPlease enter an encryption key: ");
        scanf(" %d", &key);

        for(i = 0; text[i] != '\0'; ++i)
        {
            position = text[i];

            if(position >= 'a' && position <= 'z')
            {
                position = position + key;

                if(position > 'z')
                {
                    position -= 26;
                }
                else if(position < 'a')
                {
                    position += 26;
                }
                else
                {
                    /*Do nothing*/
                }

                text[i] = position;
            }
            else if(position >= 'A' && position <= 'Z')
            {
                position = position + key;

                if(position > 'Z')
                {
                    position -= 26;
                }
                else if(position < 'A')
                {
                    position += 26;
                }
                else
                {
                    /*Do nothing*/
                }

                text[i] = position;
            }
            else
            {
                /*Do nothing*/
            }
        }

        printf("\nThe cipher text is: %s\n", text);
    }
    else if((option=='2')||(option=='D')||(option=='d'))
    {
        printf("\nYou have chosen the decryption method.\n");
        printf("Please enter a cipher text to decrypt: ");
        scanf(" %s", text);
        printf("\nPlease enter a decryption key: ");
        scanf(" %d", &key);;

        for(i = 0; text[i] != '\0'; ++i)
        {
            position = text[i];

            if(position >= 'a' && position <= 'z')
            {
                position = position - key;

                if(position < 'a')
                {
                    position += 26;
                }
                else if(position > 'z')
                {
                    position -= 26;
                }
                else
                {
                    /*Do nothing*/
                }

                text[i] = position;
            }
            else if(position >= 'A' && position <= 'Z')
            {
                position = position - key;

                if(position < 'A')
                {
                    position += 26;
                }
                else if(position > 'Z')
                {
                    position -= 26;
                }
                else
                {
                    /*Do nothing*/
                }


                text[i] = position;
            }
            else
            {
                /*Do nothing*/
            }
        }

        printf("\nThe plain text is: %s\n", text);
    }
    else
    {
        printf("\nThe chosen option is not valid.\n");
        goto loop_main;
    }

    printf("\nPress any key to try again...\n\n");
    getch();
    goto loop_main;
}
