#include <bits/stdc++.h>
using namespace std;

//#define pair<int,int> ii;

struct Nodo{
	int x,y;
	int suma;
	Nodo(int x1,int y1,int suma1):x(x1),y(y1),suma(suma1){}
};

bool operator <(Nodo a, Nodo b){
	if(a.suma < b.suma)return false;
	else return true;
}

int main(){
	
	int a,b,elem;
	cin>>a>>b;
	vector<vector<int>> graph;
	for(int i=0; i < a ; i++){
		vector<int> aux(b);
		for(int j=0; j < b; j++){
			cin>>elem;
			aux[j]=elem;
		}
		graph.push_back(aux);
	}

	priority_queue<Nodo> q;
	set<pair<int,int>> exp;
	Nodo n(0,0,graph[0][0]);
	q.push(n);
	
	while( q.top().x < a-1 ||  q.top().y < b-1){

		Nodo aux = q.top();q.pop();
		exp.insert(pair<int,int>(aux.x,aux.y));

		if( aux.x+1 <= a-1){
			int suma = aux.suma + graph[aux.x+1][aux.y];
			Nodo newnode(aux.x+1,aux.y,suma);
			if(exp.find({aux.x+1,aux.y}) == exp.end())q.push(newnode);
		}
		if( aux.y+1 <= b-1){
			int suma = aux.suma + graph[aux.x][aux.y+1];
			Nodo newnode(aux.x,aux.y+1,suma);
			if(exp.find({aux.x,aux.y+1}) == exp.end())q.push(newnode);
		}
	}
	cout<< q.top().suma<<endl;

	return 0;
}