#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumplatform(int arr[], int dep[], int m, int n) {
    
  sort(arr, arr + m);
  sort(dep, dep + n);
  
  int i =1;
  int j = 0;
  
  int max_platform = 1;
  int min_platform = 1;
  while (i <m  && j <n) {
      
      if(arr[i] > dep[j]) {
          min_platform--;
          j++;
      }
      
      else if( arr[i] <=dep[j]) {
          min_platform++;
          i++;
      }
      
      
      if(max_platform <min_platform) {
          max_platform = min_platform;
      }
  }
  
  return max_platform;
  
  
  
}

// simple trick in case of i and j which is lesser increment that in while loop


int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = sizeof(dep)/sizeof(dep[0]);
    
    cout << minimumplatform(arr,dep,m,n);

    return 0;
}
