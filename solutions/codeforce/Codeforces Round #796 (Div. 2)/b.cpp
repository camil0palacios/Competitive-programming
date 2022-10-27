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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int o = 0, e = 0, tmp = 1e9;
        fori(i,0,n) {
            int a; cin >> a;
            if(a % 2 == 0) {
                int x = 0;
                e++;
                while(a % 2 == 0) {
                    x++;
                    a /= 2;
                }
                tmp = min(tmp, x);
            } else o++;
        }
        cout << (o ? e : e-1 + tmp) << endl;
    }
    return 0; 
}