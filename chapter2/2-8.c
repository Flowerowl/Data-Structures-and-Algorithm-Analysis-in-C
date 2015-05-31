#include <stdio.h>

/*
 *O(N)
 */
int
MaxSubsequenceSum(const int A[], int N){
    int ThisSum, MaxSum, i;

    ThisSum = MaxSum = 0;
    for (i=0; i<N; i++){
        ThisSum += A[i];

        if (ThisSum > MaxSum){
            MaxSum = ThisSum;
        } else if(ThisSum < 0){
            ThisSum = 0;
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
