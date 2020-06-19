vector<int> Solution::allFactors(int A) {
    vector<int>ans;
    stack<int> s;
    int i;
    for(i=1;i*i<A;i++){
        if(A%i==0){
            ans.push_back(i);
            s.push(A/i);
        }
    }
    if(i*i==A) ans.push_back(i);
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
