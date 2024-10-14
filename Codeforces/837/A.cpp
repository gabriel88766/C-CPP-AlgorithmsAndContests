#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> v;
//cout << fixed << setprecision(6)
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string str;
    std::getline (std::cin,str);
    std::getline (std::cin,str);
    string cur = "";
    for(auto c : str){
        if(c == ' '){
            v.push_back(cur);
            cur = "";
        }else cur += c;
    }
    v.push_back(cur);
    int ans = 0;
    for(auto str : v){
        int cur = 0;
        for(auto c : str){
            if(c <= 'Z' && c >= 'A') cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}
