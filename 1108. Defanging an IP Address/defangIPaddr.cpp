class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();
        int i = 0;
        for(; i < n; ++i){
            if(address[i] == '.'){
                address.insert(i,"[");
                address.insert(i+2, "]");
                i++;
                n+=2;
            }
        }
        return address;
    }
};
