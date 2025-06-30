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
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int cur = 0, mn = 0;
        for(auto c : s){
            if(c == ')') cur--;
            else cur++;
            mn = min(mn, cur);
        }
        vp.push_back({cur, mn});
    }
    int sm = 0;
    for(auto [a, b] : vp){
        sm += a;
    }
    if(sm == 0){
        int cs = 0;
        vector<pair<int, int>> vp2, vp3;
        for(auto [a, b] : vp){
            if(a >= 0){
                vp2.push_back({a, b});
            }else{
                vp3.push_back({a, b});
            }
        }
        sort(vp2.begin(), vp2.end(), [&](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        }); 
        bool ok = true;
        for(auto [a, b] : vp2){
            if(cs >= abs(b)) cs += a;
            else{
                ok = false;
            }
        }
        if(ok){
            //now only negatives (a)
            sort(vp3.begin(), vp3.end(), [&](pair<int, int> a, pair<int, int> b){
                return abs(a.first - a.second) < abs(b.first - b.second);
            }); 
            ll os = 0;
            for(auto [a, b] : vp3){
                if(os >= abs(a - b)) os += abs(a);
                else ok = false;
            }
        }

        if(ok) cout << "Yes\n";
        else cout << "No\n";
        

    }else cout << "No\n";
}
