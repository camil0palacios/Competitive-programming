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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1010;
int n, d;
int p[Mxn], sum[Mxn];

int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
int join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        sum[a] += sum[b];
        p[b] = a;
        return 0;
    }
    return 1;
}

int cal(int x) {
    vi a;
    fori(i,0,n) {
        if(p[i] == i) a.eb(sum[i]);
    }
    sort(all(a), greater<int>());
    int ans = 0;
    fori(i,0,x+1) ans += a[i];
    return ans-1; 
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> d;
    fori(i,0,n) p[i] = i, sum[i] = 1;
    int acc = 0;
    fori(i,0,d) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        acc += join(a, b);
        cout << cal(acc) << endl; 
    }
    return 0; 
}