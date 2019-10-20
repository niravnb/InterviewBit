/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

LINK: https://www.interviewbit.com/problems/fraction/
*/
string Solution::fractionToDecimal(int A, int B) {
    
    long int n = A, d = B, r , p;
    string res;
    
    if(n==0) return "0";
    
    if(n<0^d<0) res.append("-");
    
    n = abs(n);
    d = abs(d);
    
    p = n/d;
    res.append(to_string(p));
    
    r = n%d;
    if(r==0) return res;
    
    unordered_map<long int,long int> m;

    res += '.';
    
    while(r!=0 && m.find(r)==m.end()){
        m[r] = res.length();
        r = r*10;
        
        res.append(to_string(r/d));
        
        r = r%d;
        
    }
    
    if(r==0) return res;
    res.insert(m[r],"(");
    res.append(")");
    
    return res;
        
}
