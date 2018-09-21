#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<string> mapa;
vector<vector<bool>> visited;

void direction(char dir,int &x,int &y){
	if(visited[x][y])return;
	visited[x][y]=true;
	if(dir == '>'){
		y++;
		while(y < mapa[x].size()){
			if(visited[x][y])return;
			if(mapa[x][y] == '.'){visited[x][y]=true;y++;}
			if(mapa[x][y] == '*')return;
			if(mapa[x][y] == 'v' || mapa[x][y] == '<' || mapa[x][y] == '>' || mapa[x][y] == '^')return direction(mapa[x][y],x,y);
		}
	}
	else if(dir == '<'){
		y--;
		while(y >= 0){
			if(visited[x][y])return;
			if(mapa[x][y] == '.'){visited[x][y]=true;y--;}
			if(mapa[x][y] == '*')return;
			if(mapa[x][y] == 'v' || mapa[x][y] == '<' || mapa[x][y] == '>' || mapa[x][y] == '^')return direction(mapa[x][y],x,y);		}
	}
	else if(dir == '^'){
		x--;
		while(x >= 0){
			if(visited[x][y])return;
			if(mapa[x][y] == '.'){visited[x][y]=true;x--;}
			if(mapa[x][y] == '*')return;
			if(mapa[x][y] == 'v' || mapa[x][y] == '<' || mapa[x][y] == '>' || mapa[x][y] == '^')return direction(mapa[x][y],x,y);
		}
	}
	else if(dir == 'v'){
		x++;
		while(x < mapa.size()){
			if(visited[x][y])return;
			if(mapa[x][y] == '.'){visited[x][y]=true;x++;}
			if(mapa[x][y] == '*')return;
			if(mapa[x][y] == 'v' || mapa[x][y] == '<' || mapa[x][y] == '>' || mapa[x][y] == '^')return direction(mapa[x][y],x,y);
		}
	}
}

int main(){

	int x,y;
	cin>>x>>y;
	mapa.assign(y,string());
	visited.assign(y,vector<bool> (x,false));
	for(auto &i: mapa)cin>>i;
	x=0;y=0;
	direction(mapa[x][y],x,y);
	if(mapa[x][y] == '*')cout<<'*'<<endl;
	else cout<<'!'<<endl;

	return 0;
}
