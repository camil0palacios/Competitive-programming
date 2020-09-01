#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct node{
	int a, sum;
	node(int x,int y): a(x), sum(y){}
};

int main(){
	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		string s;
		queue<node> q;
		set<int> cont;
		q.push(node(a,0));
		while(!q.empty() && q.front().a != b){
			int x = q.front().a;
			int sum =  q.front().sum;
			q.pop();
			if(cont.find(x) !=  cont.end())continue;
			cont.insert(x);
			q.push(node(x+1,sum+1));
			s = to_string(x);
			reverse(s.begin(), s.end());
			x = stoi(s);
			q.push(node(x,sum+1));
		}
		cout<<q.front().sum<<endl;

	}
	return 0;
}