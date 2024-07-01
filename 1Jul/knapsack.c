#include <stdio.h>
#include <string.h>
int findMax(int n1, int n2){
   if(n1>n2) {
      return n1;
   } else {
      return n2;
   }
}
int knapsack(int W, int wt[], int val[], int n){
   int K[n+1][W+1];
   for(int i = 0; i<=n; i++) {
      for(int w = 0; w<=W; w++) {
         if(i == 0 || w == 0) {
            K[i][w] = 0;
         } else if(wt[i-1] <= w) {
            K[i][w] = findMax(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
         } else {
            K[i][w] = K[i-1][w];
         }
      }
   }
   return K[n][W];
}
int main(){

   int W;
   int len;
   scanf("%d %d", &len, &W);
   int val[len];
   int wt[len];

    for(int i=0;i<len;i++){
   scanf("%d %d",&val[i],&wt[len]);
    }
   printf("Maximum Profit: %d", knapsack(W, wt, val, len));
}
