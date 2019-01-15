#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

char* alphabet = "abcdefghijklmnopqrstuvwxyz";

int GetCharPositionInAplhabet(char ch)
{
    char* letter = strchr(alphabet, ch);
    return letter - alphabet;
}

void DisplayCharArray(char* str)
{
    int i = 0;
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}

char* BuildNewKey(char plainText[], char key[])
{
    int i;
    char* newKey = (char *) malloc(sizeof(char) * strlen(plainText) + strlen(key) -1);
    for(i = 0; i<strlen(key);i++)
    {
        newKey[i] = key[i];
    }

    int j;
    for(int j=0; j<strlen(plainText); j++)
    {
        newKey[i] = plainText[j];
        i++;
    }
    return newKey;
}

char* Encrypt(char plainText[], char key[])
{
    int i = 0;
    int j = 0;
    char* cipherText  = (char *) malloc(sizeof(char) * strlen(plainText) -1);
    char* newKey = BuildNewKey(plainText,key);
    for(i = 0; i < strlen(plainText); i++)
    {
        int plainLetterIndex = GetCharPositionInAplhabet(plainText[i]);
        int keyLetterIndex = GetCharPositionInAplhabet(newKey[j]);

        int index = plainLetterIndex + keyLetterIndex;

        if(index > ALPHABET_SIZE)
        {
            index -= ALPHABET_SIZE;
        }
        else
        {
            /*Do nothing*/
        }

        cipherText[i] = alphabet[index];
        j++;

    }

    return cipherText;

}

char* Decrypt(char cipherText[], char key[])
{
    int i = 0;
    int j = 0;
    char* plainText  = (char *) malloc(sizeof(char) * strlen(cipherText) -1);

    for(i = 0; i < strlen(cipherText); i++)
    {
        int cipherLetterIndex = GetCharPositionInAplhabet(cipherText[i]);
        int keyLetterIndex = GetCharPositionInAplhabet(key[j]);
        int index = 0;
        if(cipherLetterIndex >= keyLetterIndex)
        {
            index = cipherLetterIndex - keyLetterIndex;
        }
        else
        {
            if(cipherLetterIndex + keyLetterIndex > ALPHABET_SIZE)
            {
                index = ALPHABET_SIZE - keyLetterIndex + cipherLetterIndex;
            }
            else
            {
                index = keyLetterIndex + cipherLetterIndex;
            }
        }

        plainText[i] = alphabet[index];
        j++;
        if(j == strlen(key))
        {
            j = 0;
        }
        else
        {
            /*Do nothing*/
        }
    }
    return plainText;
}


int main()
{
    char* cipherText = Encrypt("people", "dintw");
    DisplayCharArray(cipherText);

    char* plainText = Decrypt("smbihh", "dintw");
    DisplayCharArray(plainText);


    return 0;
}
