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
        int a = 0, b = 0, c = 0;
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i] >= '0' && s[i] <= '9') a++;
            else if(s[i] >= 'a' && s[i] <= 'z') b++;
            else c++;
        }
        if(a && b && c) cout << s << "\n";
        else{
            if(a && b){
                for(int i=0;i<s.size();i++){
                    if(s[i] >= '0' && s[i] <= '9' && a > 1){
                        s[i] = 'Z';
                        break;
                    }
                    if(s[i] >= 'a' && s[i] <= 'z' && b > 1){
                        s[i] = 'Z';
                        break;
                    }
                }
            }else if(a && c){
                for(int i=0;i<s.size();i++){
                    if(s[i] >= '0' && s[i] <= '9' && a > 1){
                        s[i] = 'z';
                        break;
                    }
                    if(s[i] >= 'A' && s[i] <= 'Z' && c > 1){
                        s[i] = 'z';
                        break;
                    }
                }
            }else if(b && c){
                for(int i=0;i<s.size();i++){
                    if(s[i] >= 'a' && s[i] <= 'z' && b > 1){
                        s[i] = '1';
                        break;
                    }
                    if(s[i] >= 'A' && s[i] <= 'Z' && c > 1){
                        s[i] = '1';
                        break;
                    }
                }
            }else{
                if(a){
                    s[0] = 'A';
                    s[1] = 'b';
                }else if(b){
                    s[0] = '1';
                    s[1] = 'Z';
                }else{
                    s[0] = '1';
                    s[1] = 'c';
                }
            }
            cout << s << "\n";
        }
    }
}
