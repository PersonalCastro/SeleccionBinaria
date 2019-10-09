/* Ordenar un vector SeleccionV.Pablo */

#include <iostream>
#define restaurar "\033[1;0m"
#define desordenado "\033[1;33m"
#define ordenado "\033[1;32m"
#define debug "\033[1;31m"

using namespace std;

void OrdenaSeleccionV_P(int v[], int util_v);

int main () {

	const int DIM  = 30;
	int v[DIM] = {9,8,7,6,5,4,3,2,1,0};
	int util_v = 10;

	cout << desordenado << "Vector desordenado: ";
	for (int i = 0; i < util_v; i++){
		
		cout << v[i] << " ";
	}
	cout << "\n" << restaurar;

	OrdenaSeleccionV_P(v,util_v);
	
	cout << ordenado << "Vector ordenado: ";
	for (int i = 0; i < util_v; i++){
		
		cout << v[i] << " ";
	}
	cout << "\n" << restaurar;
}

void OrdenaSeleccionV_P(int v[], int util_v){

	int pos_min = 0;
	int pos_max = 0;
	int aux = 0;
	//int aux2 = 0;


	/* Esta condicion podria dar problemas */
	for (int i = 0, i_contraria = util_v - 1; i<=i_contraria-1; i++, i_contraria--){

		pos_min = i;
		pos_max = i;
		for (int j=i+1; j<=i_contraria; j++){
		
			if(v[j] < v[pos_min]){
				pos_min = j;
			}
			if(v[j] > v[pos_max]){
				pos_max = j;
			}
		}

		/*cout << debug << i << " - Vector dentro del bucle: ";
		for (int d = 0; d < util_v; d++){
		
			cout << v[d] << " ";
		}
cout << debug << "\nDebug pos_min: " << v[pos_min] << restaurar << " ";
cout << debug << "\nDebug pos_max: " << v[pos_max] << restaurar << " ";
cout << debug << "\nDebug i: " << i << restaurar << " ";
cout << debug << "\nDebug i_contraria: " << i_contraria << restaurar << " ";

		cout << "\n" << restaurar;*/

	/*CAMBIO DE VARIABLES*/
		if (i != pos_max){
	//cout << debug << " (i != pos_max) \n"; 
			aux = v[i];
			v[i] = v[pos_min];
			v[pos_min] = aux;

			aux = v[i_contraria];
			v[i_contraria] = v[pos_max];
			v[pos_max] = aux;
		}else if (i_contraria != pos_min){
	//cout << debug << " (i_contraria != pos_min) \n"; 
			aux = v[i_contraria];
			v[i_contraria] = v[pos_max];
			v[pos_max] = aux;

			aux = v[i];
			v[i] = v[pos_min];
			v[pos_min] = aux;
		}else{
	//cout << debug << " (else) \n"; 
			aux = v[i_contraria];
			v[i_contraria] = v[pos_max];
			v[pos_max] = aux;
		}



	//cout << debug << i << " - Vector dentro del bucle: ";
		for (int d = 0; d < util_v; d++){
		
			cout << v[d] << " ";
		}

		//cout << "  (cambio realizado)\n" << restaurar;

	} 
}
