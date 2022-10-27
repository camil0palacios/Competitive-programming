#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 2e5 + 5;
set<int> a[Mxn];
bool is_vul[Mxn];

bool still_vul(int i) {
    return sz(a[i]) && *(a[i].rbegin()) > i;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, q;
    cin >> n >> m; 
    fori(i,0,m) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }
    int vul = 0;
    fore(i,1,n) {
        if(still_vul(i)) {
            vul++;
            is_vul[i] = 1;
        }
    }
    cin >> q;
    fori(i,0,q) {
        int t, u, v;
        cin >> t;
        if(t == 1) {
            cin >> u >> v;
            a[u].insert(v);
            a[v].insert(u);
            if(!is_vul[u] && u < v) is_vul[u] = 1, vul++;
            if(!is_vul[v] && v < u) is_vul[v] = 1, vul++;
        }
        else if(t == 2) {
            cin >> u >> v;
            a[u].erase(v);
            a[v].erase(u);
            if(is_vul[u] && !still_vul(u)) is_vul[u] = 0, vul--;
            if(is_vul[v] && !still_vul(v)) is_vul[v] = 0, vul--; 
        }
        else {
            cout << n-vul << endl;
        }
    }
    return 0; 
}