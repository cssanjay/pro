#include<iostream>
#include<algorithm>

using namespace std;

struct Interval{
    int start;
    int end;
};

bool compareInterval(Interval A, Interval B){
    return (A.start < B.start)? true:false;
}

bool isOverlap(Interval arr[], int n){
    sort(arr, arr+n-1, compareInterval);

    for(int i = 1; i<n; i++){
        if(arr[i-1].end>arr[i].start)
            return true;
    }
    return false;
}