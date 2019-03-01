#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n){
        vector<int> v(10);
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            v[tmp]++;
        }
        n /= 3;
        if(v[1] == n && v[2] + v[3] == n && v[2] >= v[4] && v[4] + v[6] == n && v[6] >= v[3]){
            while(v[4]--){
                v[2]--;
                cout << "1 2 4" << endl; 
            }
            while(v[2]--){
                cout << "1 2 6" << endl;
            }
            while(v[3]--){
                cout << "1 3 6" << endl;
            }
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}