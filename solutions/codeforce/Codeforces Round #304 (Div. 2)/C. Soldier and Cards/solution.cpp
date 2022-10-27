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

typedef queue<int> qu;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k1, k2;
    cin >> n >> k1;
    qu a, b;
    fori(i,0,k1) {
        int x; cin >> x;
        a.push(x);
    }
    cin >> k2;
    fori(i,0,k2) {
        int x; cin >> x;
        b.push(x);
    }
    int g = 0;
    set<pair<qu,qu>> s;
    while(sz(a) && sz(b) && !s.count(mp(a, b))) {
        g++;
        s.insert(mp(a, b));
        int x = a.front();
        int y = b.front();
        a.pop(), b.pop();
        if(x > y) a.push(y), a.push(x);
        else b.push(x), b.push(y);
    }
    if(sz(a) && sz(b)) cout << -1 << endl;
    else if(sz(a)) cout << g << ' ' << 1 << endl;
    else cout << g << ' ' << 2 << endl;
    return 0; 
}