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
<h2>9. print Nodes at a given level</h2>
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
<h1>2 - Insert a Node(Recursive Approach) :</h1>
<h3>[Video Reference] (https://youtu.be/x6t1lKzjGhY)</h3>
<img src="https://i.ibb.co/vcbxQjB/bst-insert-recursive.png">

```cpp
//Insert the Node through recursive Method
  TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}

		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r;
		}
		return r;
	}
  ```
  <h1>4 - Print 2D :</h1>
  <h3>[Video Reference] (https://youtu.be/xhkSiIeTKQo)</h3>
<img src="https://i.ytimg.com/vi/xhkSiIeTKQo/maxresdefault.jpg">

```cpp
void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5
      cout << " "; // 5.1
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
  ```
  <h1>5 - Height of Tree :</h1>
  <h3>[Video Reference] (https://www.youtube.com/watch?v=M-ovXwd6_0I)</h3>
  <img src="https://i.ytimg.com/vi/_pnqMz5nrRs/maxresdefault.jpg">

  ```cpp
  // Find Height of Tree Node
    int height(TreeNode *r){
        if(r==NULL)
            return -1;
        else{
                //Compute height of each subtree
            int lheight=height(r->left);
            int rheight=height(r->right);
        //use the larger one
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
        }
    }
   ```
   <h1>Print Pre-Order Traversal (NODE, LEFT, RIGHT) :</h1>
  <h3>[Video Reference] (https://youtu.be/Pj5w6qnCXes)</h3>
  <img src="https://i.ibb.co/Dz3mVrv/preorder.png">

  ```cpp
  //print Preorder
    void Printpreorder(TreeNode *r){
        if(r==NULL)
            return;
        cout<<r->value<<" ";
        Printpreorder(r->left);
        Printpreorder(r->right);
    }
```
<h1>7. Print In-Order Traversal (LEFT, NODE, RIGHT)</h1>
<h3>[Video Reference](https://www.youtube.com/watch?v=KIVdqquGehY)</h3>
<img src="https://i.ibb.co/nDmK5q2/inorder.png">

```cpp
//Print Inorder
    void PrintInorder(TreeNode *r){
        if(r==NULL)
            return;
        PrintInorder(r->left);
        cout<<r->value<<" ";
        PrintInorder(r->right);
    }
```
<h1>8. Print Post-Order Traversal (LEFT, RIGHT, NODE)</h1>
<h3>[Video Reference](https://www.youtube.com/watch?v=fC3s5Pj2KuE)</h3>
<img src="https://i.ibb.co/841kbrF/postorder.png">

```cpp
 void PrintPostorder(TreeNode *r){
        if(r==NULL)
            return;
        PrintPostorder(r->left);
        PrintPostorder(r->right);
        cout<<r->value<<" ";
    }
```
<h1>9. print Nodes at a given level </h1>
<img src="https://media.cheggcdn.com/study/0fd/0fd1fe97-c205-4eb9-948a-bcd124d3c1c7/image.png">

```cpp
//print Nodes at a given level
    void printGivenLevel(TreeNode *r,int level){
        if(r==NULL)
            return;
        else if(level==0)
            cout<<r->value<<" ";
        else{//level>0
            printGivenLevel(r->left,level-1);
            printGivenLevel(r->right,level-1);
        }
    }
    void printLevelOrderBFS(TreeNode *r){
        int h=height(r);//calculate height of Tree
        for(int i=0;i<=h;i++){
            printGivenLevel(r,i);
        }
    }
```

<h1>10. Search in Binary Search Tree (Iterative Approach)</h1>
<h3>[Video Reference](https://youtu.be/adBuxEjVwYk)</h3>
<img src="https://i.ibb.co/h7FdKrf/searchiterative.png">

```cpp
//Iterative search
    TreeNode *iterativeSearch(int val){
        if(root==NULL)
            return root;
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(val==temp->value)
                    return temp;
                else if(val<temp->value)
                    temp=temp->left;
                else
                    temp=temp->right;
            }

        return NULL;
        }
    }
```
<h1>11 - Search in Binary Search Tree (Recursive Approach)</h1>
<h3>[Video Reference](https://youtu.be/kU9Lv3e_kxs)</h3>

```cpp
//Insert the Node through recursive Method
  TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}

		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r;
		}
		return r;
	}
```
<h2>12. Delete Node :</h2>
<h3>[Video Reference](https://youtu.be/5_AZcOOc-kM)</h3>

```cpp
TreeNode *deleteNode(TreeNode *r,int v){
        //base case
        if(r==NULL){
            return NULL;
        }
        else if(v<r->value){
            r->left=deleteNode(r->left,v);
        }
        else if(v > r->value){
            r->right=deleteNode(r->right,v);
        }
        else{
            if(r->left==NULL){
                TreeNode *temp=r->right;
                delete r;
                return temp;
            }
            else if(r->right==NULL){
                TreeNode *temp=r->left;
                delete r;
                return temp;
            }
            else{
                TreeNode *temp=minValueNode(r->right);
                r->value=temp->value;
                r->right=deleteNode(r->right,temp->value);
            }
        }
        return r;
    }
};
```
<h1>13.Check Weather tree is balanced or not:</h1>
<h3>[Video Reference]:(https://www.youtube.com/watch?v=lUDgp2D6sf8)</h3>

```cpp
//Get Balance Factor
int getBlanceFactor(TreeNode *n){
    if(n==NULL){
        return -1;
    return height(n->left)-height(n->right);
    }
}
//For Right Rotation
TreeNode *rightRotate(TreeNode *y){
    TreeNode *x=y->left;
    TreeNode *T2=x->right;
    //Perform Rotation
    x->right=y;
    y->left=T2;

    return x;
}
//For Left Rotation
TreeNode *leftRotate(TreeNode *x){
    TreeNode *y=x->right;
    TreeNode *T2=y->left;
    //Perform Rotation
    y->left=x;
    x->right=T2;

    return y;
}
```






















