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
        int f0pos = INF_INT;
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            if(s[i] >= '5'){
                f0pos = i;
                break;
            }
        }
        if(f0pos > 0 && f0pos != INF_INT){
            for(int i=f0pos-1;i>=0;i--){
                s[i] += 1;
                if(s[i] >= '5'){
                    f0pos = i;
                }else break;
            }
        }
        if(f0pos == 0){
            cout << "1";
            for(int i=0;i<s.size();i++) cout << "0";
        }else{
            for(int i=0;i<s.size();i++){
                if(i >= f0pos) cout << "0";
                else cout << s[i];
            }
        }
        cout << "\n";
    }
}
 