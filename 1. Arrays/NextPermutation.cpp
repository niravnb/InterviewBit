/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

LINK: https://www.interviewbit.com/problems/next-permutation/
*/

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 2){
        // if(A[1]>A[0]){
            swap(A[1],A[0]);
        // }
    }else{
    int min,j;
    for(int i = n-1 ; i>0; i--){
        if(A[i]>A[i-1]){
            min = i;
            for(j = i+1; j < n; j++){
                if(A[j]< A[min] && A[j] > A[i-1]){
                    min = j;
                }
            }
            swap(A[min],A[i-1]);
            sort(A.begin() + i,A.end());
            break;
        }
    }
        
    }
}


/* 
Hint:

It might help to write down the next permutation on paper to see how and when the sequence changes.

You’ll realize the following pattern :

The suffix which gets affected is in a descending order before the change.

A swap with the smaller element happens and then we reverse the affected suffix.

    1 2 3 -> 1 3 2   // Suffix being just the 3. 

    1 2 3 6 5 4  -> 1 2 4 3 5 6 // Suffix being 6 5 4 in this case. 

*/