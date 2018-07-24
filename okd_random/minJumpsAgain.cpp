#include<iostream>
#include<limits.h>
using namespace std;

int minJumps(int arr[], int l, int h){
    if(h == l)
        return 0;
    if(arr[l]==0) return INT_MAX;
    int min = INT_MAX;

    for(int i = l+1; i<=h & i<=arr[l]+l; i++){
        int jumps = minJumps(arr, i, h);
        if(jumps!= INT_MAX && jumps+1<min)
            min = jumps+1;
    }
    return min;
}

//Dynamic Programming

int minJumps(int arr[], int n){
    int *jumps = new int[n];
    int i,j;

    if(n==0 || arr[0]==0)
        return INT_MAX;
    jumps[0] = 0;

    for(i =1; i<n;i++){
        jumps[i]=INT_MAX;
        for(j=0; j<i;j++){
            if(i <= j + arr[j] && jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i], jumps[j]+1);
                break;
            }
        }
    }
    return jumps[n-1];
}