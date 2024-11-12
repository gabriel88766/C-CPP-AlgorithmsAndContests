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
    int v[16];
    for(int i=0;i<16;i++) cin >> v[i];
    int ans = 0;
    for(int i=1;i<(1 << 16);i++){
        bool ok1 = true;
        for(int j=0;j<16;j++){
            if(v[j]){
                if(!(i & (1 << j))) ok1 = false;
            }
        }
        if(!ok1) continue;
        vector<bool> vis(16, false);
        int lj = -1;
        for(int j=0;j<16;j++) if(i & (1 << j)) lj = j;
        queue<int> q;
        q.push(lj);
        vis[lj] = true;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            if(u % 4 != 3){
                if((!vis[u+1]) && (i & (1 << (u+1)))){
                    q.push(u+1);
                    vis[u+1] = true;
                }
            }
            if(u % 4 != 0){
                if((!vis[u-1]) && (i & (1 << (u-1)))){
                    q.push(u-1);
                    vis[u-1] = true;
                }
            }
            if(u <= 11){
                if((!vis[u+4]) && (i & (1 << (u+4)))){
                    q.push(u+4);
                    vis[u+4] = true;
                }
            }
            if(u >= 4){
                if((!vis[u-4]) && (i & (1 << (u-4)))){
                    q.push(u-4);
                    vis[u-4] = true;
                }
            }
        }
        bool ok2 = true;
        for(int j=0;j<16;j++){
            if(i & (1 << j)){
                if(!vis[j]) ok2 = false;
            }
        }
        if(ok2){
            queue<int> q;
            vector<int> vis(16, false);
            for(int j=0;j<4;j++) if(!(i & (1 << j))){q.push(j); vis[j] = true;}
            for(int j=4;j<=8;j+=4) if(!(i & (1 << j))){q.push(j); vis[j] = true;}
            for(int j=7;j<=11;j+=4) if(!(i & (1 << j))){q.push(j); vis[j] = true;}
            for(int j=12;j<16;j++) if(!(i & (1 << j))){q.push(j); vis[j] = true;}
            while(!q.empty()){
                auto u = q.front();
                q.pop();
                if(u % 4 != 3){
                    if((!vis[u+1]) && !(i & (1 << (u+1)))){
                        q.push(u+1);
                        vis[u+1] = true;
                    }
                }
                if(u % 4 != 0){
                    if((!vis[u-1]) && !(i & (1 << (u-1)))){
                        q.push(u-1);
                        vis[u-1] = true;
                    }
                }
                if(u <= 11){
                    if((!vis[u+4]) && !(i & (1 << (u+4)))){
                        q.push(u+4);
                        vis[u+4] = true;
                    }
                }
                if(u >= 4){
                    if((!vis[u-4]) && !(i & (1 << (u-4)))){
                        q.push(u-4);
                        vis[u-4] = true;
                    }
                }
            }
            for(int j=0;j<16;j++){
                if(!(i & (1 << j))){
                    if(!vis[j]) ok2 = false;
                }
            }
            if(ok2)ans++;
        }
    }
    cout << ans << "\n";
}
