#include <stdio.h>

/*
 *O(N^3)
 */
int
MaxSubsequenceSum(const int A[], int N){
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for (i=0; i<N; i++){
        for (j=i; j<N; j++){
            ThisSum = 0;
            for(k=i; k<=j; k++){
                ThisSum += A[k];
            }

            if (ThisSum > MaxSum){
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

int
main(){
    int array[] = {1, 2, 3, 4, -5};
    int MaxSum = MaxSubsequenceSum(array, sizeof(array)/sizeof(int));
    printf("result is %d\n", MaxSum);

    return 0;
}
