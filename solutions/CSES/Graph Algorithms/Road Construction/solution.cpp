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
int p[Mxn], tam[Mxn];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
bool join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        tam[a] += tam[b];
        p[b] = a;
        return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fori(i,0,n) p[i] = i, tam[i] = 1;
    int cnt = n, mx = 1;
    fori(i,0,m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(join(a, b)) cnt--;
        mx = max(mx, tam[find(a)]);
        cout << cnt << ' ' << mx << endl;
    }
    return 0; 
}