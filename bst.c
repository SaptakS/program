
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

long long counter;

struct node
{
    int key;
    struct node *left, *right;
};


struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct node *root)
{
	if(root != NULL) {
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->key);
	}
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int key)
{


    if (node == NULL) return newNode(key);


    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);


    return node;
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;


    while (current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(struct node* root, int key)
{
 
    if (root == NULL) return root;


    if (key < root->key)
        root->left = deleteNode(root->left, key);


    else if (key > root->key)
        root->right = deleteNode(root->right, key);


    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }


        struct node* temp = minValueNode(root->right);


        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


int main()
{
    clock_t start,end;

    struct node *root = NULL;
    int ch;
    int n,y,i;
	do {

	        printf("Menu:\n1.Insert\n2.Delete\n3.Minimum Value\n4.Preorder Display\n5.Inorder Display\n6. Postorder Display\n7.Exit\nEnter your choice:\n");
		scanf("%d", &ch);
		if(ch == 1) {
			printf("Enter Value of node:\n");
			scanf("%d", &n);
			root = insert(root, n);
		}
		else if(ch == 2) {
			printf("Enter No. to delete:\n");
			scanf("%d", &y);
			root = deleteNode(root, y);
		}

		else if(ch == 3) {
			
			printf("Min value: %d\n", (minValueNode(root)->key));
		}
		else if(ch == 4) {
			preorder(root);
		}
		else if(ch == 5) {
			inorder(root);
		}
		else if(ch == 6) {
			postorder(root);
		}
	}while(ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5 || ch == 6);



    return 0;
}
