#include <iostream>

using namespace std;

int left(int i)
{
	//left node
	return (2 * i);
}

int right(int i)
{
	//right node
	return (2 * i + 1);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void max_heapify(int a[], int i, int heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest;

	//determine the largest among a[left],a[right] and a[i]
	if (l < heap_size && a[l] > a[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if(r < heap_size && a[r] > a[largest]) {
		largest = r;
	}

	//If a[i] is not largest then we need to max-heapify otherwise terminate
	if(largest != i) {
		swap(&a[i],&a[largest]);
		max_heapify(a, largest, heap_size);
	}
}

void build_max_heap(int a[], int n)
{	
	//to convert the array into a max heap
	int i;
	int heap_size = n;
	for(i = n / 2 ; i >= 0; i--)
		max_heapify(a, i, heap_size);
}

void heapsort(int a[], int n)
{
	int i;
	int heap_size = n;
	
	build_max_heap(a, n);//we build the array into a heap

	//exchange the top element of the heap with the last element and then heapify again after decreasing the heap size by 1
	for(i = n - 1; i > 0; i --) {
		swap(&a[0],&a[i]);
		heap_size--;
		max_heapify(a, 0, heap_size);
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
	int i,n;
	cout << "Enter Size of Array" << endl;
	cin >> n;
	
	int a[n];
	cout << "Enter " << n << " Numbers:" << endl;
	for(i = 0; i < n; i++)
		cin >> a[i];
	
	heapsort(a, n);

	cout << "Sorted Array: " << endl;
	printArray(a, n);

	return 0;
}
	

