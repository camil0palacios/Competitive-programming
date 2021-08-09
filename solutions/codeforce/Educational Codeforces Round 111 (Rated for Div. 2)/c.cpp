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
int x[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        ll ans = 0; int lst = 0;
        fori(i,0,n) { 
            cin >> x[i];
            int a = -1, b = 1e9 + 5;
            ans++;
            forr(j,i-1,lst) {
                if(x[j] <= a || x[j] >= b) {
                    lst = j+1;
                    break;
                }
                if(x[j] <= x[i]) a = max(a, x[j]);
                if(x[j] >= x[i]) b = min(b, x[j]);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0; 
}