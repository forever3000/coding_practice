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

        // Mirror function
        void Mirror(BST *);

        // In order traversal
        void InOderTraversal(BST *);

        void PrintLeftView(BST *);
        void PrintRightView(BST *);
        void PrintLeaf(BST *);
        // Boundary traversal
        void BoundaryTraversal(BST *);
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

void BST::Mirror(BST *root) {
    if (root == NULL) {
        return;
    }

    Mirror(root->left);
    Mirror(root->right);
    BST *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void BST::InOderTraversal(BST *root) {
    if (root == NULL) {
        return;
    }

    InOderTraversal(root->left);
    cout << root->data << endl;
    InOderTraversal(root->right);
}

void BST::PrintLeftView(BST *root) {
    if (root == NULL) {
        return;
    }

    if (root->left) {
        cout << root->data << " ";
        PrintLeftView(root->left);
    } else if (root->right) {
        cout << root->data << " ";
        PrintLeftView(root->right);
    }
}

void BST::PrintRightView(BST *root) {
    if (root == NULL) {
        return;
    }

    if (root->right) {
        PrintRightView(root->right);
        cout << root->data << " ";
    } else if (root->left) {
        PrintRightView(root->left);
        cout << root->data << " ";
    }
}

void BST::PrintLeaf(BST *root) {
    if (root == NULL) {
        return;
    }

    PrintLeaf(root->left);
    if(root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
    }
    PrintLeaf(root->right);
}

void BST::BoundaryTraversal(BST *root) {
    cout << root->data << " ";
    PrintLeftView(root->left);
    PrintLeaf(root->left);
    PrintLeaf(root->right);
    PrintRightView(root->right);
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
    b.Insert(root, 70);
    b.Insert(root, 80);
    b.InOderTraversal(root);
    //b.Mirror(root);
    //cout << " After mirror: " << endl;
    //b.InOderTraversal(root);
    cout << "Boudary Traversal: " << endl;
    b.BoundaryTraversal(root); 


    return 0;
}
