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
        int n, m;
        string s;
        cin >> n >> m >> s;
        bool ok = 1;
        for(int t = 0; t < m && ok; t++) {
            ok = 0;
            string tmp = s;
            fori(i,0,n) {
                if(s[i] == '1') continue;
                if(!i) {
                    if(i+1 < n && s[i+1] == '1') tmp[i] = '1', ok = 1;
                } 
                else if(i == n-1) {
                    if(s[i-1] == '1') tmp[i] = '1', ok = 1;
                }
                else if((s[i-1]-'0')^(s[i+1]-'0'))
                    tmp[i] = '1', ok = 1;
            }
            s = tmp;
        }
        cout << s << endl;
    }
    return 0; 
}