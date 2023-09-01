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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool ok = true;
        int len = 0;
        stack<pair<int,int>> stp;
        for(int i=0;i<s.size();i++){
            if(s[i] == '+'){
                len++;
            }else if(s[i] == '-'){
                len--;
            }else if(s[i] == '1'){
                if(stp.size() && stp.top().first == 0){
                    ok = false;
                    break;
                } 
                stp.push({1, len});
            }else{
                if(len <= 1){
                    ok = false;
                    break;
                }
                if(stp.size() && stp.top().first == 1 && stp.top().second == len){
                    ok = false;
                    break;
                }
                stp.push({0, len});
            }
            while(stp.size() && stp.top().first == 0 && stp.top().second > len) stp.pop();
            if(stp.size() && stp.top().second > len ){
                if(stp.top().first == 1){
                    stp.top().second--;
                }
            }
            if(len < 0){
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    
}   
