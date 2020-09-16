//Insertion Sort
#include<iostream>
#include<ctime>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Elements: ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    clock_t start=clock();
    insertion_sort(arr,n);
    clock_t stop=clock();
    cout<<endl<<"Duration: "<<stop-start<<" clocks"<<endl;
}