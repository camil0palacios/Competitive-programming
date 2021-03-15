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

const int Mxn = 2e5 + 5;
int a[Mxn], p[Mxn], s[Mxn];

void solve() {
    int n;
    cin >> n;
    fore(i,1,n) cin >> a[i], p[i] = s[i] = 0;
    s[n+1] = 0;
    fore(i,1,n) {
        if(p[i-1] == -1 || a[i] < p[i-1]) p[i] = -1;
        else p[i] = a[i] - p[i-1];
    }
    if(p[n] == 0) { cout << "YES" << endl; return; }
    forr(i,n,1) { 
        if(s[i+1] == -1 || a[i] < s[i+1]) s[i] = -1;
        else s[i] = a[i] - s[i+1];
    }
    if(s[1] == 0) { cout << "YES" << endl; return; }
    fore(i,0,n-2) {
        int j = i+3;
        if(p[i] == -1 || s[j] == -1) continue;
        if(p[i] <= a[j-1] && s[j] <= a[i+1] && a[j-1] - p[i] == a[i+1] - s[j]) { 
            cout << "YES" << endl; 
            return; 
        } 
    }
    cout << "NO" << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}