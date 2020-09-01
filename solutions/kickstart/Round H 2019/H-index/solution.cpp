#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        cin >> n;
        int ans = 0, cur = 0;
        priority_queue< int, vector<int>, greater<int> > v;
        cout << "Case #" << cs << ":";
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(x > ans)v.push(x);
            while(!v.empty() && v.top() <= ans)v.pop();
            if(v.size() > ans)ans++;
            cout << ' ' << ans;
        }
        cout << endl;
    }
    return 0;
}