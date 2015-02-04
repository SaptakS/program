#include <iostream>
#include <cstdlib>

using namespace std;

#define BITIFY(num,pos) (num >> pos & 1)

typedef struct node {
    int key;
    struct node *left, *right;
}node;

int nodes;
node *current, *temp, *first;

void addNode(node *, node *, int);
void swapify(int *, int *);
void getRoot(node *, int);
void heapify(node *);

int main()
{
    int num, i, j;
    char ch;
    do{
        cout << "Enter a Number" << endl;
        cin >> num;

        current = (node *)malloc(sizeof(node));
        if (current == 0)
            return 0;

        current->key = num;
        nodes++;

        for(i = nodes,j = -1; i; i >>= 1, j++);

        if(first == 0) {
            first = current;
            first->left = first->right = 0;
        }
        else
            addNode(first, first, j - 1);

        cout << "Do you want to add more number(y/n)?";
        cin >> ch;

    }while(ch != 'n');

    cout << "No of nodes is:" << nodes << endl;

    while (nodes) {
        cout << first->key << "=>";

        for(i = nodes, j = -1; i; i >>= 1, j++);
        getRoot(first, j - 1);
        nodes--;

        heapify(first);
    }
    cout << endl;
    return 0;
}

void swapify(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void addNode(node *tmp, node *parent, int pos)
{
    int directn = BITIFY(nodes, pos);//bit representatn of position

    //if pos = 0 which means that it is at the position to be inserted
    if(!pos) {
        if(directn)
            tmp->right = current;
        else
            tmp->left = current;

        current->left = current->right = 0;
        if(current->key > tmp->key)
            swapify(&current->key, &tmp->key);
    }

    //traverse to the position to be inserted
    else
        if(directn)
            addNode(tmp->right, tmp, pos - 1);
        else
            addNode(tmp->left, tmp, pos - 1);


    //heapify-up
    if(tmp->key > parent->key)
        swapify(&parent->key, &tmp->key);
}

void getRoot(node *temp, int pos)
{

    int directn;

    //if only 1 nodes
    if(nodes == 1) {
        return;
    }

    //traverse to the parentof the last element
    while(pos) {
        directn = BITIFY(nodes, pos);
        if(directn)
            temp = temp->right;
        else
            temp = temp->left;

        pos--;
    }

    //to see if the last element is at the left or right of its parent
    directn = BITIFY(nodes, pos);
    if(directn) {
        first->key = temp->right->key;
        free(temp->right);
        temp->right = 0;
    }
    else {
        first->key = temp->left->key;
        free(temp->left);
        temp->left = 0;
    }

}

void heapify(node *temp)
{

    if(!temp->right && !temp->left)
        return;

    if(!temp->right) {
        if(temp->left->key > temp->key)
            swapify(&temp->left->key, &temp->key);
    }

    else {

        if(temp->right->key > temp->left->key){
            if(temp->right->key > temp->key) {
                swapify(&temp->right->key, &temp->key);
                heapify(temp->right);
            }
        }

         else{
            if(temp->left->key > temp->key) {
                swapify(&temp->left->key, &temp->key);
                heapify(temp->left);
            }
        }
    }
}

