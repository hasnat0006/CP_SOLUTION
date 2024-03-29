#include<stdio.h>
int arr[1000000000];
int main(){
    int n = 1000000000;
    //scanf("%d", &n);
    for(int i = 0; i < n; i++){
      //  scanf("%d", &arr[i]);
      arr[i] = i;
    }
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
