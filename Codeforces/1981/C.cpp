#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string to_bin(int num){
    string ans = "";
    while(num){
        if(num & 1) ans += '1';
        else ans += '0';
        num >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int b2int(string num){
    int ans = 0;
    for(auto &c : num){
        ans *= 2;
        if(c == '1') ans += 1;
    }
    return ans;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans(n);
        vector<int> idx;
        for(int i=0;i<n;i++){
            cin >> ans[i];
            if(ans[i] != -1){
                idx.push_back(i);
            }
        }
        if(!idx.size()){
            for(int i=0;i<n;i++){
                if(i % 2) cout << "1 ";
                else cout << "2 ";
            }
            cout << "\n";
        }else{
            bool ok = true;
            for(int i=idx[0]-1; i >= 0; i--){
                int df = idx[0] - i;
                if(df % 2) ans[i] = ans[idx[0]]*2;
                else ans[i] = ans[idx[0]];
            }
            for(int i = idx.back()+1;i<n;i++){
                int df = i - idx.back();
                if(df % 2) ans[i] = ans[idx.back()] * 2;
                else ans[i] = ans[idx.back()];
            }
            for(int i=1;i<idx.size();i++){
                int i1 = idx[i-1], i2 = idx[i];
                string s1 = to_bin(ans[i1]), s2 = to_bin(ans[i2]);
                int cp = 0;
                for(int j=1;j<min(s1.size(), s2.size());j++){
                    if(s1[j] == s2[j]) cp = j;
                    else break;
                }
                int dif1 = i2 - i1;
                int dif2 = s1.size() + s2.size() - 2*(cp + 1);
                if(dif1 >= dif2 && dif1 % 2 == dif2 % 2){
                    int cs = s1.size();
                    bool f1 = false, f2 = false;
                    for(int j=i1+1;j<=i2-1;j++){
                        if(!f1){
                            if(cs > cp+1){
                                s1.pop_back();
                                cs--;
                                ans[j] = b2int(s1);
                                continue;
                            }else f1 = true;
                        }
                        if(!f2){
                            if(s1.size() < s2.size()){
                                s1 += s2[s1.size()];
                                ans[j] = b2int(s1);
                                continue;
                            }else f2 = true;
                        }
                        if(s1 == s2){
                            s1 += '0';
                            ans[j] = b2int(s1);
                        }else{
                            s1.pop_back();
                            ans[j] = b2int(s1);
                        }

                        
                    }
                }else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                for(auto x : ans) cout << x << " ";
                cout << "\n";
            }else cout << "-1\n";
        }
    }
}   
