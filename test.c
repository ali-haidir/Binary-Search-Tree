#include<stdio.h>
#include<iostream>
#include <vector>

using namespace std;

class BST {
  public:
    int data;
    BST *left, *right;


    BST();

    BST(int);

    BST* Insert(BST*, int);

    void Inorder(BST*);

    BST* LCA(BST* root, int n1, int n2)
    {
        if (root == NULL)
            return root;
        if (root->data == n1 || root->data == n2)
            return root;

        BST* left = LCA(root->left, n1, n2);
        BST* right = LCA(root->right, n1, n2);

        if (left != NULL && right != NULL)
            return root;
        if (left == NULL && right == NULL)
            return NULL;
        if (left != NULL)
            return LCA(root->left, n1, n2);

        return LCA(root->right, n1, n2);
    }

    int findLevel(BST* root, int k, int level)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return level;

        int left = findLevel(root->left, k, level + 1);
        if (left == -1)
            return findLevel(root->right, k, level + 1);
        return left;
    }


    int findDistance(BST* root, int a, int b)
    {

        BST* lca = LCA(root, a, b);

        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);

        return d1 + d2;
    }

};

BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
    if (!root) {
        return new BST(value);
    }

    if (value > root->data) {

        root->right = Insert(root->right, value);
    }
    else if (value < root->data){

        root->left = Insert(root->left, value);
    }


    return root;
}

void BST ::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int BSTdistance(const std::vector<int>& values, int nodeA, int nodeB)
{
// TODO your code here
int arr[]={8, 7, 13, 6, 2, 5, 1, 9, 11, 3, 4, 10 };

BST b, *root = NULL;

int len = sizeof(arr)/sizeof(arr[0]);

root = b.Insert(root, arr[0]);
for(int i=1 ; i<=len -1 ; i++){
// cout << "arr[i] = " << arr[i]<<endl;
b.Insert(root, arr[i]);
}

b.Inorder(root);
cout<<endl;

cout << "Dist(4, 2) = " << b.findDistance(root, 4, 2)<<endl;
cout << "\nDist(4, 0) = " << b.findDistance(root, 4, 0)<<endl;


return 0;
}

int main()
{

     BSTdistance({ 8, 7, 13, 6, 2, 5, 1, 9, 11, 3, 4, 10}, 4, 2);
    return 0;
}
