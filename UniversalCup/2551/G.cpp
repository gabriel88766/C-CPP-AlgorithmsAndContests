#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    string s;
    int seq = 0;
    string cur = "!@#!";
    int ans = -1;
    while(getline(cin, s)){
        string fs;
        for(int j=s.size()-1;j>=0;j--){
            if(s[j] != ' ') fs += s[j];
            else break;
        }
        if(fs.size() == 0){
            seq = 0;
            cur = "$##@";
            continue;
        }
        reverse(fs.begin(), fs.end());
        string s1 = fs + ", " + fs + " " + fs + "ity " + fs;
        string s2 = "i said " + fs + ", " + fs + " " + fs + "ity " + fs;
        

        if(fs != cur){
            if(s1 == s){
                seq = 1;
                cur = fs;
            }else{
                cur = "$#@$#";
                seq = 0;
            }
        }else{
            if(seq % 2 && s2 == s){
                seq++;
            }else if(seq % 2 == 0 && s1 == s){
                seq++;
            }else if(s1 == s){
                seq = 1;
            }else{
                cur = "@#$@$#";
                seq = 0;
            }
        }
        if(seq >= 2) ans = max(ans, (int) ((seq/2) * (23 + 8 * cur.size())));
    }
    cout << ans << "\n";
}
