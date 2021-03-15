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
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 1e6 + 5;
int a[Mxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int n, m;
	while(cin >> n >> m, n != 0 || m != 0){
		fori(i,0,n) cin >> a[i];
		sort(a, a + n);
		int anb = 0; 
		fori(i,0,m) {
			int b; cin >> b;
			int j = lower_bound(a, a+n, b) - a;
			if(j != n && a[j] == b) anb++;
		}
		int aub = n + m - anb;
		int a_b = aub - m;
		int b_a = aub - n;
		cout << a_b << ' ' << anb << ' ' << b_a << ' ' << aub << endl;
	}
}