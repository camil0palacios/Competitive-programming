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

const int Mxn = 2e5 + 5;
int h[Mxn], l[Mxn], r[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        fori(i,0,n) cin >> h[i], r[i] = l[i] = 0;
        l[0] = r[0] = h[0];
        bool ok = 1;
        fori(i,1,n) {
            l[i] = max(l[i-1] - k + 1, h[i]);
            r[i] = min(r[i-1] + k - 1, h[i] + k - 1);
            if(l[i] > r[i]) ok = 0;
        }
        cout << (ok && l[n-1] == h[n-1] ? "yes" : "no") << endl;
    }
    return 0; 
}