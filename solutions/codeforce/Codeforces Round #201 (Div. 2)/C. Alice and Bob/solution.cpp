#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    int g = 0, mx = 0;
    fori(i,0,n) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        mx = max(mx, a[i]);
    }
    if((mx/g - n) & 1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0; 
}