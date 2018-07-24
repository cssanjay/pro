#include<iostream>
#include<unordered_map>

using namespace std;

bool areEqual(int arr1[],int arr2[], int n, int m){
    if(n!=m)
        return false;
    
    unordered_map<int, int> mp;
    for(int i =0; i<n; i++)
        mp[arr1[i]]++;

    for(int i = 0; i<n;i++){
        if(mp.find(arr2[i]) == mp.end())
            return false;
        //if arr[2] appears more times than in arr1[]
        if(mp[arr2[i]]==0)
            return false;
        mp[arr2[i]]--;
    }
    return true;
}