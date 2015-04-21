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

    /*
    Question:    1.5
    Arguments:   Pointer to character array
    Returns:     Pointer to character array
    Description: Given a string input, compress the string by replacing
                 repeated sequences of characters with the character an
                 integer count. If the compressed string would be longer
                 than the original, return the original string instead
    Assumptions: None
    */
    char* CompressString(char* str)
    {
        char* ptr = str;
        char current = *ptr++;
        int char_count = 1, sum = 0;

        while (*ptr)
        {
            if (*ptr == current)
            {
                char_count++;
            }
            else
            {
                sum += (1 + (to_string(char_count).length()));
                char_count = 1;
                current = *ptr;
            }

            ++ptr;
        }

        sum += (1 + (to_string(char_count).length()));

        if (sum > (int)strlen(str))
        {
            return str;
        }
        else
        {
            ptr = str;
            current = *ptr++;
            char_count = 1;
            int index = 0;

            char* compressed_str = (char*)malloc((sum + 1) * sizeof(char));
            memset(compressed_str, 0, (sum * sizeof(char)));

            while (*ptr)
            {
                if (*ptr == current)
                {
                    char_count++;
                }
                else
                {
                    compressed_str[index] = current;
                    ++index;

                    for (char c : to_string(char_count))
                    {
                        compressed_str[index] = c;
                        ++index;
                    }

                    char_count = 1;
                    current = *ptr;
                }

                ++ptr;
            }

            compressed_str[index] = current;
            ++index;

            for (char c : to_string(char_count))
            {
                compressed_str[index] = c;
                ++index;
            }

            compressed_str[index] = '\0';

            return compressed_str;
        }
    }

    /*
    Question:    1.6
    Arguments:   Pointer to array of integer pointers, integer matrix dimension
    Returns:     <void>
    Description: Given a square matrix (represented as a two-
                 dimensional array), rotate the matrix by 90 degrees
    Assumptions: None
    */
    void RotateMatrix(int** matrix, int width)
    {
        for (int i = 0; i < (width / 2); ++i)
        {
            int start = i, end = (width - 1 - i);

            for (int j = start; j < end; ++j)
            {
                int k = (end - (j - start));
                int top_val = matrix[start][j];

                matrix[start][j] = matrix[k][start];
                matrix[k][start] = matrix[end][k];
                matrix[end][k] = matrix[j][end];
                matrix[j][end] = top_val;
            }
        }
    }

    /*
    Question:    1.7
    Arguments:   Pointer to array of integer pointers, integer number
                 of matrix rows, integer number of matrix columns
    Returns:     <void>
    Description: Given a matrix (represented as a two-dimensional array),
                 zero out all rows and columns containing a zero.
    Assumptions: None
    */
    void ZeroMatrixRowAndColumn(int** matrix, int rows, int cols)
    {
        vector<bool> *zeros = new vector<bool>();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                (matrix[i][j] == 0) ? zeros->push_back(1) : zeros->push_back(0);
            }
        }

        for (vector<bool>::iterator it = zeros->begin(); it != zeros->end(); ++it)
        {
            if (*it == 1)
            {
                int row = ((it - zeros->begin()) / cols);
                int col = ((it - zeros->begin()) % cols);

                for (int i = 0; i < cols; ++i)
                {
                    matrix[row][i] = 0;
                    matrix[i][col] = 0;
                }
            }
        }
    }

    /* Helper method to print out matrices for questions 1.6 and 1.7 */
    void PrintMatrix(int** matrix, int rows, int cols)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (j == (cols - 1))
                {
                    printf("%d\n", matrix[i][j]);
                }
                else
                {
                    printf("%d%s", matrix[i][j], ", ");
                }
            }
        }
    }

    /*
    Question:    1.8
    Arguments:   Two pointers to character arrays
    Returns:     Boolean
    Description: Given a string input, determine if a second 
                 string input is a rotation of the first input
    Assumptions: None
    */
    bool IsStringRotation(char* str1, char* str2, bool cpp)
    {
        if (strlen(str1) != strlen(str2))
        {
            return false;
        }

        if (cpp)
        {
            return IsStringRotationpp(str1, str2);
        }

        bool is_rotation = false;
        int bufferSize = ((strlen(str1) * 2) + 1);
        char* buffer = (char*)malloc(bufferSize * sizeof(char));

        memset(buffer, 0, (bufferSize * sizeof(char)));
        strcat_s(buffer, bufferSize, str1);
        strcat_s(buffer, bufferSize, str1);

        if (strstr(buffer, str2) != NULL)
        {
            is_rotation = true;
        }

        free(buffer);

        return is_rotation;
    }

    /*
    Question:    1.8 (alternate solution using string)
    Arguments:   Two pointers to character arrays
    Returns:     Boolean
    Description: Given a string input, determine if a second
    string input is a rotation of the first input
    Assumptions: None
    */
    bool IsStringRotationpp(char* str1, char* str2)
    {
        string str = str1;
        str += str1;

        if (str.find(str2) != -1)
        {
            return true;
        }

        return false;
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

    void IsStringRotationTest(bool cpp)
    {
        char* str1 = "waterbottle\0";
        char* str2 = "ottlewaterb\0";
        char* str3 = "rotation\0";

        cout << "Is string: \"" << str2 << "\" a rotation of string: \"" << str1 << "\"? " << (IsStringRotation(str1, str2, cpp) ? "Yes!" : "No!") << endl;
        cout << "Is string: \"" << str3 << "\" a rotation of string: \"" << str1 << "\"? " << (IsStringRotation(str1, str3, cpp) ? "Yes!" : "No!") << endl;
    }

    void CompressStringTest()
    {
        char* str1 = "aabbbbbcddddeeffffffzzzzzzzzzzgggghijkllll\0";
        char* str2 = "abcdefg\0";
        char* str3 = "1111111111111111111111111111111111111111\0";

        cout << "String: \"" << str1 << "\" in compressed form is: \"" << CompressString(str1) << "\"." << endl;
        cout << "String: \"" << str2 << "\" in compressed form is: \"" << CompressString(str2) << "\"." << endl;
        cout << "String: \"" << str3 << "\" in compressed form is: \"" << CompressString(str3) << "\"." << endl;
    }

    void RotateMatrixTest()
    {
        int* matrix[4] = { 
            new int[] { 1, 2, 3, 4 },
            new int[] { 5, 6, 7, 8 },
            new int[] { 9, 10, 11, 12 },
            new int[] { 13, 14, 15, 16 }
        };

        cout << "Matrix: " << endl;
        PrintMatrix(matrix, 4, 4);
        cout << endl << "rotated 90 degrees is: " << endl;
        RotateMatrix(matrix, 4);
        PrintMatrix(matrix, 4, 4);
        cout << endl;
    }

    void ZeroMatrixRowAndColumnTest()
    {
        int* matrix[4] = {
            new int[] { 1, 2, 3, 4 },
            new int[] { 5, 6, 0, 8 },
            new int[] { 9, 10, 11, 12 },
            new int[] { 13, 14, 15, 16 }
        };

        cout << "Matrix: " << endl;
        PrintMatrix(matrix, 4, 4);
        cout << endl << "with zeroed rows and columns is: " << endl;
        ZeroMatrixRowAndColumn(matrix, 4, 4);
        PrintMatrix(matrix, 4, 4);
        cout << endl;
    }
};