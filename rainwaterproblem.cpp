/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int rainwaterproblem(int *arr, int size){
    int count = 0;
    int leftmax[size], rightmax[size], water_stored[size];
    
    // Fill left array
    leftmax[0] = arr[0];
    for (int i = 1; i < size; i++)
        leftmax[i] = max(leftmax[i - 1], arr[i]);
  
    // Fill right array
    rightmax[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
        rightmax[i] = max(rightmax[i + 1], arr[i]);
    
    
    for(int i = 0; i<size ;i++){
        water_stored[i] = min(rightmax[i], leftmax[i]) -arr[i];
        count += water_stored[i];
        
    }
    
    for(int i = 0 ;i <size; i++){
      std::cout << leftmax[i] << " ";
    }
    
    cout <<"\n";
    for(int i = 0 ;i <size; i++){
      std::cout << rightmax[i] << " ";
    }
    
    return count;
}

int main()
{
    int a[] = {3,0,0,2,0,4};
    int size = sizeof(a)/sizeof(a[0]);
    
    cout << rainwaterproblem(a,size);

    return 0;
}
