#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
using namespace std;

typedef pair<int,int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n; ll W;
        cin >> n >> W;
        vector<li> a(n);
        fori(i, 0, n) {
            cin >> a[i].ft;
            a[i].sd = i;
        }
        sort(all(a));
        ll acc = 0;
        int i = 0, j = n - 1;
        vector<int> ans;
        while(j >= 0 && a[j].ft > W) j--;
        while(i <= j && acc < (W+1)/2) {
            while(i <= j && acc + a[j].ft <= W) acc += a[j].ft, ans.emplace_back(a[j--].sd);
            if(acc >= (W+1)/2) break;
            if(i <= j && acc + a[i].ft <= W) acc += a[i].ft, ans.emplace_back(a[i++].sd);
        }
        if(acc >= (W+1)/2) {
            cout << ans.size() << endl;
            for(auto & i : ans) cout << i + 1 << ' ';
            cout << endl;
        } else cout << -1 << endl;
    }
    return 0; 
}