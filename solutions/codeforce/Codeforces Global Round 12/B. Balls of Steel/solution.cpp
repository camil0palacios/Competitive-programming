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
        int n, k;
        cin >> n >> k;
        vi x(n), y(n);
        fori(i,0,n) cin >> x[i] >> y[i];
        bool ok = 0;
        fori(i,0,n) {
            int cnt = 0;
            fori(j,0,n) {
                if(i == j) continue;
                cnt += abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k;
            }
            if(cnt == n-1) ok = 1;  
        }
        cout << (ok ? 1 : -1) << endl;
    }
    return 0; 
}