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
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    int ans = 0;
    int n = sz(s);
    fori(i,0,k) {
        char a, b;
        cin >> a >> b;
        int l = 0, r = 0;
        fori(j,0,n) {
            if(s[j] == a) l++;
            else if(s[j] == b) r++;
            else {
                ans += min(l, r);
                l = r = 0;
            }
        }
        ans += min(l, r);
    }
    cout << ans << endl;
    return 0; 
}