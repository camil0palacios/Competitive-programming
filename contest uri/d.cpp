#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef pair<int,int> ii;
set<ii> infect;

int bfs(int x, int y, int n, int m,vector<string> &g){
	int ans = 0;
	infect.insert(ii(x,y));
	int x1 = x-1, x2 = x+1, y1 = y-1, y2 = y+1;
	while(x1 >= 0 || x2 < n || y1 >= 0 || y2 < m){
		bool inf = false;
		if(y1 >= 0 && g[x][y1] == '#' && infect.count(ii(x,y1)) == 0){infect.insert(ii(x,y1));inf = true;}
		if(y2 < m && g[x][y2] == '#' && infect.count(ii(x,y2)) == 0){infect.insert(ii(x,y2));inf = true;}
		if(x1 >= 0 && g[x1][y] == '#' && infect.count(ii(x1,y)) == 0){infect.insert(ii(x1,y));inf = true;}
		if(x2 < n && g[x2][y] == '#' && infect.count(ii(x2,y)) == 0){infect.insert(ii(x2,y));inf = true;}
		--y1;++y2;--x1;++x2;
		if(inf)ans++;
	}
	return ans;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	vector<string> b(n);
	for(auto &i: b)cin>>i;

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m ; j++){
			if(b[i][j] == '@'){
				int tmp = bfs(i,j,n,m,b);
				ans = max( tmp, ans); 
			}
		}
	}
	if(infect.size() == n*m)cout<<ans<<endl;
	else cout<<-1<<endl;

	return 0;
}