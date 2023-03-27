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
        int n, k;
        cin >> n >> k;
        int g = n/2+(k-1);
        //process ans
        string s;
        cin >> s;
        vector<char> ans(n);
        for(int i=0;i<n;i++){
            if(k > 1){
                ans[i] = '(';
                ans[i+1] = ')';
                i++;
                k--;
            }else{
                if(i < g) ans[i] = '(';
                else ans[i] = ')';
            }
        }
        vector<pair<int,int>> mod;
        for(int i=0;i<n;i++){
            if(s[i] == ans[i]) continue;
            else{
                for(int j = i+1;j<n;j++){
                    if(s[i] != s[j]){
                        reverse(s.begin()+i, s.begin()+j+1);
                        mod.push_back({i, j});
                        break;
                    }
                }
            }
        }
        cout << mod.size() << "\n";
        for(auto x : mod) cout << x.first+1 << " " << x.second+1 << "\n";
    }
}
