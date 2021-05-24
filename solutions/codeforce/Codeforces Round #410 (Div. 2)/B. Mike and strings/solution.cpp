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

const int Mxn = 55;
string a[Mxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i];
    int ans = 1e9;
    fori(i,0,sz(a[0])) {
        string s = a[0].substr(i) + a[0].substr(0, i);
        int acc = 0, cnt = 0;
        fori(j,1,n) {
            fori(k,0,sz(a[j])) {
                string t = a[j].substr(k) + a[j].substr(0, k);
                if(t == s) {
                    cnt++;
                    acc += k; 
                    break;
                }
            }
        }
        if(cnt == n-1)
            ans = min(ans, acc + i);
    }
    cout << (ans != 1e9 ? ans : -1) << endl;
    return 0; 
}