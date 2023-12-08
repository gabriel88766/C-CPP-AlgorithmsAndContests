#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void ch(string &s, int v){
    for(int i=s.size()-1;i>=1;i--){
        if((s[i]-'0')%3 == v){
            if(i == s.size() - 1) s = s.substr(0, i);
            else s = s.substr(0, i) + s.substr(i+1, s.size() - 1);
            break;
        }
    }
}
void solve(string &s){
    int sd = 0;
    for(int i=0;i<s.size();i++) sd += (s[i] - '0');
    sd %= 3;
    if(sd){
        int c1 = 0, c2 = 0;
        for(int i=s.size()-1;i>=1;i--){
            if((s[i] - '0') % 3 == 1) c1++;
            else if((s[i] - '0') % 3 == 2) c2++;
        }
        if(sd == 1 && c1 >= 1){
            ch(s, 1);
        }else if(sd == 2 && c2 >= 1){
            ch(s, 2);
        }else if((s[0]-'0') % 3 == sd && s.size() != 1 && s[1] != '0'){
            s = s.substr(1, s.size() - 1);
        }else if(sd == 1 && c2 >= 2){
            ch(s, 2);
            ch(s, 2);
        }else if(sd == 2 && c1 >= 2){
            ch(s, 1);
            ch(s, 1);
        }else{
            int fnz = -1;
            for(int i=1;i<s.size();i++){
                if(s[i] != '0'){
                    fnz = i;
                    break;
                }
            }
            if(fnz != -1){
                s = s.substr(fnz, s.size() - fnz);
                solve(s);
            }else if(s.size() != 1) s = "0";
            else s = "-1";
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    bool hz = false;
    for(int i=0;i<s.size();i++) if(s[i] == '0') hz = true;
    solve(s);
    if(s == "-1" && hz) cout << "0";
    else cout << s << "\n";
}
