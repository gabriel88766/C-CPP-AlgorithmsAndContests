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
        string s, z;
        cin >> s >> z;
        deque<pair<int, int>> va, vb;
        char l = '-';
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] != l){
                if(c) va.push_back({l-'0', c});
                c = 1;
                l = s[i];
            }else c++;
        }
        va.push_back({l-'0', c});
        l = '-';
        c = 0;
        for(int i=0;i<z.size();i++){
            if(z[i] != l){
                if(c) vb.push_back({l-'0', c});
                c = 1;
                l = z[i];
            }else c++;
        }
        vb.push_back({l-'0', c});
        int ans = 0;
        while(va.size() && vb.size()){
            while(va.size() >= 2 && va[0].first == va[1].first){
                va[1].second += va[0].second;
                va.pop_front();
            }
            if(va[0].first == vb[0].first){
                if(va[0].second == vb[0].second){
                    va.pop_front();
                    vb.pop_front();
                }else if(va[0].second < vb[0].second){
                    vb[0].second -= va[0].second;
                    va.pop_front();
                }else break;
            }else{
                if(va.size() == 1) break;
                else {swap(va[0], va[1]); ans++;}
            }
        }
        if(va.size() || vb.size()) cout << "-1\n";
        else cout << ans << "\n";
    }
}
