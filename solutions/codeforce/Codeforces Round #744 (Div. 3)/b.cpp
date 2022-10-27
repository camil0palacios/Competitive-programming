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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fori(i,0,n) cin >> a[i];
        vector<pair<ii,int>> ans;
        fori(i,0,n) {
            int idx = i;
            fori(j,i+1,n) {
                if(a[j] < a[idx]) idx = j;
            }
            if(idx != i) {
                deque<int> b;
                fori(j,idx,n) b.eb(a[j]);
                fori(j,i,idx) b.eb(a[j]);
                fori(j,i,n) a[j] = b.front(), b.pop_front();
                ans.eb(mp(i, n-1), idx-i);
            }
        }
        cout << sz(ans) << endl;
        for(auto p : ans) {
            int i = p.ft.ft, j = p.ft.sd;
            int d = p.sd;
            cout << i+1 << ' ' << j+1 << ' ' << d << endl;
        }
    }
    return 0; 
}