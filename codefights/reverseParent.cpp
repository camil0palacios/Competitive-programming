#include <iostream>
#include <string>

using namespace std;

std::string reverse(std::string s,int init,int finish){
    for(int i=init; i < s.size(); i++){
        if( i >= finish)break;
        else{
        	cout<<s<<"\n";
            int aux = s[i];
            s[i] = s[finish];
            s[finish] = aux;
            finish--;
        }
    }
    return s;
}

std::string reverseParentheses(std::string s) {
	int i=0;
    while(i < s.size()){
    	if(s[i] == '('){
	        int cont = 1,fin = 0;
	        for(int j=i+1 ; j < s.size() ; j++){
	            fin = j;
	            if(s[j] == '('){
	                s[j] = ')';
	                cont++;
	            }
				else if(s[j] == ')'){
					cont--;
					if(cont == 0){
						break;
					}else s[j] = '(';
	            }
	        }
	        s = reverse(s,i+1,fin-1);
	        s.erase(s.begin()+i);
	        s.erase(s.begin()+fin-1);
		}
		else i++;
    }
    return s;
}

int main(){
	string s ="The ((quick (brown) (fox) jumps over the lazy) dog)";
	cout<< reverseParentheses(s)<<"\n";
	system("pause");
	return 0;
}
