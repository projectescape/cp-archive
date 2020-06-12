// TLE
// bool isGreater(string &a,string &b){
//     for(int i=0;i<a.size();i++){
//         if(a[i]>b[i]) return true;
//         if(a[i]==b[i]) continue;
//         return false;
//     }
//     return false;
// }

// void permute(vector<string> &v,int pos,string &ans){
//     if(pos==v.size()) {
//         string temp="";
//         for(auto i:v) temp+=i;
//         if(ans==""){
//             ans=temp;
//             return;
//         }
//         ans=isGreater(temp,ans)?temp:ans;
//         return;
//     }
//     for(int i=pos;i<v.size();i++){
//         swap(v[i],v[pos]);
//         permute(v,pos+1,ans);
//         swap(v[i],v[pos]);
//     }

// }

// string Solution::largestNumber(const vector<int> &A) {
//     string ans="";
//     vector<string> v(A.size());
//     for(int i=0;i<A.size();i++){
//         v[i]=to_string(A[i]);
//     }
//     permute(v,0,ans);
//     return ans;
// }

bool compare(int &a, int &b) {
    return (to_string(a) + to_string(b)) > (to_string(b) + to_string(a));
}

string Solution::largestNumber(const vector<int> &A) {
    int max = *max_element(A.begin(), A.end());
    int min = *min_element(A.begin(), A.end());
    if (max == min) {
        if (max == 0) {
            return "0";
        }
    }
    vector<int> B;
    for (int i = 0; i < A.size(); i++) {
        B.push_back(A[i]);
    }
    sort(B.begin(), B.end(), compare);
    string ans = "";

    for (int i = 0; i < A.size(); i++) {
        ans += to_string(B[i]);
    }
    return ans;
}