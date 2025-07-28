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
        bool ch = false;
        for(int i=1;i<s.size();i++){
            int a = s[i] - '0';
            int b = s[i-1] - '0';
            if(a + b >= 10){
                ch = true;
            }
        }
        if(!ch){
            s[1] += (s[0] - '0');
            s = s.substr(1, s.size() - 1);
        }else{
            for(int i=s.size()-2;i>=0;i--){
                int a = s[i] - '0';
                int b = s[i+1] - '0';
                if(a + b >= 10){
                    s[i] = '1';
                    s[i+1] = (a+b) % 10 + '0';
                    break;
                }
            }
        }
        cout << s << "\n";
    }
}
