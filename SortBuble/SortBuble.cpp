#include <iostream>

using namespace std;

int main() {

	int size = 10;

	int arr[] = { 4,10,6,12,7,1,9,2,3,6 };


	int temp;

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
	return 0;
}
