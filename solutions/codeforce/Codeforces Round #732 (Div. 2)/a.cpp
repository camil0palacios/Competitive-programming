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

const int Mxn = 110;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) cin >> b[i];
        vii ans;
        fori(i,0,n) {
            if(a[i] > b[i]) {
                fori(j,0,n) {
                    if(a[j] < b[j]) {
                        while(a[i] > b[i] && a[j] < b[j]) {
                            ans.eb(i+1, j+1);
                            a[i]--, a[j]++;
                        }
                    }
                }
            }
        }
        bool ok = 1;
        fori(i,0,n) ok &= a[i] == b[i];
        if(ok) {
            cout << sz(ans) << endl;
            for(auto & p : ans) cout << p.ft << ' ' << p.sd << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}