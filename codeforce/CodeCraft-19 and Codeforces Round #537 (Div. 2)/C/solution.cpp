#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;

struct node{
    node *l, *r;
    long long val;
    int cnt;
    node(){ val = 100000000000; cnt = 0; l = nullptr; r = nullptr; }
};

node* update(node* n, int left, int rigth, int pos){
    if(!n)n = new node();
    if(pos < left || pos > rigth){
        if(n -> cnt == 0){
            n -> val = A;
        }
        return n;
    }
    if(left == rigth){
        n -> cnt++;
        n -> val = n -> cnt*B;
        return n;
    }
    int mid = (left + rigth) >> 1;
    n -> l = update(n -> l, left, mid, pos);
    n -> r = update(n -> r, mid+1, rigth, pos);
    n -> cnt =  n -> l -> cnt + n -> r -> cnt;
    n -> val = min(n -> cnt * B * (rigth - left + 1), n -> l -> val + n -> r -> val);
    return n;
}

int main(){
    while(cin >> n >> k >> A >> B){
        node *r = nullptr;
        for(int i = 0; i < k; i++){
            int tmp;
            cin >> tmp;
            r = update(r, 1, 1 << n, tmp);
        }
        cout << r -> val << endl;
    }
    return 0;
}