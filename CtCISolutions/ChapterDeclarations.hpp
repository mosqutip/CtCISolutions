#include <iostream>
#include <string>

using namespace std;

namespace CtCISolutions
{
    /* CHAPTER 1: ARRAYS AND STRINGS */
    // Methods for questions
    bool AllCharactersUnique(char *str);
    void ReverseString(char *str);
    bool IsStringPermutation(char *str1, char *str2);
    void UrlEncodeSpaces(char* str1, char* str2);
    char* CompressString(char* str);
    bool IsStringRotation(char* str1, char* str2, bool cpp);
    bool IsStringRotationpp(char* str1, char* str2);
    void RotateMatrix(int** matrix, int width);

    // Test cases
    void AllCharactersUniqueTest();
    void ReverseStringTest();
    void IsStringPermutationTest();
    void UrlEncodeSpacesTest();
    void CompressStringTest();
    void IsStringRotationTest(bool cpp);
    void RotateMatrixTest();

    /* CHAPTER 2: LINKED LISTS */
};