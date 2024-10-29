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
    //freopen("in", "r", stdin); //test input
    ll n, k;
    string s;
    cin >> n >> k >> s;
    stack<char> mv;
    for(auto c : s){
        if(mv.empty()) mv.push(c);
        else{
            if(c == 'U'){
                if(mv.top() != 'U') mv.pop();
                else mv.push(c);
            }else mv.push(c);
        }
    }
    string acm;
    while(mv.size()){
        acm += mv.top();
        mv.pop();
    }
    reverse(acm.begin(), acm.end());
    // cout << acm << "\n";
    for(auto x : acm){
        if(x == 'U') k >>= 1;
        else if(x == 'L') k <<= 1;
        else k = 2*k + 1;
    }
    cout << k << "\n";
}
