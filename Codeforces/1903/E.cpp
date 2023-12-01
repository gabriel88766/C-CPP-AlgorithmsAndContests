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
        int n, sx, sy;
        cin >> n >> sx >> sy;
        int ini = (sx % 2) ^ (sy % 2);
        vector<int> x(n+1), y(n+1);
        vector<int> ty(n+1);
        set<int> vs[2];
        for(int i=1;i<=n;i++){
            cin >> x[i] >> y[i];
            ty[i] = (x[i] % 2) ^ (y[i] % 2);
            vs[ty[i]].insert(i);
        }
        if(vs[ini].size() >= vs[ini^1].size()){
            cout << "First\n";
            int nxt = 1;
            while(vs[ini].size() || vs[ini^1].size()){
                if(nxt){
                    if(vs[ini^1].size()){
                        cout << *vs[ini^1].begin() << "\n";
                        vs[ini^1].erase(vs[ini^1].begin());
                        cout.flush();
                    }else{
                        cout << *vs[ini].begin() << "\n";
                        vs[ini].erase(vs[ini].begin());
                        cout.flush();
                    }
                }else{
                    int cur;
                    cin >> cur;
                    if(vs[ini].count(cur)) vs[ini].erase(cur);
                    else vs[ini^1].erase(cur);
                }
                nxt ^= 1;
            }
        }else{
            cout << "Second\n";
            cout.flush();
            int nxt = 0;
            while(vs[ini].size() || vs[ini^1].size()){
                if(nxt){
                    if(vs[ini].size()){
                        cout << *vs[ini].begin() << "\n";
                        vs[ini].erase(vs[ini].begin());
                        cout.flush();
                    }else{
                        cout << *vs[ini^1].begin() << "\n";
                        vs[ini^1].erase(vs[ini^1].begin());
                        cout.flush();
                    }
                }else{
                    int cur;
                    cin >> cur;
                    if(vs[ini].count(cur)) vs[ini].erase(cur);
                    else vs[ini^1].erase(cur);
                }
                nxt ^= 1;
            }
        }
    }
}
