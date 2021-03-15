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

const int Mxn = 1005;
int a[5*Mxn], b[5*Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vi ans;
    fore(i,1,n+m) {
        while(a[i] < k || b[i+1] == 0) {
            ans.eb(i);
            fore(j,i,i+n-1) {
                a[j]++;
                a[j+n+m]++;
                b[j] = 1;
            }
        }
    }
    cout << sz(ans) << endl;
    for(auto & i : ans) cout << i << ' ';
    cout << endl;
    return 0; 
}