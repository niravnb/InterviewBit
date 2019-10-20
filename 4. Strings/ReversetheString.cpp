/*
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.

LINK: https://www.interviewbit.com/problems/reverse-the-string/
*/

string myreverse(string &A, int s, int e){
    char temp;
    int os = s, oe = e;
    while(s<=e){
        temp = A[s];
        A[s++] = A[e];
        A[e--] = temp;
    }
    string t;
    for(int i = os; i<=oe;i++) t.push_back(A[i]);
    return t;
}

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int s = 0, e, n = A.size(), i = 0;
    string res, t;
    
    for(; i<n;){
        s = i;
        while(A[i]!= '\0' && A[i]!=' ') i++;
        e = i-1;
        t = myreverse(A, s, e);
        res.append(t);
        if(A[i]) res.push_back(' ');
        i++;
        
        while(A[i]==' ' && A[i]!='\0' && i<n) i++;
        
    }
    
    t = myreverse(res, 0, res.size()-1);
    A = t;
    return;
}


/*
void Solution::reverseWords(string &s)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    vector<string> words;
    string word = "";
    int n = s.length();
 
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ' && word.length()>0)
        {
            words.push_back(word);
            word = "";
        }
        else
            word.push_back(s[i]);
    }
    if(word.length()>0)
        words.push_back(word);
 
    reverse(words.begin(), words.end());
    s="";
 
    for(int i=0;i<words.size();i++)
    {
        if(i!=0)
            s.push_back(' ');
        s += words[i];
    }
}*/