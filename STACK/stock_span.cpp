#include<bits/stdc++.h>
using namespace std;

vector<int> a(vector<int> &arr) {
    vector<int> res;
    stack<pair<int,int>> s;
    for (int i=0;i<arr.size();i++) {
        if (s.empty()) {
            res.push_back(i+1);
        }
        else if (s.size()>0 && s.top().first>arr[i]) {
            res.push_back(i-s.top().second);
        }
        else if (s.size()>0 && s.top().first<=arr[i]) {
            while (s.size()>0 && s.top().first<=arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                res.push_back(i+1);
            }
            else {
                res.push_back(i-s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    return res;
}