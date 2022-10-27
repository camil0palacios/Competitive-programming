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

// typedef __int128_t i128; // only for extreme cases
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int N = 2e5 + 5;
int d[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int p;
        string s;
        cin >> s >> p;
        int n = sz(s), p1 = 0;
        priority_queue<ii> q;
        fori(i,0,n) {
            int x = s[i]-'a'+1;
            q.push({x, i});
            d[i] = 1;
            p1 += x;
        }
        while(p1 > p) {
            auto p = q.top(); q.pop();
            p1 -= p.ft;
            d[p.sd] = 0;
        }
        fori(i,0,n) if(d[i]) cout << s[i];
        cout << endl;
    }
    return 0; 
}