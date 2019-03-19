#include<bits/stdc++.h>
using namespace std;

int first_fit(int b,int process_size,int * block){
	int index=-1;
	for(int i =0;i<b;i++){
		if(block[i]>=process_size){
			index = i;
			break;
		}
	}
	return index;
}

int main(){
	int b,p;
	cin>>b>>p;

	int block[b],process[p],allocated[p];
	//inputting blocks
	for(int i=0;i<b;i++)
		cin>>block[i];
	//inputting process
	for(int i=0;i<p;i++)
		cin>>process[i];

	for(int ind=0;ind<p;ind++){
		int index = first_fit(b,process[ind],block);
		if(index==-1){
			allocated[ind] = -1;
			continue;
		}
		block[index] = block[index] - process[ind];
		if(block[index]==0)block[index]=-1;
		allocated[ind] = index;
	}

	for(int i=0;i<p;i++){
		if(allocated[i]!=-1)
		cout<<"process "<< i+1<<" allocated to "<<allocated[i]+1<<endl;
		else{
			cout<<"process "<< i+1<<" couldn't allocated"<<endl;
		}	
	}	
}