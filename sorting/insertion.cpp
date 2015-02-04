#include <iostream>

using namespace std;

void insertion(int a[], int n)
{
	int i,j;
	for(i = 1; i < n; i++) {
		int key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void printArray(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
        cout << "Enter Size" << endl;
        cin >> n;

        int a[n];
        int i;
        cout << "Enter " << n << " Numbers:" << endl;
        for(i = 0; i < n; i++) {
                cin >> a[i];
        }

        insertion(a, n);
        cout << "Sorted Array:" << endl;
        printArray(a, n);

}	
