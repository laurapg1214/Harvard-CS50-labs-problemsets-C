/*
    PROGRAM :  Caesar
    AUTHOR  :  Laura Purcell-Gates
    EMAIL   :  <laurapurcellgates@gmail.com>

    CS50x 2023 Problem Set 2 Caesar

    Caesar is a program that encrypts messages using Caesar's cipher.

    Code fully written by me; no pre-filled CS50 code.

    Link to the  problem set:
    https://cs50.harvard.edu/x/2023/psets/2/caesar  */


#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare functions
bool only_digits(string s);
string rotate(string s, int k);

int main(int argc, string argv[])
{
    // validate key for argc == 2 and for only_digits. Message to user "Usage: ./caesar key" and return 1
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // convert argv[] from a string to an int using atoi, declare int key
    int key = atoi(argv[1]);

    // ask user for input "plaintext:  " with 2 spaces no newline (get_string)
    string plaintext = get_string("plaintext:  ");

    // call function rotate
    string ciphertext = rotate(plaintext, key);

    // print "ciphertext: " with 1 space no newline, following by user's ciphertext
    printf("ciphertext: %s\n", ciphertext);
}

// define function bool only_digits(string s)
bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// define function rotate
string rotate(string s, int k)
{
    // for loop to go through each character of string array
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // for letters only, convert into ascii value
        if (isalpha(s[i]))
        {
            // run the ci = (pi + k) % 26, with resetting to 65 / 97
            int ascii_offset = isupper(s[i]) ? 65 : 97;
            int pi = s[i] - ascii_offset;
            int ci = (pi + k) % 26;
            // LauraPG: place cipherletters back into array using offset to get back to ascii values
            s[i] = ci + ascii_offset;
        }
    }
    // return ciphertext
    return s;
}