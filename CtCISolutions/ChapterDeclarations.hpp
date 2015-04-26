#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

namespace CtCISolutions
{
    /* CHAPTER 1: ARRAYS AND STRINGS */
    // Solutions
    bool AllCharactersUnique(char *str);
    void ReverseString(char *str);
    bool IsStringPermutation(char *str1, char *str2);
    void UrlEncodeSpaces(char* str1, char* str2);
    char* CompressString(char* str);
    bool IsStringRotation(char* str1, char* str2, bool cpp);
    bool IsStringRotationpp(char* str1, char* str2);
    void RotateMatrix(int** matrix, int width);
    void ZeroMatrixRowAndColumn(int** matrix);

    // Test cases
    void AllCharactersUniqueTest();
    void ReverseStringTest();
    void IsStringPermutationTest();
    void UrlEncodeSpacesTest();
    void CompressStringTest();
    void IsStringRotationTest(bool cpp);
    void RotateMatrixTest();
    void ZeroMatrixRowAndColumnTest();

    /* CHAPTER 2: LINKED LISTS */

    /* CHAPTER 6: BIT MANIPULATION */
    // Solutions
    int InsertBitSubsequence(int n1, int n2, short i, short j);
    int SwapBitIndices(int n);

    // Test cases
    void InsertBitSubsequenceTest();
    void SwapBitIndicesTest();
};