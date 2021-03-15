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

const int Mxn = 1e5 + 5;
int p[Mxn][26];

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    fori(i,0,n) memset(p[i], 0, sizeof p[i]);
    if(n % k != 0) { cout << -1 << endl; return; }
    fori(i,0,n) {
        fori(j,0,26) p[i+1][j] = p[i][j];
        p[i+1][s[i]-'a']++;
    }
    bool ok = 1;
    fori(i,0,26) ok &= p[n][i] % k == 0;
    if(ok) { cout << s << endl; return; }
    forr(i,n-1,0) {
        int tmp[27];
        memset(tmp, 0, sizeof tmp);
        fori(j,s[i]-'a'+1,26) {
            fori(l,0,26) tmp[l] = p[i+1][l];
            tmp[s[i]-'a']--;
            tmp[j]++;
            int sum = 0;
            fori(l,0,26) if(tmp[l] % k != 0) {
                int x = (k - tmp[l] % k) % k;
                sum += x;
                tmp[l] += x;
            }
            if(sum <= n-i-1 && ((n-i-1)-sum) % k == 0) {
                tmp[0] += (n-i-1) - sum;
                fori(l,0,i) {
                    cout << s[l];
                    tmp[s[l]-'a']--;
                }
                cout << char(j+'a');
                tmp[j]--;
                fori(l,0,26) if(tmp[l]) cout << string(tmp[l], char(l+'a'));
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0; 
}