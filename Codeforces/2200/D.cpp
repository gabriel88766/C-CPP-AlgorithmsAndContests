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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<int> v1, v2, v3;
        for(int i=1;i<=x;i++) v1.push_back(v[i]);
        for(int i=y+1;i<=n;i++) v1.push_back(v[i]);
        for(int i=x+1;i<=y;i++) v2.push_back(v[i]);
        if(v2.size()){
            auto mn = *min_element(v2.begin(), v2.end());
            int idx;
            for(int j=0;j<v2.size();j++) if(v2[j] == mn) idx = j;
            if(idx != 0){
                for(int i=idx;i<v2.size();i++) v3.push_back(v2[i]);
                for(int i=0;i<idx;i++) v3.push_back(v2[i]);
            }else v3 = v2;
        }
        //v1 and v3;
        vector<int> ans;
        reverse(v1.begin(), v1.end());
        reverse(v3.begin(), v3.end());
        while(v1.size() && v3.size()){
            if(v1.back() < v3.back()){
                ans.push_back(v1.back());
                v1.pop_back();
            }else{
                break;
            }
        }
        while(v3.size()){
            ans.push_back(v3.back());
            v3.pop_back();
        }
        while(v1.size()){
            ans.push_back(v1.back());
            v1.pop_back();
        }
        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
