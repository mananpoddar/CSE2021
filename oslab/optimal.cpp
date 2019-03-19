#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,size=0;
	int arr[10000];
	cout<<"Enter the number of page slots"<<endl;
	cin>>n;
	cout<<"Enter the number of pages "<<endl;
	cin>>size;
	cout<<"Enter the pages"<<endl;
	for(i=0;i<size;i++){
		cin>>arr[i];
	}
	int pos[10000];
	memset(pos,-1,sizeof(pos));
	j=0;
	int next[10000],page_fault=0;
	for(i=0;i<size;i++)next[i]=1e9;
	for(i=0;i<size;i++)
	{
		if(pos[arr[i]]!=-1)
		{
			next[pos[arr[i]]]=i;
		}
		pos[arr[i]]=i;
	}
	
	memset(pos,-1,sizeof(pos));
	j=0;
	int enter[10000];
	memset(enter,-1,sizeof(enter));
	for(i=0;i<size;i++)
	{
		if(enter[arr[i]]==-1)
		{
			if(j!=n)
			{
				cout<<"Page Fault.."<<endl;
				cout<<"Page "<<arr[i]<<" is inserted in the memory "<<endl;
				j++;
				pos[arr[i]]=next[i];
				enter[arr[i]]=i;
			}
			else
			{	
				int k,ma=-1e9,l=-1;
				for(k=0;k<10000;k++)
				{
					if((enter[k]!=-1)&&(pos[k]>=ma))
					{

						if((ma==pos[k])&&(enter[k]<enter[l]))
							l=k;
						if(ma!=pos[k])
							l=k;
						ma=pos[k];
					}
				}
				cout<<"Page Fault.."<<endl;
				cout<<"Page "<<arr[i]<<" replaced page "<<l<<endl;
				enter[l]=-1;
				enter[arr[i]]=i;
				pos[arr[i]]=next[i];
			}
			page_fault++;
		}
		else
		{
			cout<<"Page "<<arr[i]<<" hits!!"<<endl;
			enter[arr[i]]=i;
			pos[arr[i]]=next[i];

		}
		cout<<"The memory contains ";
		for(int k=0;k<10000;k++)
		{
			if(enter[k]!=-1){
				cout<<k<<" ";
			}
		}
		cout<<endl;
	}
	cout<<"The total number of page fault is "<<page_fault<<endl;

	return 0;
}