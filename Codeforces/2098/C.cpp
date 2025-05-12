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
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        vector<int> v;
        for(auto &[a, b] : mp){
            if(!mp.count(a-1)) v.push_back(0);
            v.push_back(b);
        }
        bool ok = false, sq2 = false;
        for(int i=0;i<v.size();i++){
            if(v[i] >= 4) ok = true;
            else if(v[i] >= 2 && sq2) ok = true;
            else if(v[i] >= 2) sq2 = true;
            else if(v[i] == 0) sq2 = false; 
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
}
