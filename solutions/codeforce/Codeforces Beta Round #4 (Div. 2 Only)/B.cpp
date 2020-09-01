#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> minimo,maximo;
    int d,sumpet,mini,maxi,sumMin = 0 , sumMax = 0;
    scanf("%d %d",&d,&sumpet);
    if( 1 <= d && d <= 30 && 0 <= sumpet && sumpet <= 240){
        for(int i=1; i <= d; i++){
            scanf("%d %d",&mini,&maxi);
            sumMin += mini;
            sumMax += maxi;
            minimo.push_back(mini);
            maximo.push_back(maxi);
        }
        if(sumMin <= sumpet && sumpet <= sumMax){
            printf("%s\n", "YES");
            for(int i=0; i < d ; i++){
                sumMin -= minimo[i];
                if(i <= d-2)
                    if(minimo[i+1] == 0 && maximo[i+1] == 0){
                        if(i+1 == d - 1) printf("%d ",sumpet);
                        else {  sumpet-= maximo[i] - minimo[i];
                                printf("%d ",maximo[i] - minimo[i]);}
                        continue;
                    }
                if(sumMin < sumpet - maximo[i]){
                    printf("%d ",maximo[i]);
                    sumpet -= maximo[i];
                }
                else{
                    if(i == d-1)
                        printf("%d",sumpet);
                    else{
                    printf("%d ",minimo[i]);
                    sumpet -= minimo[i];
                    }
                }
            }
        }else printf("%s\n", "NO");
    }else printf("%s\n", "NO");
}
