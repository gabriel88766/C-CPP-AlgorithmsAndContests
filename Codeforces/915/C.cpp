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
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() == s2.size()){
        sort(s1.begin(), s1.end());
        vector<bool> used(s1.size(), false);
        string ans;
        for(int i=0;i<s1.size();i++){
            //choose next
            int newl = -1;
            for(int j=0;j<s1.size();j++){
                if(used[j]) continue;
                string cur = ans + s1[j];
                for(int k=0;k<s1.size();k++){
                    if(k == j || used[k]) continue;
                    cur += s1[k];
                }
                if(cur <= s2) newl = j;
                else break;
            }
            assert(newl != -1);
            ans += s1[newl];
            used[newl] = true;
        }
        cout << ans << "\n";
    }else{
        sort(s1.begin(), s1.end(), greater<char>());
        cout << s1 << "\n";
    }
}
