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
typedef vector<ii> vii;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vi a(n);
        fori(i,0,n) cin >> a[i];   
        auto get_first = [&](int x)->int{
            fori(i,0,n) {
                if(a[i] > x) return i;
            }
            return -1;
        };
        int op = 0;
        while(!is_sorted(all(a))) {
            int idx = get_first(x);
            if(idx == -1) break;
            swap(a[idx], x);
            op++;
        }
        cout << (is_sorted(all(a)) ? op : -1) << endl;
    }
    return 0; 
}