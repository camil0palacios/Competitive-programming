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

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(all(s));
    if(s[0] != s[k-1]) {
        cout << s[k-1] << endl;
        return;
    }
    cout << s[0];
    if(s[k] != s[n-1]) {
        fori(i,k,n) cout << s[i];
    } else {
        fori(i,0,(n-k+k-1)/k) cout << s[n-1];
    }
    cout << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}