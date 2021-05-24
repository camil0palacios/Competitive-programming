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

const int Mxn = 55;
int a[Mxn];

bool is_asc(int n) {
    bool ok = 1;
    fore(i,2,n) ok &= a[i-1]+1 == a[i];
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
        if(is_asc(n)) cout << 0 << endl;
        else {
            int ans = 0;
            if(a[n] == 1) {
                if(a[1] == n) cout << 3 << endl;
                else cout << 2 << endl;
            }
            else if(a[1] != 1) {
                ans++;
                sort(a+1, a+n);
                if(!is_asc(n)) ans++;
                cout << ans << endl; 
            } else cout << 1 << endl;
        }
    }
    return 0; 
}