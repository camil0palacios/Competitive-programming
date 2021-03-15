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
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        fori(i,0,n) cin >> a[i];
        int lst = n - 1;
        while(lst >= 0 && a[lst] == lst + 1) lst--;
        double ans = 1;
        if(lst == -1) ans = 0;
        fori(i,0,m) {
            int r; double p;
            cin >> r >> p;
            r--;
            if(r >= lst) ans *= (1 - p);
        }
        cout << (1 - ans) << endl;
    }
    return 0; 
}