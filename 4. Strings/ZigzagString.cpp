/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

LINK: https://www.interviewbit.com/problems/zigzag-string/
*/
string Solution::convert(string A, int B) {
    if(B==1) return A;
    
    string res = "";
    vector<string> arr(B);
    int n = A.length();
    int row = 0, flag=0;
    
    for(int i =0; i<n; i++){
        arr[row]+=A[i];
        
        if(flag==0) row++;
        else row--;
        
        if(row>=B){
            row = B-2;
            flag=1;
        }
        if(row<0){
            row = 1;
            flag = 0;
        }
    }
    
    for(int i = 0; i<B; i++) res += arr[i];
    
    return res;
}
