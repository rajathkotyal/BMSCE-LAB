#include<iostream>
using namespace std;
int a[15][15];

int palin_len(char str[],int n){
    for(int i=0;i<n;i++)
        a[i][i]=1;
    for(int str_len=2;str_len<=n;str_len++){
        for(int i=0;i<n-str_len+1;i++){
            int j=i+str_len-1;
            if(str[i]==str[j]){
                if(str_len==2)
                    a[i][j]=2;
                else
                    a[i][j]=a[i+1][j-1]+2;
            }
            else
                a[i][j]=max(a[i][j-1],a[i+1][j]);
        }
    }
    return a[0][n-1];
}

int main(){
    char str[20];
    cout<<"Enter the string: ";
    cin>>str;
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    cout<<"Length of longest palindrome: "<<palin_len(str,len)<<endl;
}