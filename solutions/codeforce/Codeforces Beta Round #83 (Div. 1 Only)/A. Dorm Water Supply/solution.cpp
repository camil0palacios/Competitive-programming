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
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 1010;
int to[Mxn], in[Mxn], out[Mxn], d[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    fori(i,0,p) {
        int a, b, w;
        cin >> a >> b >> w;
        to[a] = b, d[a] = w;
        in[b]++, out[a]++;
    }
    int t = 0;
    fore(i,1,n) if(in[i] == 0 && out[i]) t++;
    cout << t << endl;
    fore(i,1,n) {
        if(in[i] == 0 && out[i]) {
            int s = i, mn = 1e9;
            while(to[s]) {
                mn = min(mn, d[s]);
                s = to[s];
            }
            cout << i << ' ' << s << ' ' << mn << endl;
        }
    }
}