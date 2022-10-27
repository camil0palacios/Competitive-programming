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

void rev(int j, string & s) {
    reverse(s.begin(), s.begin()+j+1);
    fore(i,0,j) s[i] = s[i] == '0' ? '1' : '0';
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vi ans;
        forr(i,n-1,0) {
            if(a[i] == b[i]) continue;
            if(a[0] == b[i]) {
                ans.eb(1);
                rev(0, a);
            }
            ans.eb(i+1);
            rev(i, a);
        }
        cout << sz(ans) << ' ';
        for(auto & i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0; 
}