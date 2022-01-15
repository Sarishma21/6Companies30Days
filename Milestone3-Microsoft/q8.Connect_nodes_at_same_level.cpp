class Solution {
    public:
    void connect(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
    
            if(node == NULL) {
                if(!q.empty()) {
                    q.push(NULL);
                }
                continue;
            }
            
            node->nextRight = q.front();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
};