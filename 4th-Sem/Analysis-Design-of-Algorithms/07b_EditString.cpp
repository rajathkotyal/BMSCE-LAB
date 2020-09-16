//Edit String
#include<iostream>
using namespace std;

int len(char str[]){
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}

int min(int a,int b,int c){
    int temp=a<b?a:b;
    return temp<c?temp:c;
}

int edit(char str1[],char str2[],int l1,int l2){
    if(l1==0)
        return l2;
    if(l2==0)
        return l1;
    if(str1[l1-1]==str2[l2-1])
        return edit(str1,str2,l1-1,l2-1);
    return 1+min(edit(str1,str2,l1,l2-1),edit(str1,str2,l1-1,l2),edit(str1,str2,l1-1,l2-1));
}

int main(){
    char str1[10],str2[10];
    int l1,l2;
    cout<<"Enter string1: ";
    cin>>str1;
    cout<<"Enter string2: ";
    cin>>str2;
    l1=len(str1);
    l2=len(str2);
    cout<<"Edit distance="<<edit(str1,str2,l1,l2);
}