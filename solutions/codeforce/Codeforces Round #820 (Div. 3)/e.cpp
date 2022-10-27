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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

ll query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    flush(cout);
    ll x; cin >> x;
    return x;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fori(i,4,29) {
        ll x = query(1, i);
        if(x == -1) {
            cout << "! " << i-1;
            break;
        }
        ll y = query(i, 1);
        if(x != y) {
            cout << "! " << x+y;
            break;
        }
    }
    return 0; 
}