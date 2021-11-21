<h1>What is Balanced BT :</h1>
<h3>Binary tree where the difference between the height of left subtree and right subtree **for every node** is not more than k(usually k=1). This difference is called balanced factor. **bf=|height of LST - height of RST</h3>
<h3>So for every node **height of LST - height of RST** should be {-1,0,1}.</h3>
<h1>AVL Tree :</h1>
<h3>AVL Tree is a self-balancing BST (i.e., basically a BST which remains balanced even though you insert or delete nodes).</h3>
<h1>Ways of Balancing AVL Tree</h1>

<h2>To maintain the balance in AVL Tree(i.e to be AVL tree always) while inserting and deleting, we perform Rotations. Depending on different imbalance cases, we have 4 basic types of rotations –</h2>

- **LEFT LEFT Imbalance/case - RIGHT Rotation**
- **RIGHT RIGHT Imbalance/case - LEFT Rotation**
- **LEFT RIGHT Imbalance/case - LEFT RIGHT Rotation**
- **RIGHT LEFT Imbalance/case - RIGHT LEFT Rotation**
<h3>[Video Reference](https://youtu.be/_nyt5QYel3Q)</h3>

![AVL Tree Rotation](https://user-images.githubusercontent.com/64855541/122770456-1522f400-d2c3-11eb-9d95-7bba74a9afc8.jpg)
[AVL Tree Rotation.pdf](https://github.com/thepranaygupta/Data-Structures-and-Algorithms/files/6686954/AVL.Tree.Rotation.pdf)
<h1>INSERTION IN AVL TREE</h1>

<h3>Step 1 (Optional) : [Theoretical Insertion in AVL Tree](https://youtu.be/f0BplF93TIA)</h3>

<h3>Step 2 : [Practical Insertion in AVL Tree dry run + code](https://youtu.be/otiDcwZbCo4)</h3>

```cpp
//Insert The Node in AVL Tree
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
		int bf=getBlanceFactor(r);
		//Left Left case
		if(bf>1 && new_node->value<r->left->value)
            return rightRotate(r);
        //Right Right case
        if(bf<-1 && new_node->value>r->right->value)
            return leftRotate(r);
        //left Right case
        if(bf>1 && new_node->value>r->left->value){
            r->left=leftRotate(r->left);
            return rightRotate(r);
        }
        //Right Left Case
        if(bf<-1 && new_node->value<r->right->value){
            r->right=rightRotate(r->right);
            return leftRotate(r);
        }
        //return the unchanged node pointer
        return r;

	}
```
