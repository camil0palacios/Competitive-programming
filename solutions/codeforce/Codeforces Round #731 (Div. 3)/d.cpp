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
int a[Mxn], x[Mxn], y[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> x[i], y[i] = 0;
        a[0] = x[0], y[0] = 0;
        fori(i,1,n) {
            fori(j,0,30) {
                int b1 = (a[i-1] >> j) & 1;
                int b2 = (x[i] >> j) & 1; 
                if(b1 != b2) y[i] |= ((b2^1) << j);
            }
            a[i] = x[i] ^ y[i];
        }
        fori(i,0,n) cout << y[i] << ' ';
        cout << endl;
    }
    return 0; 
}