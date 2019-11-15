#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
000000000
011100101
010101000
110010001
010011010
111101011
001011000
110000111
*/

int main()
{
    int n;
    cin >> n;
    int *a = new int[n], min = INT32_MAX, temp;
    for (size_t i = 0; i < n; i++)
    {
        bitset<9> bit;
        cin >> bit;
        a[i] = bit.count();
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            temp = abs(a[i] - a[j]);
            if (temp < min)
                min = temp;
        }
    }
    cout << temp << endl;
}