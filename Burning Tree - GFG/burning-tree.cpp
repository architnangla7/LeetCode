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
  Node* markParents(Node*root,unordered_map<Node*,Node*>&parents_track,int target){
      queue<Node*>queue;
      queue.push(root);
      Node* result=0;
      parents_track[root]==NULL;
      
      while(!queue.empty()){
          Node* current=queue.front();
          queue.pop();
          
          if(current->data==target){
              result=current;
          }
          if(current->left){
              parents_track[current->left]=current;
              queue.push(current->left);
          }
          if(current->right){
              parents_track[current->right]=current;
              queue.push(current->right);
          }
      }
      return result;
  }
  int burnTree(Node*target,unordered_map<Node*,Node*>&parents_track)
  {
      unordered_map<Node*,bool>visited;
      queue<Node*>queue;
      queue.push(target);
      visited[target]=true;
      int ans=0;
      
      while(!queue.empty()){
          bool flag=0;
         int size=queue.size();
         for(int i=0;i<size;i++){
             Node* front=queue.front();
             queue.pop();
             
             if(front->left && !visited[front->left]){
                 flag=1;
                 queue.push(front->left);
                 visited[front->left]=true;
             }
             if(front->right && !visited[front->right]){
                 flag=1;
                 queue.push(front->right);
                 visited[front->right]=true;
             }
             if(parents_track[front] && !visited[parents_track[front]]){
                 flag=1;
                 queue.push(parents_track[front]);
                 visited[parents_track[front]]=true;
             }
         }
         if(flag==1)
         ans++;
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        int ans=0;
        unordered_map<Node*,Node*>parents_track;
        Node* targetNode=markParents(root,parents_track,target);
        
        ans=burnTree(targetNode,parents_track);
        return ans;
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