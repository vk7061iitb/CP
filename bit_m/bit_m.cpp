#include <bits/stdc++.h>
using namespace std;

// Function to print the bit representation of a number
void printBit(int n)
{
    vector<int> bit_val;
    cout << "Bit representation of " << n << " is: ";
    while (n)
    {
        bit_val.push_back(n % 2);
        n /= 2;
    }
    reverse(bit_val.begin(), bit_val.end());
    for (int i : bit_val)
    {
        cout << i;
    }
    cout << '\n';
}

int main()
{
    // A bit (binary digit) can hold a value of either 1 or 0
    // Computers use the binary (base 2) number system to store data
    // Example: 1 = 0001, 2 = 0010, 9 = 1001

    // initializing 16 bit integer
    int_fast16_t a = 10, b = 2;
    printBit(a);
    printBit(b);

    // Bitwise Operators

    // AND (&): Performs a bitwise AND operation
    // a = 1010, b = 0010 => a & b = 0010
    cout << "a & b: " << (a & b) << endl;

    // OR (|): Performs a bitwise OR operation
    // a = 1010, b = 0010 => a | b = 1010
    cout << "a | b: " << (a | b) << endl;

    // XOR (^): Performs a bitwise XOR (exclusive OR) operation
    // a = 1010, b = 0010 => a ^ b = 1000
    cout << "a ^ b: " << (a ^ b) << endl;

    // NOT (~): Performs a bitwise NOT (complement) operation
    // a = 0000 0000 0000 1010 => ~a = 1111 1111 1111 0101
    // b = 0000 0000 0000 0010 => ~b = 1111 1111 1111 1101
    cout << "~a: " << ~a << " ~b: " << ~b << endl;

    // Left Shift (<<): Shifts bits to the left
    // a << 1 shifts the bits in a to the left by 1 position, filling the rightmost bits with zeros
    // a = 1010 << 1 => 10100
    cout << "a << 1: " << (a << 1) << endl;

    // Right Shift (>>): Shifts bits to the right
    // a >> 1 shifts the bits in a to the right by 1 position. For unsigned types,
    // the leftmost bits are filled with zeros. For signed types, the behavior is implementation-defined
    // a = 1010 >> 1 => 0101
    cout << "a >> 1: " << (a >> 1) << endl;

    // Setting a bit: To set a bit at a specific position to 1
    // Set the 2nd bit of b
    int pos = 1;
    b = b | (1 << pos); // b = 0010 | 0010 => 0010 (no change as bit is already 1)
    cout << "After setting bit at position 1: ";
    printBit(b);

    // Clearing a bit: To clear a bit at a specific position to 0
    // Clear the 2nd bit of b
    b = b & ~(1 << pos); // b = 0010 & 1101 => 0000
    cout << "After clearing bit at position 1: ";
    printBit(b);

    // Toggling a bit: To toggle (invert) a bit at a specific position
    // Toggle the 2nd bit of a
    a = a ^ (1 << pos); // a = 1010 ^ 0010 => 1000
    cout << "After toggling bit at position 1: ";
    printBit(a);

    // Checking a bit: To check if a bit at a specific position is set
    // Check the 3rd bit of a
    pos = 2;
    bool isSet = a & (1 << pos); // a = 1000 & 0100 => 0000 (false)
    cout << "Is the 3rd bit of a set? " << (isSet ? "Yes" : "No") << endl;

    // Example: Counting the number of 1 bits (Hamming Weight)
    int num = 29; // 29 = 11101 in binary
    int count = 0;
    while (num)
    {
        count += num & 1;
        num >>= 1;
    }
    cout << "Number of 1 bits in 29: " << count << endl;

    return 0;
}
