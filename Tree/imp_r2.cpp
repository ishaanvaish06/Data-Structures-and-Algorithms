#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        this->data=x;
    }
};
int idx=-1;
Node* buildTre(vector<int>& pre) {
    idx++;
    if (pre[idx]==-1 || idx>=pre.size()) return NULL;
    Node* root=new Node(pre[idx]);
    root->left=buildTre(pre);
    root->right=buildTre(pre);
    return root;
}

int dia=INT_MIN;
int height(Node* root) {
    if (root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    dia=max(dia,lh+rh);
    return (lh>rh?lh:rh)+1;
}

int levelOrder(Node* root) {
    int count=0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        if (q.front()==NULL) {
            q.pop();
            cout<<endl;
            if (!q.empty()) q.push(NULL);
        }
        else {
            Node*temp=q.front();
            count++;
            q.pop();
            cout<<temp->data<<" ";
            if (temp->left!=NULL) q.push(temp->left);
            if (temp->right!=NULL) q.push(temp->right);
        }
    }
    cout<<endl;
    return count;
}

int main() {
    vector<int> pre;
    pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTre(pre);
    cout<<height(root)<<endl;
    cout<<dia<<endl<<endl;
    cout<<levelOrder(root);
    return 0;
}

