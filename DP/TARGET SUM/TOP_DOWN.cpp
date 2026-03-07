#include <vector>
int t[101][10001];
int knapsack(vector<int> &arr,int sum) {
    int range=0;
    for (int i=0;i<arr.size();i++) {
        range=range+arr[i];
    }
    int s1=(range+sum)/2;

    for (int i=0;i<=arr.size();i++) {
        t[0][i]=0;
    }

    for (int i=0;i<=s1;i++) {
        t[i][0]=1;
    }

    for (int i=1;i<=arr.size();i++) {
        for (int j=1;j<=s1;j++) {
            if (arr[i-1]<=j) {
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[arr.size()][s1];
}