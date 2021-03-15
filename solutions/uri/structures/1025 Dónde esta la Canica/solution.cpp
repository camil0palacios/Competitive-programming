#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, tc = 0;
    while(cin >> n >> q, n || q) {
        vi a(n);
        fori(i,0,n) {
            cin >> a[i];
        }
        sort(all(a));
        cout << "CASE# "<< ++tc << ":" << endl;
        fori(i,0,q) {
            int x; cin >> x;
            cout << x;
            int j = lower_bound(all(a), x) - a.begin();
            if(j != n && a[j] == x) cout << " found at " << j+1;
            else cout << " not found";
            cout << endl;
        }
    }
    return 0; 
}