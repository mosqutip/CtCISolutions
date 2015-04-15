#include "ChapterDeclarations.hpp"

namespace CtCISolutions
{
    /*
    Question:    1.1
    Arguments:   Pointer to character array
    Returns:     Boolean
    Description: Given a string input, return true if all characters in string
                 are unique (i.e. no repeat characters), and false otherwise
    Assumptions: Only English characters are used
                 ASCII character set is used (128 possible characters)
    */
    bool AllCharactersUnique(char *str)
    {
        if ((str == NULL) || (strlen(str) == 0))
        {
            return false;
        }

        int chars[128] = { 0 };

        while (*str)
        {
            if (chars[*str] != 0)
            {
                return false;
            }

            ++chars[*str];
            ++str;
        }

        return true;
    }

    /*
    Question:    1.2
    Arguments:   Pointer to character array
    Returns:     <void>
    Description: Given a string input, reverse the string in place
    Assumptions: None
    */
    void ReverseString(char *str)
    {
        if ((str == NULL) || (strlen(str) == 0))
        {
            return;
        }

        char start_char, *end_char = str + (strlen(str) - 1);

        while (end_char > str)
        {
            start_char = *str;
            *str = *end_char;
            *end_char = start_char;
            str++;
            end_char--;
        }
    }

    /*
    Question:    1.3
    Arguments:   Two pointers to character arrays
    Returns:     Boolean
    Description: Given two string inputs, determine if the second input is a
                 permutation of the first input, where a permutation is
                 defined purely as the reshuffling of the original characters
    Assumptions: Case sensitivity
                 ASCII character set is used (128 possible characters)
                 Alphabetization of each string followed by comparison
                 is also a valid strategy for solving this problem
    */
    bool IsStringPermutation(char *str1, char *str2)
    {
        if ((str1 == NULL) ||
            (strlen(str1) == 0) ||
            (str2 == NULL) ||
            (strlen(str2) == 0) ||
            (strlen(str1) != strlen(str2)))
        {
            return false;
        }

        int chars[128] = { 0 };

        while (*str1)
        {
            chars[*str1]++;
            ++str1;
        }

        while (*str2)
        {
            if (--chars[*str2] < 0)
            {
                return false;
            }
            ++str2;
        }

        return true;
    }

    /*
    Question:    1.4
    Arguments:   Two pointers to character arrays
    Returns:     <void>
    Description: Given a string input, change the spaces in the string
                 to the URL-encoding of a space character (%20)
    Assumptions: First string has adequate buffer space to be encoded
    */
    void UrlEncodeSpaces(char* str1, char* str2)
    {
        if ((str1 == NULL) ||
            (strlen(str1) == 0) ||
            (str2 == NULL) ||
            (strlen(str2) == 0))
        {
            return;
        }

        while (*str2)
        {
            if (*str2 == ' ')
            {
                *str1 = '%';
                *(++str1) = '2';
                *(++str1) = '0';
            }
            else
            {
                *str1 = *str2;
            }

            ++str2;
            ++str1;
        }
    }

    void AllCharactersUniqueTest()
    {
        char* str1 = "!?abcdefghijklmnopqrstuvwxyz.,\0";
        char* str2 = "The quick brown fox jumped over the lazy dog.\0";

        cout << "Does string: \"" << str1 << "\" have all unique characters? " << (AllCharactersUnique(str1) ? "Yes!" : "No!") << endl;
        cout << "Does string: \"" << str2 << "\" have all unique characters? " << (AllCharactersUnique(str2) ? "Yes!" : "No!") << endl;
    }

    void ReverseStringTest()
    {
        char str1[] = "This is a test string to reverse.\0";

        cout << "String: \"" << str1 << "\" reversed is: \"";
        ReverseString(str1);
        cout << str1 << "\"." << endl;
    }

    void IsStringPermutationTest()
    {
        char* str1 = "This is a test? string to permute\0";
        char* str2 = "is This a string to permute test?\0";
        char* str3 = "This is another test string.\0";

        cout << "Is string: \"" << str2 << "\" a permutation of string: \"" << str1 << "\"? " << (IsStringPermutation(str1, str2) ? "Yes!" : "No!") << endl;
        cout << "Is string: \"" << str3 << "\" a permutation of string: \"" << str1 << "\"? " << (IsStringPermutation(str1, str3) ? "Yes!" : "No!") << endl;
    }

    void UrlEncodeSpacesTest()
    {
        char str1[] = "This is a test string to url-encode.            \0";
        char str2[] = "This is a test string to url-encode.\0";

        cout << "String: \"" << str2 << "\" with spaces url-encoded is: \"";
        UrlEncodeSpaces(str1, str2);
        cout << str1 << "\"." << endl;
    }
};