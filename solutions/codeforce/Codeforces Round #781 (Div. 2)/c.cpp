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
int s[N];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fore(i,0,n) s[i] =  0;
        s[0] = 1;
        fore(i,2,n) {
            int v; cin >> v;
            s[v]++;
        }
        sort(s, s+n+1, greater<int>());
        priority_queue<int> q;
        int i = 0;
        for(; i < n; i++) {
            if(s[i] == 0) break;
            q.push(s[i]+i);
        }
        for(; i < q.top(); i++) {
            q.push(q.top()-1);
            q.pop();
        }
        cout << i << endl;
    }
    return 0; 
}