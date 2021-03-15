#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

const int MXN = 11;
int n;
int a[1 << MXN];
int ans, mx;

int dfs(int p, int lvl) {
    if(lvl == n) return 0;
    int left = p << 1, right = left + 1;
    int l = dfs(left, lvl+1) + a[left];
    int r = dfs(right, lvl+1) + a[right];
    int mx = max(l, r);
    ans += mx - l;
    ans += mx - r;
    return mx;
}

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 2; i <= (1<<(n+1))-1; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0; 
}