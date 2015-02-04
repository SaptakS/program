#include <iostream>

using namespace std;

void merge(int a[], int p, int q, int r)
{
	int i,j,k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int l[n1],m[n2];

	// storing 2 divided arrays
	for(i = 0; i < n1; i++)
		l[i] = a[p + i];
	for(i = 0; i < n2; i++)
		m[i] = a[q + i +1];

	//merging the arrays in sorted order
	i = 0;
	j = 0;
	k = p;
	while(i < n1 && j < n2) {
		if(l[i] < m[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = m[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		a[k++] = l[i++];
	}
	while(j < n2) {
		a[k++] = m[j++];
	}
}		

void mergeSort(int a[], int p, int r)
{
	if(p < r) {
		int q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
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

        mergeSort(a, 0, n - 1);
        cout << "Sorted Array:" << endl;
        printArray(a, n);

}

	
