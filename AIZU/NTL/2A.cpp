// tip: just use python! 
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct BigInt{ 
    const ull MAX_INT = 1000000000;
    vector<ull> v;
    int maxlen;
    int len;
    BigInt(int ml){
        maxlen = ml;
        v.assign(ml, 0);
        len = 0;
    }
    BigInt(string s, int ml){ //#digits/9 < maxlen
        //9 digits;
        int n = s.size();
        maxlen = ml;
        v.assign(ml, 0);
        len = 0;
        for(int i=(n-1);i>=0;i -= 9){
            for(int j = max(i-8, 0); j <= i; j++){
                v[len] *= 10;
                v[len] += s[j] - '0';
            }
            len++;
        }
    }
    BigInt operator +(BigInt num){
        BigInt ans(20000);
        ull carry = 0;
        for(int i=0;i<max(num.len, len);i++){
            ull sum = num.v[i] + v[i] + carry;
            carry = sum/MAX_INT;
            sum %= MAX_INT;
            ans.v[i] = sum;
        }
        ans.len = max(num.len, len);
        if(carry) ans.v[ans.len++] = carry;
        return ans;
    }
    //not ok yet, a > b
    BigInt operator -(BigInt num){
        BigInt ans(20000);
        ull borrow = 0;
        for(int i=0;i<max(num.len, len);i++){
            ull sum = MAX_INT - num.v[i] + v[i] - borrow;
            if(sum >= MAX_INT) borrow = 0;
            else borrow = 1;
            sum %= MAX_INT;
            ans.v[i] = sum;
            if(sum != 0) ans.len = i+1;
        }
        return ans;
    }
    bool operator <(BigInt num){
        if(len < num.len) return true;
        else if(len > num.len) return false;
        else{
            for(int i=(len-1);i>=1;i--){
                if(v[i] != num.v[i]) return v[i] < num.v[i];
            }
            return v[0] < num.v[0];
        }
    }
    void print(){
        if(len == 0) cout << "0";
        for(int i=(len-1);i>=0;i--){
            if(i != (len - 1)) printf("%.09d", v[i]);
            else printf("%d", v[i]);
        }
    }
};


int main(){
    string s,t ;
    cin >> s >> t;
    bool ns = false, nt = false;
    if(s[0] == '-'){
        ns = true;
        s = s.substr(1, s.size()-1);
    }
    if(t[0] == '-'){
        nt = true;
        t = t.substr(1, t.size()-1);
    }
    BigInt b1(s,20000), b2(t,20000);
    if(nt && !ns){
        if(b1 < b2) {cout << "-";(b2-b1).print();}
        else (b1-b2).print();
    }else if(!nt && ns){
        if(b2 < b1) {cout << "-"; (b1-b2).print();}
        else (b2-b1).print();
    }else if(!nt && !ns){
        (b1+b2).print();
    }else{
        cout << "-";
        (b1+b2).print();
    }
    cout << "\n";
}
