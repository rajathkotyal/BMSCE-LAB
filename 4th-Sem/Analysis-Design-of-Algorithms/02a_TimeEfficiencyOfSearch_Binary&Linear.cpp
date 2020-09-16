//Time Efficiency of Search
#include<iostream>
#include<ctime>
using namespace std;

int binsearch(int low,int high,int arr[],int key){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == key){
            cout<<"Element found at: "<<mid+1<<endl;
            return 1;
        }
        else if(arr[mid]>key)
            return binsearch(low,mid-1,arr,key);
        else 
            return binsearch(mid+1,high,arr,key);
    }
    return -1;
}


int linsearch(int arr[],int n,int ele,int i)
{
    while(i<n){
        if(arr[i]==ele){
            cout<<"Element found at: "<<i+1<<endl;
            return 1;
        }
        else  
           return linsearch(arr,n,ele,i+1);
    }
    return -1;
}

int main(){
    int n,key,res;
    clock_t start,stop;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter key: ";
    cin>>key;
    cout<<"**LINEAR SEARCH**"<<endl;
    start=clock();
    res=linsearch(arr,n,key,0);
    if (res==-1)
        cout<<"Element not found"<<endl;
    stop=clock();
    cout<<"Duration: "<<stop-start<<"clocks"<<endl;
    cout<<"**BINARY SEARCH**"<<endl;
    start=clock();
    res=binsearch(0,n-1,arr,key);
    if (res==-1)
        cout<<"Element not found"<<endl;
    stop=clock();
    cout<<"Duration: "<<stop-start<<"clocks"<<endl;
}