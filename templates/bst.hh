#ifndef __BST_HH__
#define __BST_HH__

#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <cassert>
#include <algorithm>

template <typename T>
class BST {
private:
  class Node {
  private:
    T data;
    Node* left;
    Node* right;

  public:
    Node(T elem)
        : data(elem)
        , left(nullptr)
        , right(nullptr) {}
    T& getData() { return data; }
    const T& getData() const { return data; }
    Node* getLeft() { return left; }
    void setLeft(Node* nl) { left = nl; }
    bool hasLeft() const { return left != nullptr; }
    Node* getRight() { return right; }
    void setRight(Node* nr) { right = nr; }
    bool hasRight() const { return right != nullptr; }
    void setData(T elem){ data=elem ;}
  };
  // Attributes
  Node* root;
  size_t size;

public:
  BST() : root(nullptr), size(0) {}
  bool empty() const { return root == nullptr; }
  void insert(T elem) {
    if (empty()) {
      Node* n = new Node(elem);
      root = n;
      size++;
    } else {
      insert(root, elem);
    }
  }

private:
  void insert(Node* n, T elem) {
    if (n->getData() == elem) return;
    if (elem < n->getData())
      if (n->hasLeft()) {
        insert(n->getLeft(), elem);
      } else {
        Node* k = new Node(elem);
        n->setLeft(k);
        size++;
      }
    else if (n->hasRight()) {
      insert(n->getRight(), elem);
    } else {
      Node* k = new Node(elem);
      n->setRight(k);
      size++;
    }
  }

public:
 BST (BST<T>& other){
     root=nullptr; size=0;
     other.levelorder([&](T n){ insert(n);});
 }

public:
  /**
   * Outputs a textual representation of the BST.
   *
   * To visualize it, visit:
   * http://www.webgraphviz.com/
   * Visit http://sandbox.kidstrythisathome.com/erdos/
   */
  void print() const {
    using std::cout;
    using std::endl;

    cout << "digraph BST {" << endl;
    if (empty())
      cout << endl;
    else if (!root->hasLeft() && !root->hasRight())
      cout << root->getData() << endl;
    else {
      size_t nullnodes = 0;
      print(root, nullnodes);
    }
    cout << "};" << endl;
  }

private:
  void print(Node* n, size_t& nullnodes) const {
    using std::cout;
    using std::endl;

    if (n->hasLeft()) {
      cout << n->getData() << " -> " << n->getLeft()->getData() << ";" << endl;
      print(n->getLeft(), nullnodes);
    } else
      printNullNode(n->getData(), nullnodes++);

    if (n->hasRight()) {
      cout << n->getData() << " -> " << n->getRight()->getData() << ";" << endl;
      print(n->getRight(), nullnodes);
    } else
      printNullNode(n->getData(), nullnodes++);
  }

  void printNullNode(T data, size_t nullnodes) const {
    using std::cout;
    using std::endl;

    cout << "null" << nullnodes << " [shape=point];" << endl;
    cout << data << " -> null" << nullnodes << ";" << endl;
  }
public:
 int height() const{  //complejidad lineal
	if(empty()) return 0;
	else return height(root);
}

private:

int height(Node *n) const{
	if (!n->hasLeft() && !n->hasRight()) return 1;
	int lh =0, rh =0;
	if(n->hasLeft()) lh=height(n->getLeft());
	if(n->hasRight()) rh=height(n->getRight());
	return 1 + std::max(lh,rh);
}

public:

size_t getSize() const { return size; }

public:

bool search(T elem) const{
	if(empty())
		return 0;
	else return search(root,elem);
}
private:
bool search(Node *x,T elem) const{
	if(x == nullptr) return false;
    if (elem == x->getData())
		return x;
	if(elem < x->getData())
		return search(x->getLeft(),elem);
	else return search(x->getRight(),elem);
}

public:
	T findMax() const{
		assert(!empty());
		return findMax(root)->getData();
	}
private:
  Node* findMax(Node *n) const{
		if(n->hasRight()){
			return findMax(n->getRight());
		}
		else return n;

	}

public:
using F= std::function<void(T)>;

	void inorder(F f){
    assert(!empty());

    inorder(root,f);

  }

  void preorder(F f){
    assert(!empty());

    preorder(root,f);
   ;
  }

  void posorder(F f){
    assert(!empty());

    posorder(root,f);

  }

private:
//complejidad O(size)
  void inorder(Node *n,F f){
    if(n != nullptr){
      inorder(n -> getLeft(),f);
      f(n -> getData());
      inorder(n -> getRight(),f);
    }
  }

  void preorder(Node *n,F f){
    if(n != nullptr){
      f(n -> getData());
      preorder(n -> getLeft(),f);
      preorder(n -> getRight(),f);
    }
  }

  void posorder(Node *n,F f){
    if(n != nullptr){
      posorder(n -> getLeft(),f);
      posorder(n -> getRight(),f);
      f(n -> getData());

    }
  }

 public:
  ~BST(){clear();}

  void clear(){
  	if(empty()) return;
  	clear(root);
  	size=0;
  	root=nullptr;
  }


private:
	void clear(Node *n){
		if(n->hasLeft())
			clear(n->getLeft());
		if(n->hasRight())
			clear(n->getRight());
		delete n;
	}
public:

  void levelorder(F f){
	if(empty()) return;
		//Queue<Node *>c;
      std::queue< Node * > q;
      q.push(root);
	  while(!q.empty()){
      Node *e=q.front();
      q.pop();
      f( e-> getData());
			if( e->hasLeft())
				q.push(e->getLeft());
			if( e->hasRight())
				q.push(e->getRight());
		}
	}

	void remove(T elem){
		if(empty()) return;
		root=remove(root,elem);
	}

private:
	Node *remove(Node *n,T elem){
       if(elem < n->getData()) {n->setLeft(remove(n->getLeft(),elem)); return n;}

       if(elem > n->getData()) {n->setRight(remove(n->getRight(),elem)); return n;}

       else{//cuabdo n->getData( ) ==elem
       	if(!n->hasRight() && !n->hasLeft()){
       		delete n;
       		 size--;
       		 return nullptr;
       	}
       	if(!n->hasLeft()){//solo tiene derecho
       		Node *tmp=n->getRight();
       		delete n;
       		size--;
       		return tmp;

       	}

       	if(!n->hasRight()){
       		Node *tmp=n->getLeft();
       		delete n;
       		size--;
       		return tmp;
       	}

       	Node *m=findMax(n->getLeft());
       	T tmp=n->getData();
       	n->setData(m->getData());
       	m->setData(tmp);
       	n->setLeft(remove(n->getLeft(),elem));
       	return n;
       }
	}

    public:
    T LCA(T n1,T n2){
        assert(!empty());
        return LCA(root,n1,n2)-> getData();
    }
    private:
    Node* LCA(Node* n,T n1, T n2){
        T maxi,mini;
        if(n1 < n2){ maxi = n2; mini=n1;}
        else { maxi = n1 ; mini = n2;}
        if(n->getData() > maxi)
            return LCA( n->getLeft(),n1,n2);
        else if(n ->getData() < mini)
            return LCA( n -> getRight(),n1,n2);
        else return n;
    }

};

#endif
