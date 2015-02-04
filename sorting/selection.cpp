#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void selection(int a[], int n)
{
	int i,j;
	int pos;
	for(i = 0; i < n - 1; i++) {
		pos = i;
		for(j = i + 1; j < n; j++) {
			if (a[j] < a[pos])
				pos = j;
		}
		swap(&a[pos], &a[i]);
	}
}

void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
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

	selection(a, n);
	cout << "Sorted Array:" << endl;
	printArray(a, n);
}
