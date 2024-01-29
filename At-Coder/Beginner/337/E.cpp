#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string to_bit_str(int num, int zr){
    string ans;
    while(num){
        if(num & 1) ans += '1';
        else ans += '0';
        num >>= 1;
    }
    while(ans.size() != zr) ans += '0';
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int ans = -1;
    for(int i=1;;i++){
        if((1 << i) >= n){
            ans = i;
            break;
        }
    }
    map<string, int> mp;
    vector<vector<int>> v(ans);
    for(int i=1;i<=n;i++){
        string cur = to_bit_str(i-1, ans);
        for(int j=0;j<ans;j++){
            if(cur[j] == '1') v[j].push_back(i);
        }
        mp[cur] = i;
    }
    cout << ans << "\n";
    for(int i=0;i<ans;i++){
        cout << v[i].size() << " ";
        for(auto x : v[i]){
            cout << x << " ";
        } 
        cout << "\n";
    }
    cout.flush();
    string tans;
    cin >> tans;
    cout << mp[tans] << "\n";
    cout.flush();

}
