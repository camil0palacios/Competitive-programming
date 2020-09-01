#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MXN = 1e5 + 5;
int n, c;
int x[MXN];

bool check(int dist){
	int lst = x[0], cnt = 1;
	for(int i = 1; i < n; i++){
		if(x[i] - lst >= dist){
			lst = x[i];
			cnt++;
		}
	}
	return cnt >= c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}
		sort(x, x + n);
		int l = 0, r = 1e9, ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(check(mid)) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}