#include <iostream> 
using namespace std;
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main()
{
    int a,b;
    cout<<"Enter X : ";
    cin>>a;
    cout<<"Enter Y : ";
    cin>>b;
    cout<<gcd(a,b);
    cout<<"\n\n";
}