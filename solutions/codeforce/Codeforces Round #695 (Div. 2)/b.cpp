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

const int Mxn = 3e5 + 5;
int a[Mxn];

bool check(int i) {
    return (a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]);
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        fore(i,1,n) cin >> a[i];
        a[0] = a[1];
        a[n+1] = a[n];
        int tot = 0, mx = 0;
        fore(i,1,n) {
            if(check(i)) {
                tot++;
                int cur = a[i];
                int m = check(i-1) + check(i) + check(i+1);
                a[i] = a[i-1];
                int l = check(i-1) + check(i) + check(i+1);
                a[i] = a[i+1];
                int r = check(i-1) + check(i) + check(i+1);
                a[i] = cur;
                mx = max(mx, m - min(l, r));
            }
        }
        cout << tot - mx << endl;
    }
    return 0; 
}