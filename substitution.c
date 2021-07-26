#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    // printf("%d\n %s\n", argc, argv[1]);
    // Validate the Key
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("key must only contain alphabetic characters.");
                return 1;
            }
        }
        
        // Check for every letter in argv[1]
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // get one letter and compare it with rest except the previous checked letters
            for (int j = i + 1; j < n; j++)
            {
                // printf("%c %c\n", argv[1][i], argv[1][j]);
                if (argv[1][j] == argv[1][i])
                {
                    printf("key must not contain repeated letters.");
                    return 1;
                }
            }
        }
    }

    // Prompt the user for plain text
    string p = get_string("plaintext: ");
    
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (isupper(p[i]))
        {
            p[i] = argv[1][p[i] - 'A'];
            // Preserving the case
            p[i] = toupper(p[i]);
        }
        else if (islower(p[i]))
        {
            p[i] = argv[1][p[i] - 'a'];
            // Preserving the case
            p[i] = tolower(p[i]);
        }
        else
        {
            p[i] += 0;
        }
    }
    
    // Print the cipher text
    printf("ciphertext: %s\n", p);
    return 0;
}