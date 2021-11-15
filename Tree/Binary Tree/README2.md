<h1>Binary Search Tree And Implementations :</h1>
<h1>Binary Search Tree :</h1>
<h2>A binary search tree (BST) is a binary tree where each node has a Comparable key (and an associated value) and satisfies the restriction that the key in any node is larger than the keys in all nodes in that node's left subtree and smaller than the keys in all nodes in that node's right subtree.</h2>
<img src="https://cdn.shortpixel.ai/client/to_avif,q_glossy,ret_img,w_1880/https://simplesnippets.tech/wp-content/uploads/2020/10/binary-tree-vs-binary-search-tree-diagram.png">
<h1>Prerequisites :</h1>
<h2>[Recursion Playlist]</h2>( https://www.youtube.com/playlist?list=PLy-G6jmofTJVCsc-tDDn8URgxHj9I4D9f)
<h1>Implementations :</h1>
<h2>1. Insert a Node(Iterative Approach)</h2>
<h2>2. Insert a Node(Recursive Approach)</h2>
<h2>3. Insert a Node(Level Order Insertion)</h2>
<h2>4. Print 2D</h2>
<h2>5. Height of tree</h2>
<h2>6. Print Pre-Order Traversal (NODE, LEFT, RIGHT)</h2>
<h2>7. Print In-Order Traversal (LEFT, NODE, RIGHT)</h2>
<h2>8. Print Post-Order Traversal (LEFT, RIGHT, NODE)</h2>
<h2>9. Print all Paths from Root to Leaf Nodes</h2>
<h2>10. Search in Binary Search Tree (Iterative Approach)</h2>
<h2>11. Search in Binary Search Tree (Recursive Approach)</h2>
<h2>12. Delete Node</h2>
<h2>13.Check Weather tree is balanced or not</h2>
<h1>0 - Class Definition containing all above Functions</h1>

```cpp
#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
    }
};
class BST{
public:
    TreeNode *root;
    BST(){
        root=NULL;
    }
    bool isTreeEmpty(){
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }
     

```
<h1>1 - Insert a Node (Iterative Approach):</h1>
<h3>[Video Reference](https://youtu.be/6U4K-7fu_4A)</h3>
<img src="https://i.ibb.co/Z8j9KS4/Insertion-Pseudocode.png">

```cpp
//Insert Node on tree

     void insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }

```
