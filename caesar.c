#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>

int main(int argc, string argv[])
{
    char *end;
    // strtol is function which tries to convert the string to long data if it cannot convert it long  then it sets second argument which is char pointer to first parameter's value. It takes third parameter which denotes the base of the number system
    // if more than 1 argument is passed
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    long val = strtol(argv[1], &end, 10);
    // checking whether the argument passed is int or not
    if (*end != '\0')
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int key = val;
    key = key % 26;
    string plaintext = get_string("Plaintext:  ");
    string ciphertext = plaintext;
    for (int i = 0, j = strlen(plaintext); i < j; i++ )
    {
        if(ciphertext[i] >= 'a' &&  ciphertext[i] <= ('z' -key))
        {
            ciphertext[i] = plaintext[i] + key;
        }
        else  if(ciphertext[i]> ('z' - key) && ciphertext[i] <= 'z')
        {
            ciphertext[i] = plaintext[i] - (26 -key);
        }
        else if(ciphertext[i] >= 'A' &&  ciphertext[i] <= ('Z' - key))
        {
            ciphertext[i] = plaintext[i] + key;
        }
        else if(ciphertext[i] > ('Z' - key) && ciphertext[i] <= 'Z')
        {
            ciphertext[i] = plaintext[i] - (26 -key);
        }
    }
    printf("Ciphertext:  %s\n", ciphertext);
}
