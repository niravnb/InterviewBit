vector<int> Solution::allFactors(int A) {
    
    vector<int> res, res1;
        if(A==1) {
            res.push_back(1);
            return res;
        }

    for(int i = 1; i*i<=A; i++){
        if(A%i == 0){
            res.push_back(i);
        }
    }
    res1 = res;
    for(int i = res.size() - 1; i>=0; i--){
        if(A/res[i] != res[i])
        res1.push_back(A/res[i]);
    }
    return res1;
}
