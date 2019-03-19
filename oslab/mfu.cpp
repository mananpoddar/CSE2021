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
	int freq[10000];
	memset(freq,0,sizeof(freq));
	int pos[10000];
	memset(pos,-1,sizeof(pos));
	j=0;
	int page_fault=0;
	for(i=0;i<size;i++)
	{
		if(freq[arr[i]]==0){
			if(j!=n)
			{
				cout<<"Page Fault.."<<endl;
				cout<<"Page "<<arr[i]<<" is inserted in the memory "<<endl;
				j++;
				freq[arr[i]]=1;
				pos[arr[i]]=i;
			}
			else
			{
				int k,ma=-1e9,l=-1;
				for(k=0;k<10000;k++)
				{
					if((freq[k]!=0)&&(freq[k]>=ma))
					{
						if((freq[k]==ma)&&(pos[k]<pos[l]))
							l=k;
						if(freq[k]!=ma)
							l=k;
						ma=freq[k];
					}
				}
				cout<<"Page Fault.."<<endl;
				cout<<"Page "<<arr[i]<<" replaced page "<<l<<endl;
				freq[l]=0;
				freq[arr[i]]=1;
				pos[l]=-1;
				pos[arr[i]]=i;
			}
			page_fault++;
		}
		else{
			cout<<"Page "<<arr[i]<<" hits!!"<<endl;
			freq[arr[i]]++;
		}
		cout<<"The memory contains ";
		for(int k=0;k<10000;k++)
		{
			if(freq[k]!=0){
				cout<<k<<" ";
			}
		}
		cout<<endl;

	}
	cout<<"The total number of page fault is "<<page_fault<<endl;
	return 0;
}