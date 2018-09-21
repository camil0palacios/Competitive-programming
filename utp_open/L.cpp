#include <bits/stdc++.h>
using namespace std;

vector<long int> segtree;

void constructTree(vector<long int>& input,long int low, long int high, long int pos){
	if(low == high){
		segtree[pos]=input[low];return;
	}
	long int mid = (low+high)/2;
	constructTree(input,low,mid,2*pos+1);
	constructTree(input,mid+1,high,2*pos+2);
	segtree[pos] = max(segtree[2*pos+1],segtree[2*pos+2]);
}

int RMQ(long int qlow,long int qhigh, long int low, long int high,long int pos){
	if(qlow <= low && qhigh >= high){return segtree[pos];}
	if(qlow > high || qhigh < low){return INT_MIN;}
	int mid= (low+high)/2;
	return max(RMQ(qlow,qhigh,low,mid,2*pos+1),RMQ(qlow,qhigh,mid+1,high,2*pos+2));
}

void updateTree(long int pos1,long int value, long int low,long int high,long int pos){
	if(low == high){segtree[pos]+=value;return;}
	long int mid=(low+high)/2;
	if(low <= pos1 && pos1 <= mid)updateTree(pos1,value,low,mid,2*pos+1);
	else updateTree(pos1,value,mid+1,high,2*pos+2);
	segtree[pos]=max(segtree[2*pos+1],segtree[2*pos+2]);
}

int main(){

	long int n,q;
	cin>>n>>q;
	vector<long int> input(n);
	for(auto &i: input)cin>>i;
	segtree.resize(4*n);
	constructTree(input,0,input.size()-1,0);
	long int op,a,b;
	while(q--){
		cin>>op>>a>>b;
		if(op == 1){
			updateTree(a-1,b,0,input.size()-1,0);
		}
		if(op == 2){
			cout<<RMQ(a-1,b-1,0,input.size()-1,0)<<endl;
		}

	}
	return 0;
}
