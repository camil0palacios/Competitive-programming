#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char conv(int n){
    if(n == 0)return 'R';
    if(n == 1)return 'G';
    if(n == 2)return 'B';
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    while(cin >> n){
        cin >> s;
        int ans = 10000000;
        string a, tmp = "RGB";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    if(i != j && j != k && i != k){
                        string x;
                        x += conv(i);
                        x += conv(j);
                        x += conv(k);
                        string aux;
                        int cnt = 0;
                        for(int i = 0; i < n; i++){
                            aux += x[i%3];
                            if(aux[i] != s[i])cnt++;
                        }
                        if(cnt < ans){
                            a = aux;
                            ans = cnt;
                        }
                    }
                }
            }
        }
        cout << ans << endl << a << endl;
    }
    return 0;
}