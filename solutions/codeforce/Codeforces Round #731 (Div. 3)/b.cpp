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
        string s;
        cin >> s;
        int n = sz(s), st = -1;
        fori(i,0,n) {
            if(s[i] == 'a') { st = i; break; }
        }
        if(st != -1) {
            char next = 'b';
            int l = st-1, r = st+1;
            while(1) {
                if(l >= 0 && s[l] == next) l--;
                else if(r < n && s[r] == next) r++;
                else break;
                next++;
            }
            cout << (l < 0 && r == n ? "YES" : "NO") << endl;
        }
        else cout << "NO" << endl;
    }
    return 0; 
}