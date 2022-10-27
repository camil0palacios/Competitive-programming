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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

void sol() {
    int n, a, b;
    cin >> n >> a >> b;
    if(abs(a - b) < 2) {
        if(n-2 < a+b) { cout << -1 << endl; return; }
        if(a+b == 0) fore(i,1,n) cout << i << ' ';
        else {
            int p = a >= b ? 1 : 0, l = 1, r = n;
            cout << (p ? 1 : n) << ' ';
            if(p) l++;
            else r--;
            fore(i,2,n) {
                cout << (p ? r-- : l++) << ' ';
                if(p && a) a--;
                if(!p && b) b--;
                if(a + b) p ^= 1;
            }
        }
        cout << endl;
    } else cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
    return 0; 
}