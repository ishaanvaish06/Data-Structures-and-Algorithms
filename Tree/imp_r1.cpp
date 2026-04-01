#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node * right;
    Node(int x) {
        this->data = x;
        right=left=NULL;
    }
};
int idx=-1;
Node* buildTr(vector<int> &v) {
    idx++;
    if (v[idx]==-1) return NULL;
    Node *root=new Node(v[idx]);
    root->left=buildTr(v);
    root->right=buildTr(v);
    return root;
}

void linetoline(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node *curr=q.front();
        if (curr==NULL) {
            q.pop();
            cout<<endl;
            if (!q.empty()) q.push(NULL);
        }
        else {
            cout<<curr->data<<" ";
            q.pop();
            if (curr->left!=NULL) q.push(curr->left);
            if (curr->right!=NULL) q.push(curr->right);
        }
    }
}

void printTree(Node *root) {
    if (root==NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}

map<int,int> m;
void acessTre(Node *root,int c) {
    if (root==NULL) return;
    if (!m[c]) {
        m[c]=root->data;
        cout<<root->data<<" ";
    }
    acessTre(root->left,c-1);
    acessTre(root->right,c+1);
}

int diameter=INT_MIN;
int height(Node *root) {
    if (root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    diameter=max(diameter,lh+rh);
    return max(lh,rh)+1;
}

int main() {
    vector<int> v={1,2,-1,-1,3,4,5,6,-1,-1,-1,-1,7,-1,8,-1,9,-1,10,-1,-1};
    Node* root=buildTr(v);
    printTree(root);
    cout<<endl;
    cout<<height(root)<<endl;
    cout<<diameter<<endl;
    linetoline(root);
    acessTre(root,0);
    return 0;
}