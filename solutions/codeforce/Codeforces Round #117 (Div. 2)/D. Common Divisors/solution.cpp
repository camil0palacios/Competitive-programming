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

bool ok(string & a, string & b, int x) {
    int n = sz(a), j = 0;
    fori(i,0,n) {
        if(a[i] != b[j]) return 0;
        j = (j + 1) % x;
    }
    return j == 0;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    if(sz(a) > sz(b)) swap(a, b);
    int n = sz(a), m = sz(b);
    int ans = 0;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            if(ok(a, a, i) && ok(b, a, i))ans++;
            if(n/i != i && ok(a, a, n/i) && ok(b, a, n/i)) ans++;
        }
    }
    cout << ans << endl;
    return 0; 
}