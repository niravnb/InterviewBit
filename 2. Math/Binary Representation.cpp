string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    string res;
    // res = (char)A%2;
    // A = A/2;
    int l = 0;
    while(A > 0){
        char a = (char)('0' + A%2);
      res += a;
      A = A/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

