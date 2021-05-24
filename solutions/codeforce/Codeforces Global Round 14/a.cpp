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

const int Mxn = 101;
int w[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        fori(i,0,n) cin >> w[i];
        sort(w, w+n);
        int s = 0, ok = 1;
        fori(i,0,n) {
            s += w[i];
            if(s == x) {
                s -= w[i];
                swap(w[i], w[n-1]);
                s += w[i];
                if(s == x) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES" << endl;
            fori(i,0,n) cout << w[i] << ' ';
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0; 
}