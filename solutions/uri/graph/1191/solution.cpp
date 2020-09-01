#include <bits/stdc++.h>
#define endl '\n'
using namespace std;


struct Node{
	char data;
	Node* left;
	Node* rigth;
	Node(char c): data(c), left(nullptr), rigth(nullptr){}
};

struct Bst{

	Node* root;
	int index;

	Bst(): root(nullptr), index(0){}

	void insert(string &pre, string &in){
		index = 0;
		root = construct(pre,in,0,pre.size()-1);
	}

	Node* construct(string &pre, string &in, int sindx , int eindx){

		if(sindx > eindx)return nullptr; //no more nodes
		Node* n = new Node(pre[index++]);
		if(sindx == eindx)return n;	// leaf node

		int mindx = search_indx(in, n->data, sindx, eindx);

		n->left =  construct(pre, in, sindx, mindx-1); // construct left subBst
		n->rigth  =  construct(pre, in, mindx+1, eindx); // construct rigth subBst

		return n;  //return current node
	}

	int search_indx(string &in, char c, int sindx, int eindx){
		for(int i=sindx; i <= eindx; i++)
			if(in[i] == c)return i ;
	}

	void postOrder(Node* n){

		if(n->left != nullptr)postOrder(n->left);
		if(n->rigth != nullptr)postOrder(n->rigth);
		cout<<n->data;
	}
};

int main(){

	string pre,in;
	while(cin>>pre>>in){
		Bst b;
		b.insert(pre,in);
		b.postOrder(b.root);
		cout<<endl;
	}
	return 0;
}