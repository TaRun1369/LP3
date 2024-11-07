

#include <bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int freq;
    char symbol;
    string huffman;
    Node* left,*right;
    
    Node(int freq , char symbol){
        this->freq = freq;
        this->symbol = symbol;
        left = right = NULL;
    }
};

struct Compare{
   bool operator ()(Node* l,Node* r){
      return l->freq > r->freq;
  }  
};

void printCodes(Node* root,string code = ""){
    if (root == NULL) return;
    string newcode = code + root->huffman;
    
    if(root->left) printCodes(root->left,newcode);
    if(root -> right) printCodes(root->right,newcode);
    
    if(!root->left && !root->right){
        cout<<root->symbol <<" -> "<<newcode<<endl;
    }
} 

// Function to print the Huffman Tree without lines or indentation, level by level
void printTree(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        
        // Print all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();

            // Print the symbol and frequency if it's a leaf node, or just frequency if internal node
            if (node->symbol != '\0') {
                cout << node->symbol << " (" << node->freq << ") ";
            } else {
                cout << "(" << node->freq << ") ";
            }

            // Add left and right children to the queue if they exist
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // Newline after each level
    }
}



int main()
{
  vector<int> syms = {'a','b','c','d','e'};
  vector<int> freqs = {121,122,123,124,125};

//  vector<char> syms = {'a', 'b', 'c', 'd', 'e'};
//     vector<int> freqs = {100, 12, 24, 105, 38};
   priority_queue<Node* , vector<Node*> ,Compare > minHeap;
   
   for(int i = 0;i<5;i++){
       minHeap.push(new Node (freqs[i],syms[i]));
   }
   
   while(minHeap.size() > 1){
       Node* lef = minHeap.top();
       minHeap.pop();
       Node* rig = minHeap.top();
       minHeap.pop();
       lef->huffman = "0";
       rig->huffman = "1";
       
       Node* nN = new Node(lef->freq + rig->freq, '\0');
       nN ->left = lef;
       nN->right = rig;
       
       minHeap.push(nN);
   }
   
   Node* root = minHeap.top();

    // Print the Huffman codes by traversing the Huffman Tree
    cout << "Huffman Codes:\n";
    printCodes(root);

    // Print the Huffman Tree structure
    cout << "\nHuffman Tree Structure:\n";
    printTree(root);

}