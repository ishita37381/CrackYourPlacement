/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    Node* findSucc(Node* root,int key){
        Node* s=NULL;
        while(root){
            if(root->key>key){
                s=root;
                root=root->left;
            }
            else root=root->right;
        }
        return s;
    }
    Node * findPre(Node* root,int key){
        Node* p=NULL;
        while(root){
            if(root->key<key){
                p=root;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return p;
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        suc=findSucc(root,key);
        pre=findPre(root,key);
    }
};
