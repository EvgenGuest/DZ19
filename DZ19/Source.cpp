#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <typename T> void showArray(T array[], int length);

//Задача 1. 
int divider(int n1, int n2) {
	int num = 0;
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (n1 % i == 0 && n2 % j == 0 && i == j)
				num = i;
		}
	}
	return num;
}

//Задача 2. Решил не сам, нашел в инете. Разобрался как работает. Гениально!!!))))
int resurveNumber(int num) {
	int a = 0;
	while (num) {
		a = a * 10 + num % 10;
		num /= 10;
	}
	return a;
}

//Задача 3.
template <typename T> int indexSerch(T array[], int length, T key) {
	for (int i = 0; i < length; i++)
		if (array[i] == key)			
			return i;
	return -1;
}

 template <typename T> void arrayZ3(T array[], int length, T key) {
	 int z=1;
	 for (int i = 0; i < length; i++){
		 if (array[i] == key)
			 z += i;		 
	 }
	 for (int i = length - 1; i >= z; i--) {
		 for (int j = z; j < i; j++)
			 if (array[j] < array[j + 1])
				 swap(array[j], array[j + 1]);
		 cout << array[i]<<" ";
	 }	 
 }

 //Задача 4.
 template <typename T> void arrayAB(T array[], int length, T key = 0, int begin = 0) {
	 for (int i = 0; i < 20; i++) {
		 array[i] = rand() % (begin-20) + key;
		 cout << array[i] << " ";
	 }
	 cout << endl;
 }

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int num, n1, n2, N;	
	
	//Задача 1.
	cout << "Задача 1.\nВведите первое число: ";
	cin >> n1;
	cout << "Введите второе число: ";
	cin >> n2;
	cout << "Наибольший общий делитель двух чисел: " << divider(n1, n2);
	cout << "\n\n";

	//Задача 2.
	cout << "Задача 2.\nВведите число:\n";
	cin >> num;	
	cout << resurveNumber(num);
	cout << "\n\n";
	
	//Задача 3.
	cout << "Задача 3.\nИзначальный массив:\n";
	int arr[10]={ 3, 10, 15, 20, 4, 8, 30, 12, 7, 62 };
	showArray(arr, 10);
	cout << "\nВведите чило:";
	cin >> N;
	cout<<"Число "<< N << " является " << indexSerch(arr,10,N)<< " элементом массива\n";		
	cout << "Отсортированный массив:\n";
	arrayZ3(arr,10,N);
	cout << "\n\n";

	// Задача 4.
	cout << "Задача 4.\n";
	int z4[20];
	arrayAB(z4, 20, 20, 60);
	
	return 0;
}

template <typename T> void showArray(T array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]";
}