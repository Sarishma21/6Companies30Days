// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;

        //find target
        queue<Node*> q1;
        q1.push(root);

        Node* node;

        while(!q1.empty()) {
            node = q1.front();
            q1.pop();
            
            if(node->data == target) {
                break;
            }

            if(node->left != NULL) {
                parent[node->left] = node;
                q1.push(node->left);
            }

            if(node->right != NULL) {
                parent[node->right] = node;
                q1.push(node->right);
            }
        }

        // find largest dist
        queue<Node*> q2;
        q2.push(node);
        q2.push(NULL);

        unordered_map<Node*, bool> queued;
        int dist = -1;

        while(!q2.empty()) {

            node = q2.front();
            q2.pop();

            if(node == NULL) {
                ++dist;
                if(!q2.empty()) {
                    q2.push(NULL);
                }
                continue;
            }

            if(node->left != NULL && !queued.count(node->left)) {
                q2.push(node->left);
                queued[node->left] = true;
            }

            if(node->right != NULL && !queued.count(node->right)) {
                q2.push(node->right);
                queued[node->right] = true;
            }

            if(parent.count(node) && !queued.count(parent[node])) {
                q2.push(parent[node]);
                queued[parent[node]] = true;
            }
        }

        return dist;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends