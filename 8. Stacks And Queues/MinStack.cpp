/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor

LINK: https://www.interviewbit.com/problems/min-stack/
*/

vector<int> s, m;
// int c;

MinStack::MinStack() {
    s.clear();
    m.clear();
    // c=0;
}

void MinStack::push(int x) {
    if(s.size()==0){
        s.push_back(x);
        m.push_back(x);
    }else{
        s.push_back(x);
         if(x<m.back()){
            m.push_back(x);
         }else{
           m.push_back(m.back());
         }
    }
    // c++;
    // cout << c << endl;
}

void MinStack::pop() {
    if(s.size()!=0){
        s.pop_back();
        m.pop_back();
    }
    
}

int MinStack::top() {
    if(s.size()==0) return -1;
    return s.back();
}

int MinStack::getMin() {
    if(s.size()==0) return -1;
    return m.back();
}



/*stack<int> st, mnst;
 
MinStack::MinStack()
{
    stack<int> temp1, temp2;
    swap(st,temp1);
    swap(mnst,temp2);
}
 
void MinStack::push(int x)
{
    st.push(x);
    if(mnst.empty() || x<=mnst.top())
        mnst.push(x);
}
 
void MinStack::pop()
{
    if(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(x==mnst.top())
            mnst.pop();
    }
}
 
int MinStack::top()
{
    if(!st.empty())
        return st.top();
    return -1;
}
 
int MinStack::getMin()
{
    if(!st.empty())
        return mnst.top();
    return -1;
}*/