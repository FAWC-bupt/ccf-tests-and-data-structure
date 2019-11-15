#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define LEN 9

/*
8
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
    int n, xi, xj, min = INT32_MAX;
    cin >> n;
    bitset<LEN> *a = new bitset<LEN>[n], temp;
    for (size_t i = 0; i < n; i++)
    {
        bitset<LEN> bit;
        cin >> bit;
        a[i] = bit;
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            temp = a[i] ^ a[j];
            if (temp.count() < min)
            {
                min = temp.count();
                xi = i;
                xj = j;
            }
        }
    }
    cout << min << " " << xi << " " << xj << endl;
}
