#include <iostream>
using namespace std;

int main()
{
    cout<< "Enter number of items: ";
    int n, hours;

    cin >> n;

    int a[n];
    cout<< "Enter the items: ";

    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout<< "Enter the number of hours: ";
    cin >> hours;

    int r = hours  % n;

    for(int i = r; i < n; i++)
        cout << a[i] << " ";

    for(int i = 0; i < r; i++)
        cout << a[i] << " ";

    return 0;
}
