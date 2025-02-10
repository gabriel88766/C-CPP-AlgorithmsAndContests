#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int p[N], vis[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<vector<int>> ap;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> cp;
            int x = i;
            cp.push_back(p[x]);
            while(p[x] != i){
                x = p[x];
                cp.push_back(p[x]);
            }
            for(auto &y : cp) vis[y] = true;
            ap.push_back(cp);
        }
    }
    int ml = 0;
    for(auto &v : ap){
        ml = max(ml, (int)v.size());
    }
    if(ml == 1) cout << "0\n";
    else if(ml == 2){
        cout << "1\n";
        vector<pair<int, int>> ans;
        for(auto &v : ap){
            if(v.size() == 1) continue;
            ans.push_back({v[0], v[1]});
        }
        cout << ans.size() << "\n";
        for(auto &[a, b] : ans) cout << a << " " << b << "\n";
    }else{
        vector<pair<int,int>> a1, a2;
        cout << "2\n";
        for(auto &v : ap){
            if(v.size() == 1) continue;
            if(v.size() == 2){
                a1.push_back({v[0], v[1]});
            }else{
                for(int i=0;;i++){
                    int ov = v.size() - i - 1;
                    if(ov > i){
                        a1.push_back({v[i], v[ov]});
                    }else break;
                }
                for(int i=1;;i++){
                    int ov = v.size() - i;
                    if(ov > i){
                        a2.push_back({v[i], v[ov]});
                    }else break;
                }
            }
        }
        cout << a1.size() << "\n";
        for(auto &[a, b] : a1) cout << a << " " << b << "\n";
        cout << a2.size() << "\n";
        for(auto &[a, b] : a2) cout << a << " " << b << "\n";
    }
}
