#include <bits/stdc++.h>
using namespace std;

int main(){
    double month, dpay, loan; int ndep;
    while(cin >> month >> dpay >> loan >> ndep && month > 0){
        double v[101];
        while(ndep--){
            int m; double p; cin >> m >> p;
            for(int i = m; i < 101; i++)v[i] = p;
        }
        int ans = 0, i = 1;
        double cpay = loan/month;
        double valcar = (loan + dpay)*(1 - v[0]);
        double cloan = loan;
        while(cloan > valcar){
            ans++;
            cloan -= cpay;
            valcar = valcar*(1 - v[i]);
            i++;
        }
        cout << ans << " month";
        if(ans != 1)cout << "s";
        cout << endl; 
    }
    return 0;
}