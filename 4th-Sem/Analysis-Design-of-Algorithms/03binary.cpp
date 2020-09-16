#include<iostream>
using namespace std;

void search(int arr[],int key,int n)
{
	int first,mid,last;
	int i,j,count=0,k;
	first=0;
	last=n-1;
	mid=(first+last)/2;
	while(first<=last)
	{
		if(arr[mid]<key)
		    first=mid+1;
		else if(arr[mid]==key)
			break;
		else
			last=mid-1;

		mid=(first+last)/2;
	}
	 	if(first>last)
	 	{
	 	cout<<"-1-10\n";
	 	return;
	 	}	
		i=first;
		for(i=first;i<last;i++)
		{
			if(arr[i]==key)
			{
			cout<<"FIRST OCCURANCE: "<<i;
			break;
			}
		}
		j=i-1;
		for(k=i;k<n;k++)
		{
			if(key==arr[i])
			{   j++;
			    count++;
			}
		}
		cout<<"\n LAST OCCURANCE:   " <<j<<endl;
		cout<<"COUNT:   "<<count<<endl;
}				

int main()
{
	int a[10],i,k,l;
	cout<<"ENTER ARRAY SIZE :  ";
    cin>>l;

	cout<<"ENTER ARRAY ELEMENTS IN SORTED FORMAT :  ";
	for(i=0;i<l;i++)
	    cin>>a[i];
	cout<<"ENTER ELEMENTS TO BE SEARCHED:  ";
	cin>>k;
	search(a,k,l);
}