// A binary search based program to find the 
// only missing number in a sorted array of 
// distinct elements within limited range. 
#include <iostream> 
using namespace std; 
  
class BST {
    private:
        int data;
        BST *left;
        BST *right;
    public:
        // Default contructor
        BST();

        // Parametereized constructor
        BST(int);
       
        // Insert function
        BST *Insert(BST *, int);

        // In order traversal
        void InOderTraversal(BST *);
};

BST::BST():data(0), left(NULL), right(NULL){};

BST::BST(int value) {
    data = value;
    left = NULL;
    right = NULL;
}

BST *BST::Insert(BST *root, int value) {
    if (root == NULL) {
        return new BST(value);
    }
    
    if (value < root->data) {
        root->left = Insert(root->left, value);
    } else if (value > root->data) {
        root->right = Insert(root->right, value);
    }

    return root;
}

void BST::InOderTraversal(BST *root) {
    if (root == NULL) {
        return;
    }

    InOderTraversal(root->left);
    cout << root->data << endl;
    InOderTraversal(root->right);
}

int main (void) {
    BST b;
    BST *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 40);
    b.Insert(root, 20);
    b.Insert(root, 10);
    b.Insert(root, 15);
    b.Insert(root, 27);
    b.Insert(root, 36);
    b.Insert(root, 45);
    b.Insert(root, 76);
    b.InOderTraversal(root);

    return 0;
}
