/*
    BST Implementation
    Binary Search Tree - BST
*/

#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// search BST by the given key
struct node* search(struct node* root, int key) { 
    if (root == NULL || root->key == key) {
       return root; 
    }
    if (root->key < key) {
       return search(root->right, key); 
    } 
    return search(root->left, key); 
} 

// in order BST traverssal
void in_order(struct node *root) { 
    if (root != NULL) { 
        in_order(root->left); 
        cout << root->key << " ";
        in_order(root->right); 
    } 
} 

// post order BST traveral
void post_order(struct node *root) { 
    if (root != NULL) { 
        post_order(root->left); 
        post_order(root->right); 
        cout << root->key << " ";
    } 
} 

// pre order BST traversal
void pre_order(struct node *root) { 
    if (root != NULL) { 
        cout << root->key << " ";
        pre_order(root->left); 
        pre_order(root->right); 
    } 
} 

// recursively insert a new node in to the BST
struct node* insert(struct node *root, int key) {
    struct node *temp = new struct node;
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL) {
        return temp;   
    } else {
        if(key < root->key) {
            root->left = insert(root->left, key);
        } else if(key > root->key) {
            root->right = insert(root->right, key);
        }
    }
}

// return the minimum node in the BST
struct node * min_node(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  
// delete a node with a given key from the BST
struct node* delete_node(struct node* root, int key) { 
    if (root == NULL) return root; 

    if (key < root->key) 
        root->left = delete_node(root->left, key); 
  
    else if (key > root->key) 
        root->right = delete_node(root->right, key); 
 
    else { 
 
        if (root->left == NULL) { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }  
        struct node* temp = min_node(root->right); 

        root->key = temp->key; 
  
        root->right = delete_node(root->right, temp->key); 
    } 
    return root; 
} 

int main() {
    struct node *root = NULL;
    root = insert(root, 5);
    insert(root, 10);
    insert(root, 6);
    insert(root, 9);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 19);

    delete_node(root, 6);

    cout << "In Order Traversal: ";
    in_order(root);
    cout << endl;
    cout << "Pre Order Traversal: ";
    pre_order(root);
    cout << endl;
    cout << "Post Order Traversal: ";
    post_order(root);
    cout << endl;

}
