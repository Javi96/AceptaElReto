#include <iostream>

using namespace std;

int solution(int v[], int weight, int trees){
	int l=0, s=0, p=0, l_act=0;
	for (int i = 0; i < trees; i++) {
		if (v[i] <= weight) {
			l_act=i-s+1;
			if (l_act > l) {
				l = l_act;
			}
		}
		else if (v[i] > weight && p <= 5) {
			p++;
			l_act= i - s + 1;
			if (l_act > l) {
				l = l_act;
			}
		}
		else if(v[i] > weight && p == 6){
			while (v[s] <= weight) {
				s++;
			}
			s++;
			p--;
			l_act=i-s+1;
			if (l_act > l) {
				l = l_act;
			}
		}
	}

	return l;
}

bool resolve() {

	int n, weight, trees;
	cin >> n;
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++){
        cin >> weight >> trees;
        int v[100000];
        for(int j=0; j<trees; j++){
            cin >> v[j];
        }
        cout << solution(v, weight, trees) << endl;
	}
	return false;
}

int main() {
	while (resolve());
	return 0;
}
