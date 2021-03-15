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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        sort(all(a), greater<int>());
        ll bob = 0, alice = 0;
        for(int i = 0; i < n; i += 2) alice += a[i] % 2 == 0 ? a[i] : 0;
        for(int i = 1; i < n; i += 2) bob += a[i] & 1 ? a[i] : 0;
        if(bob < alice) cout << "Alice";
        else if(alice < bob) cout << "Bob";
        else cout << "Tie";
        cout << endl;
    }
    return 0; 
}