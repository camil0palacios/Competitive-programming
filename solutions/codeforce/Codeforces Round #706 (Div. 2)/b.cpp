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
        int n, k;
        cin >> n >> k;
        int mex = 0;
        fori(i,0,n) cin >> a[i];
        sort(a, a+n);
        fori(i,0,n) {
            if(a[i] == mex) mex++;
        }
        if(k == 0) cout << n << endl;
        else if(mex > a[n-1]) cout << n + k << endl;
        else {
            int x = (mex + a[n-1] + 1) / 2;
            bool f = 1;
            fori(i,0,n) if(a[i] == x) f = 0;
            cout << n + f << endl;
        }
    }
    return 0; 
}