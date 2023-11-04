//{ Driver Code Starts
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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void setParentPtrs(Node* root,Node* parent,unordered_map<Node*,Node*>&parentHash){
        if(root == NULL)return;
        parentHash[root] = parent;
        setParentPtrs(root->left,root,parentHash);
        setParentPtrs(root->right,root,parentHash);
    }
    
    Node*giveTargetNode(Node* root,int target){
        if(root == NULL)return NULL;
        if(target == root->data)return root;
    
        Node* targetNode = NULL;
        targetNode = giveTargetNode(root->left,target);
        if(targetNode)return targetNode;
        targetNode = giveTargetNode(root->right,target);
        if(targetNode)return targetNode;
        
        return NULL;
    }
    
     int burnTree(Node*root,unordered_map<Node*,Node*>&mapping){
       unordered_map<Node*,bool>visited;
       int ans = 0;
       //level order traversal
       queue<Node*>q;
       q.push(root);
       visited[root]=true;
       
       while(!q.empty()){
           bool flag = false;
           int size = q.size();
           for(int i=0;i<size;i++){
            //   process neighboring nodes
            Node* front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]){
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }    
            
            if(front->right && !visited[front->right]){
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            
            if(mapping[front] && !visited[mapping[front]]){
                flag = true;
                q.push(mapping[front]);
                visited[mapping[front]] = true;
            }
           }
       
           if(flag)ans++;
       }
       
       return ans;
   }
    
    int minTime(Node* root, int target) 
    {
        // Child - Parent Mapping
        unordered_map<Node*,Node*>parentHash;
        parentHash[root] = NULL;
        setParentPtrs(root->left,root,parentHash);
        setParentPtrs(root->right,root,parentHash);
        
        
        // Finding targetNode
        Node* targetNode =  giveTargetNode(root,target);

        return burnTree(targetNode,parentHash);
    }
};

//{ Driver Code Starts.

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