#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int getState(string &str){
    int st = 0;
    int p3 = 1;
    for(int i=0;i<10;i++){
        if(str[i] == '1') st += p3;
        else if(str[i] == '2') st += 2*p3;
        p3 *= 3;
    }
    return st;
}

string fromState(int state){
    string str;
    while(state){
        if(state % 3 == 0) str += '0';
        else if(state % 3 == 1) str += '1';
        else str += '2';
        state /= 3;
    }
    while(str.size() != 10) str += '0';
    return str;
}
ll dp[59049][11];
ll p10[20]; //mod 11
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    p10[0] = 1;
    for(int i=1;i<20;i++) p10[i] = (p10[i-1] * 10) % 11;
    dp[0][0] = 1;
    for(int i=1;i<59049;i++){
        string cst = fromState(i);
        int bitcount = 0;
        for(auto &c : cst) bitcount += c - '0';
        //from state :
        bitcount--;
        for(int j=0;j<10;j++){
            //avoid leading zeroes
            if(j == 0 && (i == 59048 || i == 59047)) continue;//very easy to see logic /s
            if(cst[j] == '0') continue;
            cst[j]--;
            for(int r=0;r<11;r++){
                dp[i][(r + j*p10[bitcount]) % 11] += dp[getState(cst)][r];
            }
            cst[j]++;
        }
    }
    ll total = 0;
    for(int j=0;j<=10;j++) total += dp[59048][j];
    cout << "total : " << total << "\nanswer : ";
    cout << dp[59048][0] << "\n";
}
