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
int q[Mxn];
int ans[2][Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,1,n) cin >> q[i];
        set<int> s1;
        set<int, greater<int>> s2;
        fore(i,1,n) s1.insert(i), s2.insert(i);
        int mx = -1;
        fore(i,1,n) {
            int x;
            if(mx < q[i]) x = mx = q[i];
            else x = *(s1.begin());
            ans[0][i] = x;
            s1.erase(x);
        }
        mx = -1;
        fore(i,1,n) {
            int x;
            if(mx < q[i]) x = mx = q[i];
            else x = *(s2.lower_bound(mx));
            ans[1][i] = x;
            s2.erase(x);
        }
        fore(i,1,n) cout << ans[0][i] << ' ';
        cout << endl;
        fore(i,1,n) cout << ans[1][i] << ' ';
        cout << endl;
    }
    return 0; 
}