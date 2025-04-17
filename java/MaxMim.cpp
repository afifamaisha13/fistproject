
#include<bits/stdc++.h>
using namespace std;
int a[50];
void MaxMin(int i,int j,int &max,int &min){
    if(i==j)
        max=min=a[i];

    else if(i==j-1){
        if(a[i]<a[j]){
            max=a[j];
            min=a[i];
        }
        else{
            max=a[i];
            min=a[j];
        }

    }

    else {
        int mid=(i+j)/2;
        int max1,min1;

        MaxMin(i,mid,max,min);
        MaxMin(mid+1,j,max1,min1);

        if (max<max1) max=max1;
        if (min>min1) min=min1;
    }

}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //int a[15]={3,19,23,12,88,32,21,45,7,11};
    int maximum,minimum;

    MaxMin(0,n-1,maximum,minimum);

    cout<<"Maximum value:"<<maximum<<endl;
    cout<<"Minimum value:"<<minimum<<endl;
}


