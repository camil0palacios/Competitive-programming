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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 105;
int n, k;
ll p[Mxn];

bool check(ll s) {
    s += p[0];
    fori(i,1,n) {
        if(p[i]*100 > s*k) return 0;
        s += p[i];
    }
    return 1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        fori(i,0,n) cin >> p[i];
        ll l = 0, r = (1ll << 50);
        while(l <= r) {
            ll m = (l + r) >> 1;
            if(check(m)) r = m-1;
            else l = m+1;
        }
        cout << r+1 << endl;
        
    }
    return 0; 
}