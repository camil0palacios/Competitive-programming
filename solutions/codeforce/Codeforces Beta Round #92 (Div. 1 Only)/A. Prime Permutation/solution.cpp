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

const int Mxn = 1010;
char s[Mxn];
int a[26];

int p[Mxn], sz[Mxn];
int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
void join(int a, int b) {
    a = find(a), b = find(b);
    if(a != b) {
        sz[a] += sz[b];
        p[b] = a;
    }
}

bool is_prime(int x) {
    if(x < 2) return 0;
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    for(int i = 3; i*i <= x; i += 2) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%s", s+1);
    int n = strlen(s+1);
    fore(i,1,n) p[i] = i, sz[i] = 1;
    fore(i,1,n) {
        if(is_prime(i))
            for(int j = i; j <= n; j += i)
                join(i, j);
    }
    fore(i,1,n) a[s[i]-'a']++;
    priority_queue<ii> q;
    fore(i,0,26) q.emplace(a[i], i);
    string ans(n, '?');
    set<int> f;
    fore(i,1,n) {
        if(is_prime(i) && !f.count(find(i))) {
            auto x = q.top();
            if(sz[find(i)] <= x.ft) {
                fore(j,1,n) {
                    if(find(i) == find(j))
                        ans[j] = char(x.sd + 'a');
                }
                if(x.ft - sz[find(i)]) q.emplace(x.ft - sz[find(i)], x.sd);
                f.insert(find(i));
                q.pop();
            }
            else { cout << "NO" << endl; return 0; }
        }
    }
    fore(i,1,n) {
        if(!f.count(find(i))) {
            auto x = q.top();
            ans[i] = char(x.sd + 'a');
            q.pop();
            if(x.ft - 1) q.emplace(x.ft-1, x.sd);
        }
    }
    cout << "YES" << endl;
    fore(i,1,n) cout << ans[i];
    cout << endl;
    return 0;
}