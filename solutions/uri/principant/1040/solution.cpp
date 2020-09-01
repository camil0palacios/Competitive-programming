#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    double n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    double media = (n1*0.2 + n2*0.3 + n3*0.4 + n4*0.1);
    printf("Media: %.1f\n",media);
    if(media >= 7.0)cout<<"Aluno aprovado."<<endl;
    else if(media < 5.0)cout<<"Aluno reprovado."<<endl;
    else if(media >= 5.0 && media <= 6.9){
        cout<<"Aluno em exame."<<endl;
        double exam;
        cin>>exam;
        printf("Nota do exame: %.1f\n", exam);
        if((exam+media)/2 >= 5.0){
            cout<<"Aluno aprovado."<<endl;
            printf("Media final: %.1f\n", (exam+media)/2);
        }
        else cout<<"Aluno reprovado."<<endl;
    }
 
    return 0;
}