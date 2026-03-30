#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        right = left = NULL;
    }
};
int idx=-1;
Node* buildTre(vector<int>& pre) {
    idx++;
    if (pre[idx]==-1) return NULL;
    Node* root=new Node(pre[idx]);
    root->left = buildTre(pre);
    root->right = buildTre(pre);
    return root;
}

void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node*curr=q.front();
        if (curr->left!=NULL) q.push(curr->left);
        if (curr->right!=NULL) q.push(curr->right);

        cout<<curr->data<<" ";
        q.pop();

    }

}




int main() {
    vector<int> pre;
    pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTre(pre);
    printTree(root);
}