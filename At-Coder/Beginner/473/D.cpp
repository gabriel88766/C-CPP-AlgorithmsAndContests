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
    // freopen("out", "w", stdout); //test input
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ans;
    for(int i=n; i>=1;i--){
        if(i == n){
            for(int j=k/i;j>=0;j--){
                vector<int> cv;
                cv.push_back(j);
                ans.push_back(cv);
                if(i == 1) break;
            }
        }else{
            vector<vector<int>> nvs;
            for(auto vx : ans){
                int s = 0;
                int ax = n;
                for(auto x : vx) s += x * ax--;
                for(int j=(k-s)/i;j>=0;j--){
                    vector<int> cv = vx;
                    cv.push_back(j);
                    nvs.push_back(cv); 
                    if(i == 1) break;
                }
            }
            ans = nvs;
        }
    }
    for(auto &v : ans){
        reverse(v.begin(), v.end());
    }
    sort(ans.begin(), ans.end());
    for(auto &v : ans){
        for(auto x : v) cout << x << " ";
        cout << "\n";
    }
}
