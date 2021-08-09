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
int cnt[Mxn][2];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i], cnt[a[i]][i&1]++;
        sort(a, a+n);
        fori(i,0,n) cnt[a[i]][i&1]--;
        bool ok = 1;
        fori(i,0,n) {
            if(cnt[a[i]][0] != 0 && cnt[a[i]][1] != 0) {
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
        fori(i,0,n) cnt[a[i]][0] = cnt[a[i]][1] = 0;
    }
    return 0; 
}