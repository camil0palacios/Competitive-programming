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

const int Mxn = 1010;
int a[Mxn];

bool check(int n) {
    bool ok = 1;
    fore(i,2,n) ok &= a[i-1] <= a[i];
    return ok;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> a[i];
        int it = 0;
        if(!check(n)) { 
            for(it = 1; ;it++) {
                int st = 2;
                if(it & 1) st = 1;
                for(int i = st; i <= n; i += 2) {
                    if(i+1 <= n && a[i] > a[i+1]) swap(a[i], a[i+1]);
                }
                if(check(n)) break;
            }
        }
        cout << it << endl;
    }
    return 0; 
}