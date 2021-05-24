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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    if(a*b >= 6*n) {
        cout << a*b << endl << a << ' ' << b << endl;
        return 0;
    }
    bool f = 0;
    if(a > b) swap(a, b), f = 1;
    ll a1, b1, Sq = 1e18;
    for(ll i = a; i*i <= 6*n; i++) {
        ll nb = 6*n/i;
        if(nb * i < 6*n) nb++;
        if(nb < b) continue;
        if(i*nb < Sq) {
            Sq = i*nb;
            a1 = i, b1 = nb;
        } 
    }
    if(f) swap(a1, b1);
    cout << a1*b1 << endl << a1 << ' ' << b1 << endl;
    return 0; 
}