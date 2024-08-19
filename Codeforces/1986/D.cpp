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
        int n;
        cin >> n >> s;
        if(n == 2) cout << stoi(s) << "\n";
        else{
            int ans = INF_INT;
            for(int i=0;i<s.size()-1;i++){
                vector<int> nums;
                for(int j=0;j<s.size();j++){
                    if(j == i){
                        nums.push_back(stoi(s.substr(j, 2)));
                        j++;
                    }else nums.push_back(stoi(s.substr(j, 1)));
                }
                for(auto x : nums) if(x == 0) ans = 0;
                int cur = 0;
                for(auto x : nums) if(x != 1) cur += x;
                if(cur == 0) cur = 1;
                ans = min(ans, cur);
            }
            cout << ans << "\n";
        }
    }
}
