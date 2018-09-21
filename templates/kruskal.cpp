#include <bits/stdc++.h>
using namespace std;

class Disjoint_set{
    private:
        unordered_map<int,int> p;
        unordered_map<int,int> rank;
    public:
        Disjoint_set(): p(),rank(){}
        void make_set(int d){
            for(int i=0; i < d ; i++){
                p.insert({i,i});
                rank.insert({i,0});
            }
        }
        int Find_set(int i){
            if(p[i]==i)return i;
            else p[i]=Find_set(p[i]);
        }
        void Union_set(int a, int b){
            int x = Find_set(a), y = Find_set(b);
            if(x == y){
                return;
            }
            else{
                if(rank[x] > rank[y]) p[y]=x;
                else{
                    p[x] = y;
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
};

struct Edge{
	int u, v, weigth;
	bool operator<(Edge &other){
		return weigth < other.weigth;
	}
};

void kruskal(Disjoint_set &s, vector<Edge>& Edges,vector<Edge>& result, int &cost){
	sort(Edges.begin(), Edges.end());
	for(Edge e: Edges){
		if(s.Find_set(e.u) != s.Find_set(e.v)){
			cost += e.weigth;
			s.Union_set(e.u,e.v);
			result.push_back(e);
		}
	}
}

int main(){
	
	vector<Edge> Edges,result;
	Disjoint_set s;
	int n,q,a,b,w,cost=0;
	cin>>n; // cantidad de nodos
	s.make_set(n); // creo el conjunto disjunto de 0 a n-1;
	cin>>q; //cantidad de aristas
	while(q--){
		cin>>a>>b>>w; //añado nodo a y b con su respectivo costo
		Edge aux;
		a--;b--;
		aux.u=a;aux.v=b;aux.weigth=w;
		Edges.push_back(aux);
	}
	kruskal(s,Edges,result,cost);
	cout<<cost<<endl;
	for(auto &i: result)
		cout<<i.u<<" "<<i.v<<" "<<i.weigth<<endl;
	return 0;
}