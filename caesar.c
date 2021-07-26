#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    int key;
    // Check if only 1 argument is entered along with ./ceaser making it total 2
    // argv[0] = ./ceaser and argv[1] = a number
    if (argc == 2)
    {
        // Check if argv[1] is a number by accessing every element of argv[1]
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //printf("Success\n %s\n", argv[1]);

        // Convert argv[1](which is a string of numbers) into integer to futher perform math with it
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Prompt the user for a plain text
    string p = get_string("plaintext: ");

    // Convert the plain text to a cipher text using the formula
    // Explanation at the end
    for (int i = 0, l = strlen(p); i < l; i++)
    {
        if (isupper(p[i]))
        {
            p[i] = (((p[i] - 'A') + key) % 26) + 'A';
        }
        else if (islower(p[i]))
        {
            p[i] = (((p[i] - 'a') + key) % 26) + 'a';
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

// Explanation of formula used for converting plain text(p) into cipher text(c)

// c[i] = (p[i] + k) % 26 (total characters = 26)
// p[i] -> i(th) character of plain text similarly c[i] and k is the key by which alphabets are shifted
// We want to follow a cycle within 26 alphabets, when key is 1 the Z should be A and so on
// It is possible when A = 0, B = 1,......,Z = 25 (for both uppercase and lower case)
// If we type Z and Z = 25 and key is 1 -> c[i] = (25 + 1) % 26 gives 0 i.e A
// For this to be possible
// 1) Convert ASII to a alphabetical index i.e now A is 65
//    but A should be zero and B is 67 then B should be 1
//    This is achieved using (p[i] - 'A'), is p[i] is A then it will become zero similarly B -> 1,...,Z -> 25
// 2) Shift the alphabetical index by key using (p[i] - 'A') + key
// 3) Now Take the index and convert it back to ASCII(as program will print using ASCII) i.e 0 to A, 1 to B and so on
//    This can be done by again adding 'A' to the result
//    i.e ((p[i] - 'A') + key) + 'A'

