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
    ll n, m;
    int q;
    cin >> n >> m >> q;
    ll g = __gcd(n, m);
    ll x = n/g;
    ll y = m/g;
    while(q--) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll sg1, sg2;
        if(sx == 1) sg1 = (sy+x-1)/x;
        else sg1 = (sy+y-1)/y;
        if(ex == 1) sg2 = (ey+x-1)/x;
        else sg2 = (ey+y-1)/y;
        cout << (sg1 == sg2 ? "YES" : "NO") << endl;
    }
    return 0; 
}