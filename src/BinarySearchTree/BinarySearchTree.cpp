// A binary search based program to find the 
// only missing number in a sorted array of 
// distinct elements within limited range. 
#include <iostream> 
#include <queue>
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

        // Height of tree
        int Height(BST *);

        // Print Given Level
        void PrintGivenLevel(BST *, int);

        // Level Order Traversal
        void LevelOrderTraversal(BST *);

        // Level Order Traverlal by queue
        void LevelOrderTraverlsalByQueue(BST *);
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

int BST::Height(BST *root) {
    if (root == NULL) {
        return 0;
    } else {
        int lheight = Height(root->left);
        int rheight = Height(root->right);
        return max(lheight, rheight) + 1;
    }
}

void BST::PrintGivenLevel(BST *root, int level) {
    if (root == NULL) {
        return;
    } else {
        if (level == 1) {
            cout << root->data << " ";
        } else {
            PrintGivenLevel(root->left, level - 1);
            PrintGivenLevel(root->right, level - 1);
        }
    }
}

void BST::LevelOrderTraversal(BST *root) {
    if (root == NULL) {
        return;
    } else {
        int height = Height(root);

        for (int i = 1; i <= height; i++) {
            PrintGivenLevel(root, i);
        }
    }
}

void BST::LevelOrderTraverlsalByQueue(BST *root) {
    if (root == NULL) {
        return;
    }

    queue<BST *> q;
    q.push(root);

    while (!q.empty()) {
        BST *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL) {
            q.push(node->left);
        }

        if (node->right != NULL) {
            q.push(node->right);
        }
    }
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
    
    cout << b.Height(root) << endl;
    b.LevelOrderTraversal(root);
    cout << "Level Order Traversal by queue: " << endl;
    b.LevelOrderTraverlsalByQueue(root);

    return 0;
}
