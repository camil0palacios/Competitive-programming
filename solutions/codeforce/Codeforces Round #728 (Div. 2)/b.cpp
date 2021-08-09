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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi p(2*n + 5);
        fore(i,1,n) {
            int a; cin >> a;
            p[a] = i;
        }
        int ans = 0;
        fore(i,1,2*n) {
            for(int j = 1; j*j <= i; j++) {
                if(i % j == 0 && i/j != j && p[j] && p[i/j] && p[j]+p[i/j] == i) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0; 
}