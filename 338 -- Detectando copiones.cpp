#include <iostream>

using namespace std;


void solution(int v[], int n, int k, int & cp, int & d_cp){
    int last = -1;
    // guardar n-esimo elemento durante el for y evitar el del final
    bool control_cp=true, control_d_cp=true;
    for(int i=1; i<n; i++){
            if(v[n-1]==v[i]){
                last=0;
            }
        for(int j=i-1, z=i-k; j!=0 && (control_cp || control_d_cp); j--, z++){
            if(v[j]==v[i] && control_cp){
                cp++;
                control_cp = false;
            }
            if(v[i]==v[z] && control_d_cp && z<i && i+1>=k){
                d_cp++;
                control_d_cp=false;
            }
        }
        control_cp=true;
        control_d_cp=true;
    }
    if(last !=-1){
        cp++;
    }
}

bool solutionLauncher() {

	// Input
	int n, k, cp=0, d_cp=0;
	cin >> n;
    if(!cin){
        return false;
    }
    cin >> k;
	int v[10000];
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	// Resolve
    solution(v, n, k, cp, d_cp);

	// Output
	cout << cp << " " << d_cp << endl;
	return true;
}

int main() {

	while (solutionLauncher());
	return 0;
}



