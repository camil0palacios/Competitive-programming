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
typedef vector<ll> vl;

void solve() {
    int n, k;
    cin >> n >> k;
    vi h(n);
    fori(i,0,n) cin >> h[i];
    int lst = 0;
    fori(i,0,k) {
        int j = 0;
        while(j < n-1 && h[j] >= h[j+1]) j++;
        if(j == n-1) {
            cout << -1 << endl;
            return;
        }
        h[j] += 1;
        lst = j;
    }
    cout << lst+1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0; 
}