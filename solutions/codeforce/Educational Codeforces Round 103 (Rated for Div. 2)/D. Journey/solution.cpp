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
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int dpl[n+1], dpr[n+1];
        fore(i,0,n) dpl[i] = dpr[i] = i;
        fore(i,1,n) {
            if(s[i-1] == 'L') {
                dpl[i] = i-1;
                if(i-2 >= 0 && s[i-2] == 'R') dpl[i] = dpl[i-2];
            }
        }
        forr(i,n-1,0) {
            if(s[i] == 'R') {
                dpr[i] = i+1;
                if(i+1 < n && s[i+1] == 'L') dpr[i] = dpr[i+2];
            }
        }
        fore(i,0,n) cout << dpr[i] - dpl[i] + 1 << ' ';
        cout << endl;
    }
    return 0; 
}