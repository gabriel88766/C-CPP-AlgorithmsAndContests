#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> combs[11];
void genall(){
    for(int i=0;i<=9;i++){
        vector<int> x = {i};
        combs[1].push_back(x);
    }
    for(int i=2;i<=10;i++){
        for(auto x : combs[i-1]){
            for(int j=x.back()+1;j<=9;j++){
                auto y = x;
                y.push_back(j);
                combs[i].push_back(y);
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    genall();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s = to_string(n);
        ll ans = 1'111'111'111;
        for(auto x : combs[k]){
            int ind = -1;
            for(int j=0;j<s.size();j++){
                if(x.back() < (s[j]-'0')){
                    ind = j;
                    break;
                }
            }
            if(ind == 0) continue;
            
            if(ind == -1){
                ll cnum = 0;
                bool okg = false;
                for(int j=0;j<s.size();j++){
                    if(okg){
                        cnum *= 10;
                        cnum += x[0];
                    }else{
                        for(int xx=0;xx<x.size();xx++){
                            if(x[xx] > (s[j]-'0')){
                                okg = true;
                            }
                            if(x[xx] >= (s[j] - '0')){
                                cnum *= 10;
                                cnum += x[xx];
                                break;
                            }
                        }
                    }
                }
                ans = min(ans, cnum);
                continue;
            }


            int ind2 = -1;
            for(int j=0;j<ind;j++){
                if(x.back() > (s[j] - '0')) ind2 = j;
                bool ok = false;
                for(int xx=0;xx<x.size();xx++){
                    if(x[xx] == (s[j]-'0')){
                        ok = true;
                    }
                }
                if(!ok) break;
            }
            if(ind2 == -1) continue;
            ll cnum = 0;
            for(int j=0;j<s.size();j++){
                if(j > ind2){
                    cnum *= 10;
                    cnum += x[0];
                }else if(j < ind2){
                    cnum *= 10;
                    cnum += (s[j] - '0');
                }else{
                    for(int xx=0;;xx++){
                        if(x[xx] > (s[j]-'0')){
                            cnum *= 10;
                            cnum += x[xx];
                            break;
                        }
                    }
                }
            }
            ans = min(ans, cnum);
        }
        
        cout << ans << "\n";
    }
}
