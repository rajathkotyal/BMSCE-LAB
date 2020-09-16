//09a_Quick_sort.cpp

#include<iostream>
#include<ctime>
using namespace std;

int partition(int a[],int l,int r){
    int p=a[l],s=l;
    for(int i=l+1;i<r;i++)
        if(a[i]<p){
            s++;
            swap(a[s],a[i]);
        }
    swap(a[l],a[s]);
    return s;
}

void quick_sort(int a[],int l,int r){
    if(l<r){
        int s=partition(a,l,r);
        quick_sort(a,l,s);
        quick_sort(a,s+1,r);
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
    quick_sort(a,0,n);
    cout<<"Sorted: ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl<<"Time: "<<(clock()-start)<<"clock cycles"<<endl;
}