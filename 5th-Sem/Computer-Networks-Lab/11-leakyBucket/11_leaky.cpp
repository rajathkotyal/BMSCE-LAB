#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define bucketSize 500

void bucketInput(int a,int b)
{
	if(a > bucketSize)
		cout<<"\n\t\tBucket overflow";
	else{
		sleep(5);
		while(a > b){
			cout<<"\n\t\t"<<b<<" bytes outputted.";
			a-=b;
			sleep(5);
		}
		if(a > 0)
			cout<<"\n\t\tLast "<<a<<" bytes sent\t";
		cout<<"\n\t\tBucket output successful";
	}
}
int main()
{
	int op,pktSize;
	cout<<"Enter output rate : ";
	cin>>op;
	for(int i=1;i<=5;i++)
	{
		sleep(rand()%10);
		pktSize=rand()%700;
		cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
		bucketInput(pktSize,op);
	}
	cout<<endl;
	return 0;
}
