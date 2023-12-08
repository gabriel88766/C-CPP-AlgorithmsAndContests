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
        vector<int> low, upp;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'b' || s[i] == 'B'){
                if(s[i] == 'b' && low.size()) low.pop_back();
                if(s[i] == 'B' && upp.size()) upp.pop_back();
            }else if(s[i] <= 'z' && s[i] >= 'a'){
                low.push_back(i);
            }else{
                upp.push_back(i);
            }
        }
        int p1 = 0, p2 = 0;
        string ans;
        while(p1 < low.size() && p2 < upp.size()){
            if(low[p1] < upp[p2]){
                ans += s[low[p1]];
                p1++;
            }else{
                ans += s[upp[p2]];
                p2++;
            }
        }
        while(p1 < low.size()) ans += s[low[p1++]];
        while(p2 < upp.size()) ans += s[upp[p2++]];
        cout << ans << "\n";
    }
}
