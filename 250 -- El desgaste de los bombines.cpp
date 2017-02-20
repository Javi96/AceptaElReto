#include <iostream>
#include <cmath>

using namespace std;



void calculaInternumeros(int v[], int &sum_neg, int &sum_pos, int n) {
	int max;
	for (int i = 0; i < n; i++){
		(v[i] < 0) ? sum_neg += v[i] : sum_pos += v[i];
	}
}


int solution(int v[], int &sum_neg, int &sum_pos, int n){
	int aux_izq=0, aux_der=0;
	int add_izq, add_der;
	bool value=true, mayor=true;


	if (v[0] < 0){
		sum_neg -= v[0];
		aux_der += v[0];
	}
	else{
		sum_pos -= v[0];
		aux_izq += v[0];
	}

	add_der = sum_neg + sum_pos;
	add_izq = aux_der + aux_izq;

	int max = abs(abs(add_izq)-abs(add_der));
	int aux = 1, lastmax=max;
	for (int i = 1; i < n; i++){
		if (v[i] < 0){
			sum_neg -= v[i];
			aux_der += v[i];
		}
		else{
			sum_pos -= v[i];
			aux_izq += v[i];
		}
		add_der = sum_neg + sum_pos;
		add_izq = aux_der + aux_izq;
		if (max > abs(abs(add_izq) - abs(add_der))){
			lastmax = max;
			max = abs(abs(add_izq) - abs(add_der));
			aux = i+1;
		}else if (max < abs(abs(add_izq) - abs(add_der))){
			value=false;
		}else if (max != lastmax){
			value = false;
		}
	}

	return (value) ? 0: aux;
}

bool resuelve() {
	int n;
	cin >> n;
	if (n == 0)
		return false;

	int v[1000000];
	for (int i = 0; i<n; i++)
		cin >> v[i];

	int sum_neg=0, sum_pos=0, value;
	calculaInternumeros(v, sum_neg, sum_pos, n);

	if((sum_neg + sum_pos) == 0){
		cout << 0 << endl;
	}
	else{
		value = solution(v, sum_neg, sum_pos, n);
		(value == 0) ? cout << 0 << endl : cout << value << endl;
	}

	return true;
}

int main() {
	while (resuelve());
	return 0;
}
