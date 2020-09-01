#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> rows,cols;
int ans;

void solve(vector<vector<int>> & v, int f){
    int n, m;
    if(f)n = v.size(), m = v[0].size();
    else n = v[0].size(), m = v.size();
    for(int i = 0; i < n; i++){
        int mmin = 100000;
        bool flag = 1;
        for(int j = 0; j < m; j++){
            mmin = min(mmin, (f ? v[i][j] : v[j][i]));
            if((f ? v[i][j] : v[j][i]) == 0){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans += mmin;
            if(f)rows.push_back({i,mmin});
            else cols.push_back({i,mmin});
            for(int j = 0; j < m; j++){
                (f ? v[i][j] : v[j][i]) -= mmin;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m){
        vector<vector<int>> v(n, vector<int> (m));
        rows.clear(), cols.clear();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        ans = 0;
        if(n <= m){
            solve(v,1);
            solve(v,0);
        }else{
            solve(v,0);
            solve(v,1);
        }
        bool flag = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j])flag = 0;
            }
        }
        if(flag){
            cout << ans << endl;
            for(auto & i: rows){
                for(int j = 0; j < i.second; j++){
                    cout << "row " << i.first + 1<< endl;
                }
            }
            for(auto & i: cols){
                for(int j = 0; j < i.second; j++){
                    cout << "col " << i.first + 1 << endl;
                }
            }
        }else{
            cout << -1 << endl;
        }
    }
    return 0;   
}