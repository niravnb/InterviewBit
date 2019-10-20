/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
 Note: Each word is guaranteed not to exceed L in length. 

LINK: https://www.interviewbit.com/problems/justified-text/
*/
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n = A.size();
    vector<string> res;
    string tmp = "";
    
    for(int i = 0; i<n;){
        
        int len = 0, words = 0, spaces = 0, j = i;
        while(i<n && len+words<=B){
            len += A[i].length();
            i++;
            words++;
        }
        if(len+words>B+1){
            i--;
            words--;
            len -= A[i].length();
        }

        spaces = B-len-words+1;
        tmp = "";
        int s;
        if(i==n){
            for(int k = 0; k<words; k++){
                if(k==words-1) tmp+=A[j++];
                else tmp+=A[j++] + " ";
            }
            for(s = 0; s<spaces;s++) tmp += " ";
        }
        else{
            for(int k = 0; k<words; k++){
                if(k==words-1) tmp+=A[j++];
                else tmp+=A[j++] + " ";
                if(words-k>1){
                    for(s = 0; s<ceil((float)spaces/(float)(words-k-1));s++) tmp+=" ";
                    spaces -= s;
                }
                else{
                    for(s = 0; s<spaces;s++) tmp +=" ";
                    spaces -= s;
                }
                
            }
        }
        res.push_back(tmp);
    }
    
    return res;
}


// Other way
vector<string> Solution::fullJustify(vector<string> &s, int B)
{
    int n = s.size();
 
    vector<string> ans;
 
    int k=0,l=0;
 
    for(int i=0;i<n;i+=k)
    {
        for(k=l=0;i+k<n && l+s[i+k].size() <= B-k;k++)
            l += s[i+k].size();
 
        string temp = s[i];
 
        for(int j=0;j<k-1;j++)
        {
            if((i+k)>=n)
                temp += " ";
            else
                temp += string((B-l)/(k-1) + (j<(B-l)%(k-1)), ' ');
            temp += s[i+j+1];
        }
 
        temp += string(B-temp.size(),' ');
        ans.push_back(temp);
    }
    return ans;
}