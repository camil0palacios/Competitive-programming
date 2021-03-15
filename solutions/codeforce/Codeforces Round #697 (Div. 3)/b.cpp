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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool ok = 0;
        fore(x,0,1000) {
            if(x*2020 <= n && (n - x*2020) % 2021 == 0) { ok = 1; break; }
            if(x*2021 <= n && (n - x*2021) % 2020 == 0) { ok = 1; break; }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}