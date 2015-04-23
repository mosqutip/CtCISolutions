#include "ChapterDeclarations.hpp"

namespace CtCISolutions
{
    /*
    Question:    5.1
    Arguments:   Two integers and two short indices
    Returns:     Integer
    Description: Given two 32-bit integers and two short indices, bitwise
                 insert the second 32-bit integer into the first between
                 the first lower) and second (higher) indices
    Assumptions: The indices have exactly enough distance to hold the number
                 The second index (j) is the larger of the two
    */
    int InsertBitSubsequence(int n1, int n2, short i, short j)
    {
        n2 <<= i;
        int x = ~0;
        x <<= (j + 1);
        x |= ((1 << i) - 1);
        return (n1 |= n2);
    }

    void InsertBitSubsequenceTest()
    {
        int n1 = 0x7FFF01CE, n2 = 477;
        short i = 4, j = 12;

        cout << bitset<32>(n1) << " with: " << bitset<32>(n2) << " inserted into between indices " << i << " and " << j << " is: ";
        cout << bitset<32>(InsertBitSubsequence(n1, n2, i, j)) << "." << endl;
    }
}