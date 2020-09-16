//Selection Sort
#include<iostream>
#include<ctime>
using namespace std;

void selection_sort(int a[],int n){
    int min,k;
    for(int i=0;i<n-1;i++){
        min=a[i];
        for(int j=i+1;j<n;j++){
            if(min>a[j]){
                min=a[j];
                k=j;
            }
        }
        int temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int a[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    clock_t start=clock();
    selection_sort(a,n);
    cout<<"Sorted: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Time: "<<(clock()-start)<<endl;
}