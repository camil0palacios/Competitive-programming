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
int st[Mxn], it = -1;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--) {
        int n; ll k;
        string s;
        cin >> n >> k >> s;
        it = -1;
        forr(i,n-1,0) {
            if(s[i] == '0') st[++it] = i ;
        }
        fori(i,0,n) {
            if(s[i] == '0') continue;
            while(it >= 0 && st[it] < i) it--;
            if(it >= 0) {
                int p = st[it];
                if(p - i <= k) {
                    k -= (p - i);
                    s[p] = '1', s[i] = '0';
                    it--;
                    st[++it] = i;
                }
            }
        }
        cout << s << endl;
        
    }
    return 0; 
}