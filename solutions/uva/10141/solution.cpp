#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p, c = 1;
    while(cin >> n >> p, n, p){
        cin.ignore();
        string aux;
        for(int i = 0; i < n; i++){
            getline(cin, aux);
        }
        double compp = 0, price = 0; 
        string name;
        for(int i = 0; i < p; i++){
            string prop;
            double pri, met;
            getline(cin, prop);
            cin >> pri >> met;
            double comp = met/n;
            if(comp > compp){
                name = prop;
                compp = comp;
                price = pri;
            }
            else if(comp == compp){
                if(pri < price){
                    name = prop;
                    price = pri;
                }
            }
            cin.ignore();
            for(int j = 0; j < met; j++){ 
                getline(cin, aux);
            }
        }
        if(c > 1)cout << endl;
        cout << "RFP #" << c++ << endl;
        cout << name << endl;
    }
    return 0;
}