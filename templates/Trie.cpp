#include <bits/stdc++.h>
using namespace std;

struct Node{
  map<char, Node*> edges;
  int counter;
  bool isTerm;
  Node():counter(0),edges(),isTerm(false){}
  ~Node(){}
};

void Add(Node* node, string& cad, int id){
  node->counter++;
  if(id == cad.size()){node->isTerm=true; return;}
  if(node->edges.count(cad[id])==0)
  node->edges[cad[id]]=new Node();
  Add(node->edges[cad[id]], cad, id+1);;

}

bool result(Node* node){
  if(node->isTerm && node->counter != 1) return false;
  for(map<char, Node*>::iterator it=node->edges.begin(); it!= node->edges.end(); ++it){
    //cout << it->first << ' ' << it->second->counter << '\n';
    if(!result(it->second)) return false;
  }
  return true;
}

void borrar(Node* node){
  for(map<char, Node*>::iterator it=node->edges.begin(); it!= node->edges.end(); ++it){
    //cout << it->first << ' ' << it->second->counter << '\n';
    borrar(it->second);
  }
  delete node;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, d;
  cin >> n;
  string s;
  for(int i =1; i<=n; ++i){
    cin >> d;
    Node* root = new Node();
    while(d--){
      cin >> s;
      Add(root, s, 0);
    }
    cout << "Case " << i <<": " << ((result(root))? "YES\n" : "NO\n");
    borrar(root);
  }
}
