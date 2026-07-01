#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
    }
};

int idx=-1;
Node* newNode(vector<int>& v) {
    idx++;
    if (v[idx]==-1 || idx>=v.size()) { return NULL; }
    Node* temp = new Node(v[idx]);
    temp->left = newNode(v[idx]);
    temp->right = newNode(v[idx]);
    return temp;
}

void height(Node* root) {
    if (root==NULL) { return; }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
int main() {
    vector<int> v={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=newNode(v);
    cout<<height(root)<<endl;

}