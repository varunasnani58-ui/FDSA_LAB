#include<iostream>
using namespace std;

class Search
{
public:

int iterativeSearch(int arr[100], int n, int key)
{
    bool found=false;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found=true;
            return i+1;
        }
    }

    if(!found)
        return -1;
}

int recursiveSearch(int arr[100], int n, int key, int count)
{
    if(count>=n)
        return -1;

    if(arr[count]==key)
        return count+1;
    else
        return recursiveSearch(arr,n,key,count+1);
}
};

int main()
{
    int plates[100],n,key;
    int result1,result2;

    cout<<"Enter the number of vehicles parked: ";
    cin>>n;

    cout<<"Enter the Vehicle Plate Numbers: ";
    for(int i=0;i<n;i++)
    {
        cin>>plates[i];
    }

    cout<<"Enter the Plate Number you want to search: ";
    cin>>key;

    Search s;

    result1=s.iterativeSearch(plates,n,key);
    cout<<"Iterative search position: "<<result1<<endl;

    result2=s.recursiveSearch(plates,n,key,0);
    cout<<"Recursive search position: "<<result2<<endl;

    return 0;
}
