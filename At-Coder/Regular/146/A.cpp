#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> v;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<int>());
    int a = v[0], b = v[1], c = v[2];
    vector<string> ans;
    vector<int> p = {0, 1, 2};
    do{
        string cur = "";
        for(auto x : p){
            cur += to_string(v[x]);
        }
        ans.push_back(cur);
    }while(next_permutation(p.begin(), p.end()));
    sort(ans.begin(), ans.end(), greater<string>());
    cout << ans[0] << "\n";
}
