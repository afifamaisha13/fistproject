#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of 1st array: ";
    cin >> n;
    if (n <= 20)
    {
        cout << "Size of the first array must be greater than 20." << endl;
        return 0;
    }

    vector<int> arr1(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m = n / 10;
    vector<int> arr2(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    vector<int> div;
    vector<int> rem;

    for (int i = 0; i < n; ++i)
    {
        int value1 = arr1[i];
        int value2 = arr2[i % m];

        if (value2 == 0)
        {
            cout << "Skipping division by zero at index " << i << "." << endl;
            div.push_back(0);
            rem.push_back(0);
            continue;
        }

        int div1 = static_cast<int>(ceil(static_cast<double>(value1) / value2));
        int rem1 = value1 % value2;

        div.push_back(div1);
        rem.push_back(rem1);
    }

    cout << "Divisor array: ";
    for (int t : div)
    {
        cout << d << " ";
    }
    cout << endl;

    cout << "Remainder array: ";
    for (int x : rem)
    {
        cout << x << " ";
    }
    cout << endl;

}

