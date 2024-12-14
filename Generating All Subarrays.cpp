#include<bits/stdc++.h>
using namespace std;

void Subarray(vector<int>&v,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<v[k]<<" ";
            }
            cout<<endl;
        }
    }
}


int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

Subarray(v,n);
}


output:
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 2
// 2 3
// 2 3 4
// 3
// 3 4
// 4
