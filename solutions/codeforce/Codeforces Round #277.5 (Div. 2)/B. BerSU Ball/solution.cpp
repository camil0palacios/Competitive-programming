#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n;
    vi a(n);
    fori(i,0,n) cin >> a[i];
    cin >> m;
    vi b(m);
    fori(i,0,m) cin >> b[i];
    sort(all(a)), sort(all(b));
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m) {
        if(abs(a[i]-b[j]) < 2) i++, j++, ans++;
        else if(b[j] < a[i]) j++;
        else i++;
    }
    cout << ans << endl;
    return 0; 
}
