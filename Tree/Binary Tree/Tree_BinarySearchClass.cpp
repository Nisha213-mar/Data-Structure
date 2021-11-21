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
    //print The Tree
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
    //print Preorder
    void Printpreorder(TreeNode *r){
        if(r==NULL)
            return;
        cout<<r->value<<" ";
        Printpreorder(r->left);
        Printpreorder(r->right);
    }
    //Print Inorder
    void PrintInorder(TreeNode *r){
        if(r==NULL)
            return;
        PrintInorder(r->left);
        cout<<r->value<<" ";
        PrintInorder(r->right);
    }
    void PrintPostorder(TreeNode *r){
        if(r==NULL)
            return;
        PrintPostorder(r->left);
        PrintPostorder(r->right);
        cout<<r->value<<" ";
    }
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
    //Deletion of Node
    TreeNode *minValueNode(TreeNode *node){
        TreeNode *current=node;
        //Loop down to find the leftmost leaf
        while(current->left!=NULL){
            current=current->left;
        }
        return current;
    }
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
int main(){
    BST obj;
    int option,val;
    //TreeNode *new_node=new TreeNode();
    do{
    cout<<"What Operation do you want to perform?"<<"Select Option number.Enter 0 to exit."<<endl;
    cout<<"1. Insert Node"<<endl;
    cout<<"2. Search Node"<<endl;
    cout<<"3. Delete Node"<<endl;
    cout<<"4. Print BST values"<<endl;
    cout<<"5. Height of Tree"<<endl;
    cout<<"6. Clear Screen"<<endl;
    cout<<"0. Exit Program"<<endl;
    cin>>option;
    TreeNode *new_node=new TreeNode();
    switch(option){
    case 0:
        break;
    case 1:
        cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      obj.root=obj.insertRecursive(obj.root,new_node);
          //obj.insertNode(new_node);
	      cout<<endl;
    		break;
    case 2:
        cout<<"SEARCH"<<endl;
        cout<<"Enter the value to search :"<<endl;
        cin>>val;
        new_node=obj.iterativeSearch(val);
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
        cout<<"Enter VALUE of TREE NODE to DELETE in BST: ";
        cin>>val;
        new_node=obj.iterativeSearch(val);
        if(new_node!=NULL){
            obj.deleteNode(obj.root,val);
            cout<<"Value Deleted"<<endl;
        }
        else{
            cout<<"VALUE NOT found"<<endl;
        }
        break;
    case 4:
        cout<<"PRINT BST VALUE"<<endl;
        obj.print2D(obj.root,5);
        cout<<"PREORDER: ";
        obj.Printpreorder(obj.root);
        cout<<endl;
        cout<<"INORDER: ";
        obj.PrintInorder(obj.root);
        cout<<endl;
        cout<<"POSTORDER: ";
        obj.PrintPostorder(obj.root);
        cout<<endl;
        cout<<"Print Level Order BFS:\n";
        obj.printLevelOrderBFS(obj.root);
        cout<<endl;
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

    return 0;
}
