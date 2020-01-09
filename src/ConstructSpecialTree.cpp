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
        BST();
        BST(int);
        BST *Insert(BST*, int);
        void InOrderTraversal(BST*);
        void PreOrderTraversal(BST*);
        void PostOrderTraversal(BST*);
        int FindLevelOfNode(BST*, int);
        BST *ConstructTree(int[], char[], int);
        BST *ConstructTreeUtil(int[], char[],int*, int);
};

BST::BST():data(0),left(NULL),right(NULL){};

BST::BST(int value) {
    data = value;
    left = NULL;
    right = NULL;
}

BST *BST::Insert(BST *root, int value) {
    if (root == NULL) {
        return new BST(value);
    }

    if (value > root->data) {
        root->right = Insert(root->right, value);
    } else {
        root->left = Insert(root->left, value);
    }

    return root;
}

void BST::InOrderTraversal(BST *root) {
    if (root == NULL) {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << endl;
    InOrderTraversal(root->right);
}

void BST::PreOrderTraversal(BST *root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << endl;
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void BST::PostOrderTraversal(BST *root) {
    if (root == NULL) {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << endl;
}

BST *BST::ConstructTreeUtil(int pre[], char preLN[], int *index_ptr, int n) {
    int index = *index_ptr;

    if (index == n) {
        return NULL;
    }

    BST *temp = new BST(pre[index]);
    (*index_ptr)++;

    if (preLN[index] == 'N') {
        temp->left = ConstructTreeUtil(pre, preLN, index_ptr, n);
        temp->right = ConstructTreeUtil(pre, preLN, index_ptr, n);
    }

    return temp;
}

BST *BST::ConstructTree(int pre[], char preLN[], int n) {
    int index = 0;

    return ConstructTreeUtil(pre, preLN, &index, n);
}

int BST::FindLevelOfNode(BST *root, int value) {
    if (root == NULL) {
        return -5000;
    }

    if (root->data == value) {
        return 1;
    }

    if (value > root->data) {
        return FindLevelOfNode(root->right, value) + 1;
    } else {
        return FindLevelOfNode(root->left, value) + 1;
    }
}

int main (void) {
    BST b;
    BST *root;

    //root = b.Insert(root, 10);
    // b.Insert(root, 5);
    // b.Insert(root, 1);
    // b.Insert(root, 7);
    // b.Insert(root, 40);
    // b.Insert(root, 50);
    int pre[] = {10, 30, 20, 5, 15}; 
    char preLN[] = {'N', 'N', 'L', 'L', 'L'}; 
    int n = sizeof(pre)/sizeof(pre[0]);

    root = b.ConstructTree(pre, preLN, n);

    cout << "InOrder : " << endl;
    b.InOrderTraversal(root);
    cout << "PreOrder : " << endl;
    b.PreOrderTraversal(root);
    cout << "PostOrder : " << endl;
    b.PostOrderTraversal(root);

    cout << "Level of 70: " << b.FindLevelOfNode(root, 70) << endl;

    return 0;
}
