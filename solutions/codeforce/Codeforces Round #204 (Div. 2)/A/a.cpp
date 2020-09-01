#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    while(cin >> n){
        int z = 0, f = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            if(tmp == 5)f++;
            if(tmp == 0)z++;
            if(f % 9 == 0)ans = f;
        }
        if(!z)cout << -1 << endl;
        else if(f < 9)cout << 0 << endl;
        else{
            for(int i = 0; i < ans; i++)cout << 5;
            for(int i = 0; i < z; i++)cout << 0;
            cout << endl;
        }
    }

    return 0;
}