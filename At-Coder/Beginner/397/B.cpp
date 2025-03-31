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
    string s;
    cin >> s;
    string ans;
    for(auto &c : s){
        if(ans.size() % 2){
            //next is o
            if(c == 'o') ans += 'o';
            else ans += 'o', ans += 'i';
        }else{
            if(c == 'i') ans += 'i';
            else ans += 'i', ans += 'o';
        }
    }
    if(ans.size() % 2) ans += 'o';
    cout << ans.size() - s.size() << "\n";
}
