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
        int k;
        cin >> k;
        if(k == 1) cout << 1 << ' ' << 1 << endl;
        else {
            int n = ceil(sqrt(1.0*k));
            int s = (n-1)*(n-1) + 1;
            if(s + n-1 >= k) {
                cout << k-s+1 << ' ' << n << endl;
            } else {
                cout << n << ' ' << n - (k - (s+n-1)) << endl;
            }
        }

    }
    return 0; 
}