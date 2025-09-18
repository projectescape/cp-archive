class Solution {
public:

    bool isValidSubstring(unordered_map<char, int> &tCount,unordered_map<char, int> &sCount){
        for(auto i:tCount){
            if(i.second>sCount[i.first]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> tCount,sCount;

        for(auto c:t){
            tCount[c]++;
        }
         
        string ans = s;
        if(s.size()<1){
            return "";
        }
        sCount[s[0]]++;

        if(isValidSubstring(tCount, sCount)){
            return s.substr(0,1);
        }

        for(int left=0, right=1;right<s.size();right++){
            char rightChar = s[right];
            sCount[rightChar]++;
            if(isValidSubstring(tCount, sCount)){
                if(right-left+1<ans.size()){
                    ans = s.substr(left, right-left+1);
                }
                while(1){
                    char leftChar = s[left];
                    sCount[leftChar]--;
                    if(isValidSubstring(tCount, sCount)){
                        left++;
                        if(right-left+1<ans.size()){
                            ans = s.substr(left, right-left+1);
                        }
                    }else{
                        sCount[leftChar]++;
                        break;
                    }
                }
            }
        }

        if(ans == s && !isValidSubstring(tCount, sCount)){
            return "";
        }
        return ans;

    }
};
