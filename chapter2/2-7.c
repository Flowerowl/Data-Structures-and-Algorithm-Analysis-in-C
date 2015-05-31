#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/*
 *O(NlogN)
 */
int
MaxSubsequenceSum(const int A[], int Left, int Right){
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if (Left == Right){
        if (A[Left] > 0){
            return A[Left];
        } else {
            return 0;
        }
    }

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubsequenceSum(A, Left, Center);
    MaxRightSum = MaxSubsequenceSum(A, Center+1, Right);

    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (i=Center; i>=Left; i--){
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum){
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (i=Center+1; i<=Right; i++){
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightBorderSum){
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return MAX(MAX(MaxLeftSum, MaxRightSum), MaxLeftBorderSum + MaxRightBorderSum);
}

int
main(){
    int array[] = {1, 2, 3, 4, -5};
    int MaxSum = MaxSubsequenceSum(array, 0, 4);
    printf("result is %d\n", MaxSum);

    return 0;
}
