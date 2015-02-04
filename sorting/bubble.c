#include <stdio.h>

void swap(int *a, int *b)
{	
	//swap 2 elements
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble(int a[], int n)
{
	//sort using bubble sort algo
	int i;
	int j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int main()
{
	int n;
        int i;
        
        printf("Enter No. of Elements\n");
        scanf("%d",&n);
        int a[n];
        printf("Enter %d Elements in Sorted Order\n",n);
	
	//Array input
        for (i = 0; i < n; i++) {
                scanf("%d",&a[i]);
        }

	bubble(a, n);//calling function to sort array
	
	//Display sorted array
	printf("Sorted Array: ");
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}

