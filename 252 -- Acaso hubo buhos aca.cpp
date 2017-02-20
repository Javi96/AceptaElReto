#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool solution(string chain, int right_pointer, int left_pointer, bool & value){
    if(left_pointer>right_pointer)return true;
    while(chain[left_pointer]==' '){left_pointer++;}
    while(chain[right_pointer]==' '){right_pointer--;}
    chain[right_pointer] = tolower(chain[right_pointer]);
    chain[left_pointer] = tolower(chain[left_pointer]);
    if(chain.at(right_pointer)!=chain.at(left_pointer)){
            value=false;
    }
    left_pointer++;
    right_pointer--;
    value = value * solution(chain, right_pointer, left_pointer, value);
    return value;
}

bool solutionLauncher(){
    string chain;
    bool value;
    getline(cin, chain);
    while(chain!="XXX" && chain.size()!=0){
        value=true;
        (solution(chain, chain.size()-1, 0, value)) ? cout << "SI" << endl : cout << "NO" << endl;
        getline(cin,chain);
    }
    return false;
}

int main(){
    while(solutionLauncher());
}


/*
int main() {
    string chain;
    bool value;
    getline(cin,chain);
    int izq=0, der=chain.size()-1;
    while(chain!="XXX" && chain.size()!=0 && izq<=der){
        value=true;
        while(value && izq<=der){
            der=der;
            while(chain[der]==' '){
                der--;
            }
            izq=izq;
            while(chain[izq]==' '){
                izq++;
            }
            chain[izq] = tolower(chain[izq]);
            chain[der] = tolower(chain[der]);
            if(chain.at(der)!=chain.at(izq)){
                    value=false;
            }
            izq++;der--;
        }
        value ? cout << "SI" << endl : cout << "NO" << endl;
        getline(cin,chain);
        izq=0, der=chain.size()-1;

    }
    return 0;
}
*/