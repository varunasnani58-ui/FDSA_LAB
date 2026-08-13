#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;
    int arr[n];
    cout << "Enter book IDs:\n";

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Duplicate Book IDs:\n";

    for(int i = 0; i < n; i++)
    {
        bool duplicate = false;

        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = true;
                break;
            }
        }

        if(duplicate)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++;
        }

        if(count > 1)
            cout << arr[i] << " ";
    }

    return 0;
}
