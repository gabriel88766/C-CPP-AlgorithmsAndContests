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
    const int k = 26;
    string s;
    cin >> s;
    if(s.size() < k){
        vector<bool> us(k, false);
        for(auto c : s) us[c - 'a'] = true;
        for(int j=0;j<k;j++){
            if(!us[j]){
                s += j + 'a';
                break;
            }
        }
        cout << s << "\n";
    }else{
        int ij = -1;
        for(int j=k-1;j>0;j--){
            if(s[j] > s[j-1]){
                ij = j-1;
                break;
            }
        }   
        if(ij == -1) cout << ij << "\n";
        else{
            char x = 'z' + 1;
            for(int j=ij+1;j<k;j++){
                if(s[j] > s[ij]) x = min(x, s[j]);
            }
            string ans = s.substr(0, ij) + x;
            cout << ans << "\n";
        }
    }
}   
