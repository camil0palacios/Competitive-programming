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
int n, A, R, M;
int h[Mxn];

ll F(ll x) {
    ll need = 0, res = 0;
    fori(i,0,n) 
        h[i] <= x ? need += x-h[i] : res += 1ll*h[i]-x;
    ll tmp = min(need, res);
    need -= tmp, res -= tmp;
    return need*A + res*R + tmp*M;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> A >> R >> M;
    M = min(M, A+R);
    fori(i,0,n) cin >> h[i];
    ll l = 0, r = 1e9;
    while(l < r) {
        ll m1 = l + (r-l)/3;
        ll m2 = r - (r-l)/3;
        if(F(m1) < F(m2)) r = m2-1;
        else l = m1+1;
    }
    cout << F(l) << endl;
    return 0; 
}