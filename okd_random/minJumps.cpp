#include <iostream>
#include <limits.h>
using namespace std;
int minJumps(int arr[], int l, int h){
    if(h==l) return 0;
    if(arr[l]==0) return INT_MAX;

    int min = INT_MAX;
    for(int i = l+1; i <=h && i <= arr[l]+ l; i++){
        int jumps = minJumps(arr, i, h);
        if(jumps != INT_MAX && jumps+1 < min)
            min = jumps +1;
    }
    return min;
}

//use std::min 
int min(int x, int y) { return (x<y)? x: y; }

int minJumps_dp(int arr[], int n){
    int *jumps = new int[n];
    int i,j;

    if(n==0 || arr[0] == 0)
        return INT_MAX;
    
    jumps[0] = 0;

}

int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minJumps(arr, 0, n-1);
    return 0;
}
