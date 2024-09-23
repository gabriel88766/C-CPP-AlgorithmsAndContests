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
    vector<int> p3 = {1};
    while(p3.back() * 3 <= 100000) p3.push_back(p3.back()*3);
    vector<int> ans;
    int m;
    cin >> m;
    for(int i=p3.size()-1;i>=0;i--){
        while(m >= p3[i]){
            ans.push_back(i);
            m -= p3[i];

        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
