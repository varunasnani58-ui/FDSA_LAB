#include <iostream>
using namespace std;

int binarySearchLoop(int a[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binarySearchRecursive(int a[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == target)
        return mid;
    else if (a[mid] < target)
        return binarySearchRecursive(a, mid + 1, high, target);
    else
        return binarySearchRecursive(a, low, mid - 1, target);
}

int main()
{
    int n, target;

    cout << "Enter number of books: ";
    cin >> n;

    int a[n];

    cout << "Enter sorted book codes: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter book code to search: ";
    cin >> target;

    int result1 = binarySearchLoop(a, n, target);
    int result2 = binarySearchRecursive(a, 0, n - 1, target);

    if (result1 != -1)
    {
        cout << "Loop method position: " << result1 + 1 << endl;
        cout << "Recursive method position: " << result2 + 1 << endl;
    }
    else
    {
        cout << "Book code not found" << endl;
    }

    return 0;
}
