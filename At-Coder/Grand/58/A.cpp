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
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];
    vector<int> ans;
    for(int i=1;i<(2*n-1);i+=2){
        if(v[i] > v[i-1] && v[i] > v[i+1]) continue;
        else if(v[i+1] > v[i] && v[i+1] > v[i-1]){
            swap(v[i], v[i+1]);
            ans.push_back(i+1);
        }else{
            swap(v[i-1], v[i]);
            ans.push_back(i);
        }
    }
    if(v[2*n-1] < v[2*n-2]) ans.push_back(2*n-1);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
}
