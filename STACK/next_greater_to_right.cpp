#include <bits/stdc++.h>
using namespace std;

vector<int> stak(vector<int> arr) {
    vector<int> res;
    stack<int> s;
    for (int i=arr.size()-1;i>=0;i--) {
        if (s.empty()) {
            res.push_back(-1);
        }
        else if (s.size()>0 && s.top()>arr[i]) {
            res.push_back(s.top());
        }
        else if (s.size()>0 && s.top()<=arr[i]) {
            while (s.size()>0 && s.top()<=arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                res.push_back(-1);
            }
            else {
                res.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    return res;
}
int main() {
    vector<int> arr={1,3,0,0,1,2,4};
    vector<int> res=stak(arr);
    reverse(res.begin(),res.end());
    for (int i=0;i<res.size();i++) {
        cout<<res[i]<<" ";
    }
}



