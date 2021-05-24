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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int l1 = 1, l2 = 1;
    for(ll i = 7; i < n; i *= 7) l1++;  
    for(ll i = 7; i < m; i *= 7) l2++;
    int ans = 0;
    if(l1 + l2 <= 7) {
        fori(i,0,n) {
            fori(j,0,m) {
                vi us(7);
                for(int k = 0, a = i; k != l1; k++, a /= 7) us[a % 7]++;
                for(int k = 0, a = j; k != l2; k++, a /= 7) us[a % 7]++;
                if(*max_element(all(us)) <= 1) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0; 
}