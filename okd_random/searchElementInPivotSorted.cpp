#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key){
    if(end<start) return -1; 
    int mid=(start+end)/2;
    if(key==arr[mid]) retutn mid;

    if(key<arr[mid])
        return binarySearch(arr, start, mid-1, key);
    else return binary_search(arr, mid+1, end, key);
}

int findPivot(int arr[], int start, int end){
    if(end<start) return -1;
    if(end==start)return start;

    int mid = (start+end)/2;
    if(mid>start && arr[mid] < arr[mid-1]) return mid-1;
    if(mid<end && arr[mid] > arr[mid+1]) return mid;

    if(arr[start]>= arr[mid])
        return findPivot(arr, start, mid-1);
    return findPivot(arr, mid+1, end);
}

int pivotedBinarySearch(int arr[], int n, int key){
    int pivot = findPivot(arr, 0, n-1);
    if(pivot == -1)
        return binarySearch(arr,0,n-1,key);
    if(arr[pivot]==key)
        return pivot;
    if(arr[0]<=key)
        return binarySearch(arr, 0, pivot-1, key);
    return biniarySearch(arr, pivot+1, n-1, key);
}


int Search(int arr[], int l, int h, int key){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(arr[mid] == key) return mid;
    if(arr[l]<=arr[mid]){
        return search(arr, l,mid-1, key);
    return search(arr, mid+1, h, key);
    }
    if(key >= arr[mid] && key <= arr[h])
        return search(arr, mid+1, h, key);
    return search(arr, l, mid-1, key);
}