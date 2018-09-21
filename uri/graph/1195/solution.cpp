#include <bits/stdc++.h>
using namespace std;

struct Nodo{
	Nodo *left,*rigth;
	int value;
	Nodo(int v): value(v),left(nullptr),rigth(nullptr){}
};

struct BST{
	Nodo* root;
	size_t size;
	vector<int> res;

	BST(): root(nullptr),size(0){}

	void insert(int a){
		if(size == 0){
			Nodo *n = new Nodo(a);
			root = n;
			size++;
		}
		else insert2(root,a); 
	}

	void insert2(Nodo* n, int v){
		if(n -> value == v)return;
		if( n -> value < v){
			if(n -> rigth != nullptr)
				insert2(n->rigth,v);
			else{
				Nodo *tmp = new Nodo(v);
				n -> rigth = tmp;
				size ++;
			}
		}
		else if(n -> left != nullptr)insert2(n -> left,v);
		else{
			Nodo *tmp = new Nodo(v);
			n -> left = tmp;
			size ++;
		}
	}

	void print(){
		for(int i=0; i < res.size(); i++){
			cout<<res[i];
			if(i < res.size()-1)
				cout<<" ";
		}
		cout<<endl;
	}

	void order(){
		cout<<"Pre.: ";
		res.clear();
		preorder(root);
		print();
		cout<<"In..: ";
		res.clear();
		inorder(root);
		print();
		cout<<"Post: ";
		res.clear();
		posorder(root);
		print();
		cout<<endl;
	}
	void inorder(Nodo* n){
		if(n->left != nullptr)inorder(n->left);
		res.push_back(n->value);
		if(n->rigth != nullptr)inorder(n->rigth);
	}

	void preorder(Nodo* n){
		res.push_back(n->value);
		if(n->left != nullptr)preorder(n->left);
		if(n->rigth != nullptr)preorder(n->rigth);
	}

	void posorder(Nodo* n){
		if(n->left != nullptr)posorder(n->left);
		if(n->rigth != nullptr)posorder(n->rigth);
		res.push_back(n->value);
	}
};

int main(){
	int n,k,m,cont=1;
	cin>>n;
	while(n--){
		cin>>k;
		BST s;
		while(k--){
			cin>>m;
			s.insert(m);
		}
		cout<<"Case "<<cont<<":"<<endl;
		s.order();
		cont++;
	}
	
	return 0;
}