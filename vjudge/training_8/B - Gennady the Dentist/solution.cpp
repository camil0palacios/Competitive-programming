#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 4010;
long long v[MAXN], d[MAXN], p[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i] >> d[i] >> p[i];
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(p[i] >= 0){ 
            long long val = 0;
            for(int j = i + 1; j < n; j++){
                if(p[j] < 0)continue;
                p[j] -= val + v[i];
                if(p[j] < 0)val += d[j];
                if(v[i])v[i]--;
            }
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    } 
    cout << endl;
    return 0;
}