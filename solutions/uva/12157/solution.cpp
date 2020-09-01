#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, numCase = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mile = 0, juice = 0;
        for(int i = 0; i < n; i++){
            int tmp; cin >> tmp;
            mile += (tmp/30)*10 + 10;
            juice += (tmp/60)*15 + 15;
        }
        cout << "Case " << numCase++ << ": ";
        if(mile < juice)cout << "Mile " << mile << endl;
        else if(juice < mile)cout << "Juice " << juice << endl;
        else cout << "Mile Juice " << mile << endl; 
    }
    return 0;
}