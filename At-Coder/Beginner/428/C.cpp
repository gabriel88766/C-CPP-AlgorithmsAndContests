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
    int q;
    cin >> q;
    map<int, int> mp;
    mp[0]++;
    vector<int> vx = {0};
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            char c;
            cin >> c;
            if(c == '(') vx.push_back(vx.back() + 1);
            else vx.push_back(vx.back() - 1);
            mp[vx.back()]++;
        }else{
            mp[vx.back()]--;
            if(mp[vx.back()] == 0) mp.erase(vx.back());
            vx.pop_back();
        }
        if(vx.back() == 0 && mp.begin()->first == 0) cout << "Yes\n";
        else cout << "No\n";
    }
}
