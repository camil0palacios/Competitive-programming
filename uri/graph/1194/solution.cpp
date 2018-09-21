#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct nodo{
	char data;
	nodo *left,*right;
	nodo(char c){ data = c; left = nullptr; right = nullptr;}
};

struct Bst{
	nodo *root;
	int indx;

	Bst():root(nullptr), indx(0){}

	void insert(string pre,string in){
		indx = 0;
		//cout<<pre<<" "<<in<<endl;
		root = construct(pre, in, 0, pre.size()-1);
	}

	nodo* construct(string &pre,string &in, int lindx, int sindx){
		if(lindx > sindx)return nullptr;
		nodo *n = new nodo(pre[indx++]);
		//cout<<n->data<<endl;
		if(lindx == sindx)return n;

		int midindx = search_indx(n->data,in,lindx,sindx);
		n -> left = construct(pre, in, lindx, midindx-1);
		n -> right = construct(pre, in, midindx + 1, sindx);

		return n;
	}

	int search_indx(char c,string &in, int lindx, int sindx){
		for(int i = lindx; i <= sindx; i++)
			if(c == in[i])return i;
	}

	void post_order(nodo* n){
		if(n -> left != nullptr)post_order(n->left);
		if(n -> right != nullptr)post_order(n->right);
		cout<<n->data;
	}
};

int main(){
	
	int n,tmp;
	string pre,in;
	cin>>n;
	while(n--){
		cin>>tmp>>pre>>in;
		Bst s;
		s.insert(pre,in);
		s.post_order(s.root);
		cout<<endl;
	}

	return 0;
}