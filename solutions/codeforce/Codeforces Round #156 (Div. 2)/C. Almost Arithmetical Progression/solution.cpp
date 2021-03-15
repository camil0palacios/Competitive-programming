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

const int Mxn = 4005;
int a[Mxn], b[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    fori(i,0,n) cin >> a[i], b[i] = a[i];
    sort(b, b+n);
    map<int,int> m;
    int cnt = 0;
    fori(i,0,n) {
        if(m.count(b[i])) continue;
        m[b[i]] = cnt++;
    }
    fori(i,0,n) a[i] = m[a[i]];
    int ans = 1;
    fori(i,0,n) {
        int lst[n], r[n];
        memset(lst, -1, sizeof lst);
        memset(r, 0, sizeof r);
        int cntp = 1, lstp = i;
        fori(j,i+1,n) {
            if(a[j] == a[i]) {
                cntp++, lstp = j;
            } else {
                if(lst[a[j]] == -1) r[a[j]] = 2;
                else if(lst[a[j]] < lstp) r[a[j]] += 2;
                lst[a[j]] = j;
            }
        }
        int mx = 0;
        fori(i,0,n) {
            if(lst[i] == -1) continue;
            if(lst[i] < lstp) mx = max(mx, r[i] + 1);
            else mx = max(mx, r[i]); 
        }
        ans = max(ans, max(mx, cntp));
    }
    cout << ans << endl;
    return 0; 
}