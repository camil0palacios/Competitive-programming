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

const int Mxn = 1e4 + 5;
int p[Mxn];

int qry(int t, int i, int j, int x) {
    cout.flush();
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl; 
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int idx = -1;
        for(int i = 1; i <= n-1; i += 2) {
            int mx = qry(1, i, i+1, n-1);
            if(mx == n) { idx = i+1; break; }
            if(mx == n-1) {
                if(idx == -1) idx = i;
                else {
                    if(qry(1, idx, i, n-1) == n-1);
                    else idx = i;
                    break;
                }
            }
        }
        if(n & 1) {
            int mx = qry(1, n-1, n, n-1);
            if(mx == n) idx = n;
            if(mx == n-1) {
                if(idx == -1) idx = n-1;
                else {
                    if(qry(1, idx, n, n-1) == n-1);
                    else idx = n;
                }
            }
        }
        fore(i,1,n) {
            if(idx == i) p[i] = n;
            else p[i] = qry(2, i, idx, 1);
        }
        cout << "! ";
        fore(i,1,n) cout << p[i] << ' ';
        cout << endl;
    }
    return 0; 
}