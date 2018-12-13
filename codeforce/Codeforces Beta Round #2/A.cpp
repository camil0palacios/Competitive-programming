#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair

struct nodo{
    int val;
    map<int, int> values;
    nodo(): val(0), values(){}
    void in(int _val, int idx){
        val += _val;
        values[idx] = val;
    }
};

bool operator<(pair<string,nodo> & x, pair<string, nodo> & y){
    nodo a = x.ss, b = y.ss;
    if(a.val == b.val){
        int idx1 = 0;
        for(auto i: a.values){
            if(i.ss >= a.val){
                idx1 = i.ff;
                break; 
            }
        }
        int idx2 = 0;
        for(auto i: b.values){
            if(i.ss >= b.val){
                idx2 = i.ff;
                break;
            }
        }
        return idx1 < idx2;
    }
    else return a.val > b.val;
}

int main(){
    int n;
    cin >> n;
    map<string, nodo> m;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int val; cin >> val;
        m[s].in(val, i);
    }
    int mmax = 0;
    string ans;
    vector<pair<string,nodo>> v;
    for(auto i: m){
        v.push_back(mp(i.ff, i.ss));
    }
    sort(v.begin(), v.end());
    cout << v[0].ff << endl;

    return 0;
}
