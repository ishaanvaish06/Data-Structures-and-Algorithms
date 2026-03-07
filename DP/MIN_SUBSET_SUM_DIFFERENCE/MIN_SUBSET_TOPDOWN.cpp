//S1 + S2= ARRAY
//S1-S2=MIN
//S1-ARRAY+S1=MIN => 2S1-ARRAY
//S1 = [0,ARRAY/2]

#include<bits/stdc++.h>
using namespace std;

int t[101][10001];
int check(vector<int>& arr,int n,int sum) {
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<sum+1;j++) {
            if (i==0) {
                t[i][j] = false;
            }
            if (j==0) {
                t[i][j] = true;
            }
            else if (i!=0 && j!=0 && arr[i-1]<=j) {
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int knapsack(vector<int>& arr) {
    int n=arr.size();
    int range=0;
    for (int i=0;i<n;i++) {
        range += arr[i];
    }
    for (int i=range/2;i>=0;i--) {
        bool res= check(arr,n,i);
        if (res) {
            return range-(2*i);
            break;
        }
    }
    return 0;
}

int main() {
    vector<int> arr={1,6,11,5};
    int res=knapsack(arr);
    cout<<res;
}
