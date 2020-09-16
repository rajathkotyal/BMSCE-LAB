#include<iostream>
using namespace std;

void hanoi(int disk,char source,char dest,char aux)
{
    if(disk==1)
    {
        cout<<"                         Move Disk  "<<disk<<"  From  "<<source<<"  to  "<<dest<<endl<<endl;
        return;
    }
        hanoi(disk-1,source,aux,dest);
        cout<<"                         Move Disk  "<<disk<<"  From  "<<source<<"  to  "<<dest<<endl<<endl;
        hanoi(disk-1,aux,dest,source);
}

int main()
{
    int disk;
    cout<<"                         Enter number of disks : ";
    cin>>disk;
    cout<<endl;
    hanoi(disk,'A','B','C');
    return 0;
}
