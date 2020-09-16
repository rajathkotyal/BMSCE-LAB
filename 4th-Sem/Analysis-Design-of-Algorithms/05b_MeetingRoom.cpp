//Meetinng Room
#include<iostream>
#include<ctime>
using namespace std;

void meeting(int S[],int F[],int m[],int n){
    for(int i=1;i<n;i++){
        int key1=S[i];
        int key2=F[i];
        int key3=m[i];
        int j=i-1;
        while(j>=0 && S[j]>key1){
            S[j+1]=S[j];
            F[j+1]=F[j];
            m[j+1]=m[j];
            j--;
        }
        S[j+1]=key1;
        F[j+1]=key2;
        m[j+1]=key3;
    }
    cout<<"Meetings: "<<endl;
    cout<<m[0]<<" from "<<S[0]<<" to "<<F[0]<<endl;
    int i=0;
    while(i+1<n){
        int j=i+1;
        while(j<n){
            if(F[i]<=S[j]){
                cout<<m[j]<<" from "<<S[j]<<" to "<<F[j]<<endl;
                i=j;
            }  
            j++;  
        } 
    }
}

int main(){
    int n;
    cout<<"Enter total number of meetings: ";
    cin>>n;
    int S[n],F[n],m[n];
    for(int i=0;i<n;i++){
        m[i]=i+1;
        cout<<"Start time of meeting "<<(i+1)<<": ";
        cin>>S[i]; 
        cout<<"Finish time of meeting "<<(i+1)<<": ";
        cin>>F[i]; 
        cout<<endl;
    }
    meeting(S,F,m,n);
    return 0;
}