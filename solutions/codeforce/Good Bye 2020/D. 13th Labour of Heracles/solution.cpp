#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 2e5 + 5;
int w[Mxn];
int deg[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll sum = 0;
        fori(i,0,n) {
            deg[i] = 0;
            cin >> w[i];
            sum += w[i];
        }
        vii e(n-1);
        fori(i,0,n-1) {
            cin >> e[i].ft >> e[i].sd;
            e[i].ft--, e[i].sd--;
            deg[e[i].ft]++;
            deg[e[i].sd]++;
        }
        priority_queue<ii> q;
        fori(i,0,n) {
            q.emplace(w[i], i);
        }
        cout << sum << ' ';
        while(!q.empty()){
            ll u = q.top().sd;
            q.pop();
            if(deg[u] == 1) continue;
            sum += w[u];
            cout << sum << ' ';
            deg[u]--;
            q.emplace(w[u], u);
        }
        cout << endl;
    }
    return 0; 
}