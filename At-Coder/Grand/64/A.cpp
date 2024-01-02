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
    vector<int> ans;
    for(int i=1;i<=n-2;i++) ans.push_back(i);
    ans.push_back(n);
    ans.push_back(n-1);
    for(int i=n;i>=3;i-=2){
        ans.push_back(i);
        for(int j=0;j<i-2;j++){
            ans.push_back(i-1);
            ans.push_back(i);
        }
    }
    if(!(n % 2)) ans.push_back(2);
    for(auto x : ans) cout << x << " ";
    cout << "\n";
}
