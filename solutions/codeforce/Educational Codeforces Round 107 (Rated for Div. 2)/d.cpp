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

map<ii, int> m;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int len = min(n, k);
    int lst = k-1;
    string ans = string(1, char(lst + 'a'));
    fori(i,1,len) {
        m[{lst, i-1}]++;
        ans += char(i-1 + 'a');
        lst = i-1;
    }
    fore(i,len+1,n) {
        int pos = 0, mn = 1e9;
        fori(i,0,k) {
            if(m[{lst, i}] < mn) {
                mn = m[{lst, i}];
                pos = i;
            }
        }
        m[{lst, pos}]++;
        ans += char(pos + 'a');
        lst = pos;
    }
    cout << ans << endl;
    return 0; 
}