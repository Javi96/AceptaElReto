#include <iostream>

using namespace std;

int numbSize( long long int n ) {
    if(n<10){
        return 1;
    }
    return 1 + numbSize(n/10);
}


bool solution(long long int n, int x){
    if(n<10){
        return true;
    }
    return (n%x==0) ? solution(n/10, --x) : false;
}

bool solutionLauncher(){
    long long int n;
    cin >> n;
    if(!cin){
        return false;
    }
    (solution(n, numbSize(n))) ? cout << "POLIDIVISIBLE" << endl : cout << "NO POLIDIVISIBLE" << endl;
    return true;
}

int main(){
    while(solutionLauncher());
    return 0;
}

