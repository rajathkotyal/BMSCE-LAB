#include<iostream>
using namespace std;

int IsEven(int n){
    int count=0;
    while(n>0){
        if(n%2==1)
            count++;
        n/=2;
    }
    if(count%2==0)
        return 1;
    else
        return 0;
}

int sum(int even_one[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        while(even_one[i]>0){
            int temp=even_one[i]%10;
            sum+=temp;
            even_one[i]/=10;
        }
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter no of elements in array: ";
    cin>>n;
    int a[n],even_one[n],j=0;
    cout<<"Enter elements in array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(IsEven(a[i])){
            even_one[j]=a[i];
            j++;
        }
    }
    cout<<"Sum of digits of elements with even no of ones in its binary representation= "<<sum(even_one,j)<<endl;
}