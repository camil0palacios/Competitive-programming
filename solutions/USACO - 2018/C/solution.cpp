#include <bits/stdc++.h>
using namespace std;

typedef vector<deque<int>> vdi;
set<int> p;

void print(deque<int> v){
    for(auto &i : v)
        cout << i << " ";
    cout << endl;
}

void go(vdi v, int turn = 0, int k = 4, int g1 = 1000, int g2 = 1000){
    if(k == 0){
        p.insert(g1);
        return;
    }
    vdi aux = v;
    for(int i = 0; i < v[turn].size(); i++){
        if(v[turn][i] != -1){
            aux[!turn][10 + i] = v[turn][i];
            aux[turn][i] = -1;
            if(turn)go(aux, !turn, k - 1, g1 - v[turn][i], g2 + v[turn][i]);
            else go(aux, !turn, k - 1, g1 + v[turn][i], g2 - v[turn][i]);
            aux[!turn][10 + i] = -1;
            aux[turn][i] = v[turn][i];
        }
    }
}

int main(){

    freopen("backforth.in","r",stdin);
    freopen("backforth.out","w",stdout);
    
    vector<deque<int>> v(2, deque<int> (20,-1));
    for(int i = 0; i < 10; i++){
        cin >> v[0][i];
    }
    for(int i = 0; i < 10; i++){
        cin >> v[1][i];
    }
    go(v);
    cout << p.size() << endl;

    return 0;
}