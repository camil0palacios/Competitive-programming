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
int a[Mxn], op[Mxn];

bool check(int n) {
    bool ok = 1;
    fori(i,1,n) ok &= a[i-1] <= a[i];
    if(ok) return 0;
    ok = 1;
    fori(i,0,n-1) ok &= op[i];
    return !ok;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        fori(i,0,n) op[i] = 0;
        int idx = 0;
        while(check(n)) {
            int nxt = idx;
            fori(i,idx,n) {
                if(a[i] < a[nxt]) nxt = i; 
            }
            if(nxt != idx) {
                forr(i,nxt-1,0) {
                    if(op[i]) continue;
                    swap(a[i], a[i+1]);
                    op[i] = 1;
                }
            }
            op[idx++] = 1;
        }
        fori(i,0,n) cout << a[i] << ' ';
        cout << endl;
    }
    return 0; 
}