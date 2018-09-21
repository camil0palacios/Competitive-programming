#include <iostream>
#include <vector>
#include <algorithm>

int makeArrayConsecutive2(std::vector<int> statues) {
    std::sort(statues.begin(),statues.end());
    int cont = 0;
    for(int i= 0 ; i < statues.size()-1; i++){
        if(statues[i+1] - statues[i] != 0)
            cont = cont + (statues[i+1]-statues[i]) - 1;
    }
    return cont;
}

int main(){
	int myints[] = {6,2,3,8};
 	std::vector<int> myvector (myints, myints+4);
 /*	std::sort(myvector.begin(),myvector.end());
	for(int i = 0; i< myvector.size(); i++)
		std::cout<<myvector[i]; */
	std::cout<< makeArrayConsecutive2(myvector);
}
