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

const int Mxn = 1e6 + 5;
int r_one[Mxn];
int p[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    string s;
    cin >> k >> s;
    int n = sz(s);
    r_one[n] = n;
    forr(i,n-1,0) {
        r_one[i] = r_one[i+1];
        if(s[i] == '1') r_one[i] = i;
    }
    fori(i,0,n) p[i+1] = p[i] + (s[i] == '1');
    ll ans = 0;
    fore(i,1,n) {
        int l = 1, r = i, j = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(p[i] - p[mid-1] <= k) j = mid, r = mid-1;
            else l = mid+1;
        }
        if(j != -1 && p[i] - p[j-1] == k) {
            int x = j-1, y;
            s[x] == '1' ? y = j-1 : y = min(i-1, r_one[x]);
            ans += y-x+1;
        }
    }
    cout << ans << endl;
    return 0; 
}