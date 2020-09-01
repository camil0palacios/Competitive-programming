#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Celda{
	int x,y,sum;
	Celda(int x1,int y1, int s): x(x1), y(y1), sum(s){}
};

int main(){
	
	string s1,s2;
	int x1,y1,x2,y2,x,y,s;
	while(cin>>s1>>s2){
		int mat[8][8];
		y1 = s1[0] - 'a';
		x1 = s1[1] - '0'- 1;
		y2 = s2[0] - 'a';
		x2 = s2[1] - '0' - 1;
		set<pair<int,int>> visited;
		queue<Celda> q;
		q.push(Celda(x1,y1,0));
		while( (q.front().x != x2 || q.front().y != y2) && q.size()){ //Bfs
			x = q.front().x;
			y = q.front().y;
			s = q.front().sum;
			q.pop();
			if(visited.find({x,y}) == visited.end()){
				visited.insert({x,y});
				if( x + 2 <= 7 && y + 1 <= 7){q.push(Celda(x+2,y+1,s+1));}
				if( x + 2 <= 7 && y - 1 >= 0){q.push(Celda(x+2,y-1,s+1));}
				if( x - 2 >= 0 && y + 1 <= 7){q.push(Celda(x-2,y+1,s+1));}
				if( x - 2 >= 0 && y - 1 >= 0){q.push(Celda(x-2,y-1,s+1));}
				if( x + 1 <= 7 && y + 2 <= 7){q.push(Celda(x+1,y+2,s+1));}
				if( x - 1 >= 0 && y + 2 <= 7){q.push(Celda(x-1,y+2,s+1));}
				if( x + 1 <= 7 && y - 2 >= 0){q.push(Celda(x+1,y-2,s+1));}
				if( x - 1 >= 0 && y - 2 >= 0){q.push(Celda(x-1,y-2,s+1));}
			}
		}
		if(q.size() > 0)cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<q.front().sum<<" knight moves."<<endl;
		else cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<0<<" knight moves."<<endl;
	}
	return 0;
}