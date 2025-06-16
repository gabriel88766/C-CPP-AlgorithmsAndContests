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
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = 0;
    for(int i=0;i<n;i++) cin >> v[i];
    vector<vector<int>> ag(1);
    ag[0] = v;
    //only 1 group initally
    for(int i=29;i>=0;i--){
        //iterate over all groups.
        //check if all groups are divided in two. 
        //If so, push the new groups and set bit to answer.
        //Else, push only the groups which could not be divided and don't set the bit;
        vector<vector<int>> ng;
        for(auto &v : ag){
            int c1 = 0, c2 = 0;
            for(auto &x : v){
                if(x & (1 << i)) c1++;
                else c2++;
            }
            if(c1 == 0 || c2 == 0){
                ng.push_back(v);
            }
        }
        if(ng.size() == 0){
            ans |= (1 << i);
            for(auto &v : ag){
                vector<int> v1, v2;
                for(auto &x : v){
                    if(x & (1 << i)) v1.push_back(x);
                    else v2.push_back(x);
                }
                ng.push_back(v1);
                ng.push_back(v2);
            }
        }
        ag = ng;
    }
    cout << ans << "\n";
}
