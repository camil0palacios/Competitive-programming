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
int n, k;
int a[Mxn];
int s[Mxn];

bool check(int x) {
    s[0] = 0;
    int p = 1e9;
    fore(i,1,n) {
        if(a[i] >= x) s[i] = s[i-1] + 1;
        else s[i] = s[i-1] - 1;
        if(i >= k) p = min(p, s[i-k]);
        if(s[i]-p > 0) return 1;
    }
    return 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    fore(i,1,n) cin >> a[i];
    int l = 1, r = n;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(check(m)) l = m+1;
        else r = m-1;
    }
    cout << l-1 << endl;
    return 0; 
}