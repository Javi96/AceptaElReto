#include <iostream>

using namespace std;

long long int solution(int n, int x, int y){

     long long int fib_n=0, fib_n1, fib_n2;
     fib_n1 = x;
     fib_n2 = y;
     if (n == 0){
        fib_n = x;
     } else if(n==1){
        fib_n = y;
     } else{
         for (int i=2; i<=n; i++) {
            fib_n = (fib_n1 + fib_n2)%1000000007;
            fib_n1 = fib_n2;
            fib_n2 = fib_n;

         }
     }
     return fib_n%1000000007;
}


bool get_result() {
	int n, x, y;
    cin >> n >> x >> y;
    if(!cin){
        return false;
    }
    cout << solution(n,x,y) << endl;
	return true;
}

int main() {
	while (get_result());
}
