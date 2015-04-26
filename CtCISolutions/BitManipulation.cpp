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

    /*
    Question:    5.4
    Arguments:   N/A
    Returns:     N/A
    Description: What does the code ((n & (n - 1)) == 0) do? (No code required)
    Assumptions: <none>
    Answer:      We can see from the example where n = 13:
                 n         = 00001101
                 n - 1     = 00001100
                 n & n - 1 = 00001100
                 that n & n - 1 will always be equivalent to the value of n - 1 when the
                 subtraction does not cause a "shift" of the bits to. However, consider an
                 example where such a shift does occur:
                 n         = 00110100
                 n - 1     = 00110011
                 n & n - 1 = 00110000
                 From this example, we can see that any bits that are contained
                 within the shift will be set to zero after the AND operation.
                 Therefore, the AND operation will only return a value of zero
                 if the value of n - 1 entirely contained within the shift. We
                 can see that this will happen if and only if has a single bit
                 set, since any additional bit set would skew the shift to that
                 bit: 01100000 -> 00111111, 01000100 -> 01000011, 10000010 ->
                 10000001, etc. Since all single bits are equivalent to powers
                 of two in binary representation, this means the above code
                 will only return a true value if n is a power of two (ignoring
                 the trivial case where n = 0).
    */
    
    /*
    Question:    5.6
    Arguments:   An integer
    Returns:     An integer
    Description: Given an integer, flip the bits with even indices to the
	             values of the bits with odd indices, and vice versa
    Assumptions: A 32-bit integer is used
    */
    int SwapBitIndices(int n)
    {
        return (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));
    }

    void InsertBitSubsequenceTest()
    {
        int n1 = 0x7FFF01CE, n2 = 477;
        short i = 4, j = 12;

        cout << bitset<32>(n1) << " with: " << bitset<32>(n2) << " inserted into between indices " << i << " and " << j << " is: ";
        cout << bitset<32>(InsertBitSubsequence(n1, n2, i, j)) << "." << endl;
    }

    void SwapBitIndicesTest()
    {
        int n = 0xdeadbeef;

        cout << bitset<32>(n) << " with even and odd bits swapped is: \n"  << bitset<32>(SwapBitIndices(n)) << "." << endl;
    }
}