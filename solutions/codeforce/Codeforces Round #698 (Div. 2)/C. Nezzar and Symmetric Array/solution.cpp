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

const int Mxn = 2e5 + 5;
ll d[Mxn], a[Mxn];

bool solve() {
    int n;
    cin >> n;
    fori(i,0,2*n) cin >> d[i];
    sort(d, d + 2*n);
    d[2*n] = a[n] = 0;
    forr(i,n-1,0) {
        if(d[2*i] != d[2*i+1]) return 0;
        ll del = d[2*i+2] - d[2*i];
        if(del == 0 || del % (2*(i+1)) != 0) return 0; 
        a[i] = a[i+1] - del/(2*(i+1));
        if(a[i] <= 0) return 0;
    }
    return 1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cout << (solve() ? "YES" : "NO") << endl;    
    }
    return 0; 
}