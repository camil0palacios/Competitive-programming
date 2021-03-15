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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1010;
int x[Mxn], y[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> x[i] >> y[i];
        if(n & 1) { cout << 1 << endl; continue; }
        sort(x+1, x+n+1);
        sort(y+1, y+n+1);
        int dx = x[n/2+1] - x[n/2] + 1;
        int dy = y[n/2+1] - y[n/2] + 1; 
        cout << 1ll*dx*dy << endl;
    }
    return 0; 
}