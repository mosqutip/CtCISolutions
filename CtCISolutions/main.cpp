#include "ChapterDeclarations.hpp"

using namespace CtCISolutions;

void main()
{
    int chapter = 2;

    switch (chapter)
    {
        case 1:
            AllCharactersUniqueTest();
            ReverseStringTest();
            IsStringPermutationTest();
            UrlEncodeSpacesTest();
            IsStringRotationTest(false);
            CompressStringTest();
            RotateMatrixTest();
            ZeroMatrixRowAndColumnTest();
            break;
        case 2:
            RemoveDuplicatesTest();
            FindNthToLastNodeTest();
            DeleteNodeTest();
            SumLinkedListDigitsTest();
            IsLinkedListPalindromeTest();
            break;
        case 5:
            InsertBitSubsequenceTest();
            SwapBitIndicesTest();
            NumberOfBitsToSwapTest();
            break;
        default:
            break;
    }

    int x;
    cin >> x;
}