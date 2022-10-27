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

// typedef __int128_t i128; only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 505;
int a[Mxn][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int ev = 2, odd = 1;
        fori(i,0,n) {
            fori(j,0,k) {
                if(i & 1) a[i][j] = ev, ev += 2;
                else a[i][j] = odd, odd += 2;
            }
        }
        unordered_set<int> s;
        fore(i,1,n*k) s.insert(i);
        fori(i,0,n) {
            fori(j,0,k) s.erase(a[i][j]);
        }
        if(s.empty()) {
            cout << "YES" << endl;
            fori(i,0,n) {
                fori(j,0,k) cout << a[i][j] << ' ';
                cout << endl;
            }
        } else cout << "NO" << endl;
    }
    return 0; 
}