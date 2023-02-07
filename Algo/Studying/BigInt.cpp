//to be improved, just a draft. (if needed)
// tip: just use python! 
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct BigInt{ //easily expanded;
    vector<ull> v;
    int maxlen;
    BigInt(){}
    BigInt(string s){ //O(K^2) complexity, K number of digits
        //string to INT128_t
        int sz = s.size();
        v.reserve(sz/9+1);
        maxlen = sz/9+1;
        ull pot = 0, num = 1, p=0;
        while(sz != 0){    
            if((s[sz-1]-'0') & 1){
                v[p] |= num;
                s[sz-1]--;
            }
            //now divide it by 2
            int carry = 0;
            string ans;
            cout << ans;
            for(int i=0;i<sz;i++){
                int div = carry * 10 + s[i]-'0';
                if(div & 1) carry = 1;
                else carry = 0;
                int res = div/2;
                if(res == 0 && !i) continue;
                ans += res + '0'; 
            }
            s = ans;
            sz = s.size();
            if(pot == 31){pot=0, num = 1, p++;}
            else{pot++, num <<=1;}
        }
    }
    BigInt operator +(BigInt &v){

    }
    BigInt operator %(BigInt &v){

    } 
};


int main(){
    string s;
    s = "18446744073709551620";
    BigInt t(s);
    cout << t.v[2] << " " << t.v[1] << " " << t.v[0]; // 1 0 4, because s is 1 * 2^64 + 0 * 2^32 + 4
}
