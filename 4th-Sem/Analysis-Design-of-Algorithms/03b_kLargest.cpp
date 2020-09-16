//K Largest Element
#include<iostream>
using namespace std;

int k_largest(int a[],int n,int k){
    int max,m;
    for(int i=0;i<n-1;i++){
        max=a[i];
        m=i;
        for(int j=i+1;j<n;j++){
            if(max<a[j]){
                max=a[j];
                m=j;
            }
        }
        int temp=a[i];
        a[i]=a[m];
        a[m]=temp;
        if(i==k-1)
            return max;
    }
    return a[n-1];
}

int main(){
    int n,max,k;
    cout<<"Enter n: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter k:";
    cin>>k;
    int res=k_largest(a,n,k);
    cout<<"kth largest number: "<<res<<endl;
}