#include<iostream>
using namespace std;

int search(int n,int ele)
{
    int arr[n],i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++){
        if(arr[i]==ele)
            return 1;
    }
    return -1;
}

int main()
{
    int ele,t,n;
    cin>>t;
    
    while(t>0)
    {
        cin>>n>>ele;
        
        cout<<search(n,ele);
        t--;
    }
    return 0;
}
