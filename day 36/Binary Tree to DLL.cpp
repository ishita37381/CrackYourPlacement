class Solution {
  public:
    Node* bToDLL(Node* root) {
        // code here
        stack<Node*> s;
        Node* ans = new Node(-1);
        Node* curr = ans, *prev = NULL, *temp = root;
        while(!s.empty() || temp){
            if (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            } else {
                temp = s.top();
                s.pop();
                
                curr->right = new Node(temp->data);
                curr = curr->right;
                curr->left = prev;
                prev = curr;
                
                temp = temp->right;
            }
        }
        curr->right = NULL;
        
        return ans->right;
    }
};
