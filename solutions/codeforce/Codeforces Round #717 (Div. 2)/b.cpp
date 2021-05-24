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

const int Mxn = 1e5 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        fore(i,1,n) cin >> a[i], a[i] ^= a[i-1];
        if(a[n] == 0) { cout << "YES" << endl; continue; }
        bool ok = 0;
        fore(i,1,n) {
            fore(j,i+1,n-1) {
                if(a[i] == (a[j]^a[i]) && a[i] == (a[n]^a[j])) ok = 1;
            } 
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0; 
}