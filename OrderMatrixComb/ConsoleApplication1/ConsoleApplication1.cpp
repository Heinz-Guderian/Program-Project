

#include "pch.h"
#include <iostream>

using namespace std; 
int main()
{
	
	       setlocale(LC_ALL, "rus");
	

			cout<< "\n\tОбъеденяем две таблицы в одну A+B=C\n";


			const int n =10; 

			
			int A [n] ;  
			int B [n] ;
			int C [n*2] ;


			int k = 0;
			for (int i = 0; i < n; i++) {
				A[i] = (rand()%100);
				B[i] = (rand()%100);
				C[k] = A[i]; C[k + 1] = B[i];
				k += 2;
			}

			//Arrays.sort(A);
			//Arrays.sort(B);
			//Arrays.sort(C);
            int temp;
			for (int i = 0; i < n; i++) {
				
				
				if (A[i] > A[i+ 1]) {
					
					temp = A[i];
					A[i] = A[i + 1];
					A[i + 1] = temp;
				}
			printf("A[%d]=%d  ", i, A[i]);
			}
			cout << "\n";

			for (int i = 0; i < n; i++) {
			printf("B[%d]=%d  ", i, B[i]);
			}
			cout<< "\n";


			for (int i = 0; i < 2 * n; i++) {
			printf("C[%d]=%d\n", i, C[i]);
			}
			cout << "\n"; "\n";


	system("pause");
	return 0;
}

