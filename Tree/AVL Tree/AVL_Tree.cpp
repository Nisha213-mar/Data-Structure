//AVL Tree Implementation
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
class AVLTree{
public:
    TreeNode *root;
    AVLTree(){
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
//Calculate Height
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
	TreeNode *minValueNode(TreeNode *node){
	    TreeNode *current=node;
	    //loop to find the leftmost leaf
	    while(current->left!=NULL){
            current=current->left;
	    }
	    return current;
	}
	//Deletion in AVL Tree
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
        int bf=getBlanceFactor(r);
        //left left imbalance/case or right rotation
        if(bf==2 && getBlanceFactor(r->left)>=0)
            return rightRotate(r);
        //LR Rotation
        else if(bf==2 && getBlanceFactor(r->left)==-1){
            r->left=leftRotate(r->left);
            return rightRotate(r);
        }
        // right right imbalance case or left rotation
        else if(bf==-2 && getBlanceFactor(r->right)<=-0)
            return leftRotate(r);
        //left left imbalance case or rl rotation
        else if(bf==-2 && getBlanceFactor(r->right)==1){
            r->right=rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }
	//Print the AVL Tree
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
  //Recursive Search Method
  TreeNode * recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
  }

};
int main(){
    AVLTree obj;
    int option,val;
    do{
    cout<<"What Operation do you want to perform?"<<"Select Option number.Enter 0 to exit."<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Search Node"<<endl;
    cout<<"3. Delete Node"<<endl;
    cout<<"4. Print AVL values"<<endl;
    cout<<"5. Height of Tree"<<endl;
    cout<<"6. Clear Screen"<<endl;
    cout<<"0. Exit Program"<<endl;
    cin>>option;
    //node n1
    TreeNode *new_node=new TreeNode();
    switch(option){
    case 0:
        break;
    case 1:
        cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
	      cin >> val;
	      new_node->value = val;
	      obj.root=obj.insertRecursive(obj.root,new_node);
          //obj.insertNode(new_node);
	      cout<<endl;
    		break;
    case 2:
        cout<<"SEARCH"<<endl;
        cout<<"Enter the value to search in AVL Tree:"<<endl;
        cin>>val;
        new_node=obj.recursiveSearch(obj.root,val);
        if(new_node!=NULL){
            cout<<"Value Found"<<endl;
        }
        else{
            cout<<"Value Not Found."<<endl;
        }


        break;
    case 3:
        cout<<"DELETE"<<endl;
        //Insertion Node
        cout<<"Enter VALUE of TREE NODE to DELETE in AVL Tree";
        cin>>val;
        new_node=obj.recursiveSearch(obj.root,val);
        if(new_node!=NULL){
            obj.deleteNode(obj.root,val);
            cout<<"Value Deleted"<<endl;
        }
        else{
            cout<<"VALUE NOT found"<<endl;
        }
        break;
    case 4:
        cout<<"PRINT AVL VALUE"<<endl;
        obj.print2D(obj.root,5);


        break;
    case 5:
        cout<<"The Height :"<<endl;
        cout<<"Height :"<<obj.height(obj.root)<<endl;
        break;
    case 6:
        cout<<"CLEAR SCREEN"<<endl;
        system("cls");
        break;
    default:
        cout<<"Enter proper Option Number"<<endl;
    }

    }while(option!=0);
}

