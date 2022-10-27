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

const int Mxn = 1e5 + 5;
int p[Mxn], ps[Mxn];

int find(int a) { return a ==  p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        ps[a] += ps[b];
        p[b] = a;
    }
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    fori(i,0,n) p[i] = i, ps[i] = 1;
    fori(i,0,h) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        join(u, v);
    }
    set<int> s;
    int c = 0;
    fori(i,0,n) {
        int f = find(i);
        if(ps[f] == 1) c++;
        else s.insert(f);
    }
    cout << sz(s) << ' ' << c << endl; 
    return 0; 
}