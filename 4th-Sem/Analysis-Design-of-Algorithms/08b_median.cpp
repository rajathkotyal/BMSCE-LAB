#include<iostream>
using namespace std;

void merge(int a[],int b[],int c[],int n){
    int i=0,j=0,k=0;
    while(i<n && j<n){
        if(b[i]<c[j])
            a[k++]=b[i++];
        else
            a[k++]=c[j++];
    }
    if(i==n)
        for(int l=j;l<n;l++)
            a[k++]=c[l];
    else
        for(int l=i;l<n;l++)
            a[k++]=b[l];
}

int main(){
    int n;
    cout<<"Enter the size of two arrays: ";
    cin>>n;
    int a[n],b[n],c[n*2];
    cout<<"Enter first array: ";
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<"Enter second array: ";
    for(int i=0;i<n;i++)
        cin>>c[i];
    merge(a,b,c,n);
    cout<<"Median= "<<(a[n-1]+a[n])/2<<endl;
}