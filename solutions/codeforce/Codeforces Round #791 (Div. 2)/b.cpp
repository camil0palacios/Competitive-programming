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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
int a[N];
int lst[N], op = 0, val = 0;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    ll s = 0;
    fori(i,0,n) cin >> a[i], s += a[i];
    fore(r,1,q) {
        int t, i, x;
        cin >> t;
        if(t == 1) {
            cin >> i >> x; i--;
            if(lst[i] < op) s -= val;
            else s -= a[i];
            a[i] = x, lst[i] = r;
            s += a[i];
        } else {
            cin >> x;
            op = r, val = x;
            s = 1ll*n*x;
        }
        cout << s << endl;
    }
    return 0; 
}