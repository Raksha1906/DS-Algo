#include<bits/stdc++.h>
using namespace std;

int findMin(int num[], int n) {
    int i, l = 0, h = n-1, mid = 0, ans = INT_MAX;
    while(l <= h){
        mid = (l+h)/2;
        if(num[mid] == num[l] && num[mid] == num[h]){
            ans = min(ans, num[l]);
            l++;
            h--;
        }
        else if(num[mid] >= num[l]){
            ans = min(ans, num[l]);
            l = mid + 1;
        }
        else if(num[mid] <= num[h]){
            ans = min(ans, num[mid]);
            h = mid-1; 
        }
    }
    return ans;
}

int main(){
    int num[100],i,n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter a rotated sorted array: ";
    for(i = 0; i < n; i++)
        cin>>num[i];
    cout<<"The array is: ";
    for(i = 0; i < n; i++)
        cout<<num[i]<<" ";
    cout<<"\nThe minimum element in a rotated sorted array is: "<<findMin(num, n);
    return 0;
}
