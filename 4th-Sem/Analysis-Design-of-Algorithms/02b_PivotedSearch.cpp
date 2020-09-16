//Pivoted Search
#include<iostream>
using namespace std;

void binsearch(int low,int high,int arr[],int key){
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid] == key){
            cout<<"Element found at: "<<mid+1<<endl;
            break;
        }
        else if(arr[mid]>key)
            high=mid-1;
        else 
            low=mid+1;
    }
}

int main(){
    int n,i,key,p;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n];
    cout<<"Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            p=i;
    }
    cout<<"Enter key: ";
    cin>>key;
    if(key>arr[p])
        binsearch(0,p,arr,key);
    else
        binsearch(p+1,n-1,arr,key);
    
}