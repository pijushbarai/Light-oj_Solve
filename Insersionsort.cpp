#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    int i = 1, j = 0, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while( j >= 0){
            if(arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
        }
        arr[j+1] = key;
    }

}

int main()
{
    int n;
    cin >> n;
    int arr[n+10];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertionSort(arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    return 0;
}