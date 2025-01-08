#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int b, w;
        cin >> w >> b;
        int x, y;
        if(b > w){
            x = 3, y = 2;
        }else{
            x = y = 3;
            swap(b, w);
        }
        if(3*w + 1 < b) cout << "NO\n";
        else{
            cout << "YES\n";
            set<pair<int,int>> ans;
            vector<pair<int,int>> aux;
            for(int i=0;i<w;i++){
                ans.insert({x, y+2*i});
                ans.insert({x, y+2*i+1});
                aux.push_back({x, y+2*i});
                aux.push_back({x, y+2*i+1});
            }
            b -= w;
            for(auto [u, v] : aux){
                if((v - y) % 2 == 0){
                    for(int k=0;k<4;k++){
                        int xd = u + dx[k];
                        int yd = v + dy[k];
                        if(b > 0 && (!ans.count({xd, yd}))){
                            b--;
                            ans.insert({xd, yd});
                        } 
                    }
                }
            }
            for(auto [u, v]: ans) cout << u << " " << v << "\n";
        }
    }
}
