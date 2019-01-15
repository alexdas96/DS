#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 255

struct position
{
    int row;
    int column;
};

char* reverseSearchOnTable(char** table, char* sentence, struct position *pos, int table_len, int method)
{
    int i, x, y, w=0, spaces=0, real_len, s_len = strlen(sentence);
    char* new_sen = malloc(sizeof(char)*s_len);
    struct position *decr_pos;

    for(i=0; i<s_len; i++)
    {
        if(sentence[i] == ' ')
        {
            ++spaces;
        }
        else
        {
            /*Do nothing*/
        }
    }

    real_len = s_len - spaces;

    decr_pos = malloc(sizeof(struct position)*real_len);
    memcpy(decr_pos, pos, sizeof(struct position)*real_len);

    if(method == 1)
    {
        if(real_len % 2 == 0)
        {
            for(x=0, w=0; x<(real_len/2); x++, w+=2)
            {
                decr_pos[w].row = pos[x].row;
                decr_pos[w+1].row = pos[x].column;
            }

            for(y=x, w=0; y<(x+(real_len/2)); y++, w+=2)
            {
                decr_pos[w].column = pos[y].row;
                decr_pos[w+1].column = pos[y].column;
            }

            for(x=0; x<real_len; x++)
            {
                printf("%i%i ", decr_pos[x].row, decr_pos[x].column);
            }
        }
        else
        {
            for(x=0, w=0; x<(real_len/2); x++, w+=2)
            {
                decr_pos[w].row = pos[x].row;
                decr_pos[w+1].row = pos[x].column;
            }

            decr_pos[w].row = pos[x].row;
            decr_pos[0].column = pos[x].column;

            for(y=x+1, w=1; y<(x+1+(real_len/2)); y++, w+=2)
            {
                decr_pos[w].column = pos[y].row;
                decr_pos[w+1].column = pos[y].column;
            }

            for(x=0; x<real_len; x++)
            {
                printf("%i%i ", decr_pos[x].row, decr_pos[x].column);
            }
        }

        for(x=0, w=0; x<s_len; x++,w++)
        {
            new_sen[x] = table[decr_pos[w].row][decr_pos[w].column];
        }

        new_sen[x] = '\0';

        return new_sen;
    }

    if(real_len % 2 == 0)
    {
        for(x=0, w=0; x<(real_len/2); x++,w+=2)
        {
            new_sen[x] = table[decr_pos[w].row][decr_pos[w+1].row];
            printf("%i%i ", decr_pos[w].row, decr_pos[w+1].row);
        }

        for(y=x, w=0; y<(x+(real_len/2)); y++, w+=2)
        {
            new_sen[y] = table[decr_pos[w].column][decr_pos[w+1].column];
            printf("%i%i ", decr_pos[w].column, decr_pos[w+1].column);
        }
    }
    else
    {
        for(x=0, w=0; x<(real_len/2); x++,w+=2)
        {
            new_sen[x] = table[decr_pos[w].row][decr_pos[w+1].row];
            printf("%i%i ", decr_pos[w].row, decr_pos[w+1].row);
        }

        new_sen[x] = table[decr_pos[w].row][decr_pos[0].column];
        printf("%i%i ", decr_pos[w].row, decr_pos[0].column);

        for(y=x+1, w=1; y<(x+1+(real_len/2)); y++, w+=2)
        {
            new_sen[y] = table[decr_pos[w].column][decr_pos[w+1].column];
            printf("%i%i ", decr_pos[w].column, decr_pos[w+1].column);
        }
    }

    new_sen[y] = '\0';

    return new_sen;
}

struct position *searchOnTable(char** table, char* sentence, int table_len)
{
    struct position * pos;
    int i, x, y, w=0, spaces=0, real_len, s_len = strlen(sentence);

    for(i=0; i<s_len; i++)
    {
        if(sentence[i] == ' ')
        {
            ++spaces;
        }
        else
        {
            /*Do nothing*/
        }
    }

    real_len = s_len - spaces;
    pos = malloc(sizeof(struct position)*real_len);

    for(i=0, w=0; i<s_len; i++)
    {
        for(x=0; x<table_len; x++)
        {
            for(y=0; y<table_len; y++)
            {
                if(sentence[i] == ' ')
                {
                    ++w;
                    ++i;
                }
                else
                {
                    /*Do nothing*/
                }

                if(sentence[i] == table[x][y])
                {
                    pos[i-w].row = x;
                    pos[i-w].column = y;
                    printf("%i%i ", pos[i-w].row, pos[i-w].column);
                }
                else
                {
                    /*Do nothing*/
                }
            }
        }
    }

    return pos;
}

int main(void)
{
    char **table;
    char sentence[MAX_VALUE];
    char answ;
    struct position *posXY;
    char* de_crypt_sen;
    int i, table_len, method = 0;

    printf("------------- Bifid Cipher/Decipher  -------------\n\n");
    printf("Do you want to use default table? (y/n): ");
    scanf(" %c", &answ);
    printf("\n");

    if(answ == 'n')
    {
        printf("Size of table (ex: 5 for 5x5): ");
        scanf("%i", &table_len);
        printf("\n");

        table = malloc(table_len * sizeof(char*));
        for (i = 0; i < table_len; i++)
        {
            table[i] = malloc((table_len+1) * sizeof(char));
        }

	    printf("Write your table:\n\n");
	    for(i=0; i<table_len; i++)
        {
	        scanf("%s", table[i]);
        }

        printf("\n");
    }
    else if(answ == 'y')
    {
        table_len = 5;
        table = malloc(table_len * sizeof(char*));
        for (i = 0; i < table_len; i++)
        {
            table[i] = malloc((table_len+1) * sizeof(char));
        }

        table[0] = "abcde";
        table[1] = "fghik";
        table[2] = "lmnop";
        table[3] = "qrstu";
        table[4] = "vwxyz";
    }
    else
    {
        printf("Invalid operation\n");
        exit(0);
    }

    printf("Do you want to cipher (0) or decipher (1)? : ");
    scanf("%i", &method);
    printf("\n");

    if(method == 0)
    {
        printf("Write the sentence: ");
        scanf(" %[^\n]s", sentence);
        printf("\n");

        posXY = searchOnTable(table, sentence, table_len);

        printf("\n");

        de_crypt_sen = reverseSearchOnTable(table, sentence, posXY, table_len, method);

        printf("\n\nCiphered sentence: %s\n", de_crypt_sen);

        if(answ == 'n')
        {
            printf("\nREMEMBER: Copy your table, otherwise you can't decipher the sentence.\n");
        }
        else
        {
            /*Do nothing*/
        }

        printf("\n");

        system("PAUSE");
    }
    else if(method == 1)
    {
        printf("Write the sentence: ");
        scanf(" %[^\n]s", sentence);
        printf("\n");

        posXY = searchOnTable(table, sentence, table_len);

        printf("\n");

        de_crypt_sen = reverseSearchOnTable(table, sentence, posXY, table_len, method);

        printf("\n\nDeciphered sentence: %s\n", de_crypt_sen);

        printf("\n");

        system("PAUSE");
    }
    else
    {
        printf("Invalid operation\n");
        exit(0);
    }

	return 0;
}
