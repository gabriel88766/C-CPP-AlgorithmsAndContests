#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char vis[7][7][7][7][7][7][7];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin); //test input
    freopen("out.txt", "w", stdout); //test input
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        vector<string> gr(6);
        for(int i=0;i<6;i++) cin >> gr[i];
        queue<vector<int>> q;
        memset(vis, 0, sizeof(vis));
        q.push({6, 6, 6, 6, 6, 6, 6});
        vis[6][6][6][6][6][6][6] = true;
        bool pos1 = false, pos2 = false;
        while(!q.empty()){
            auto cur = q.front(); //this position  is still undefined
            q.pop();
            for(int i=0;i<7;i++){
                if(cur[i] == 0) continue;
                auto d = cur;
                d[i]--;

                if(vis[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]]) continue;
                vis[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]] = true;
                //for up
                bool iswin = false;
                int j = d[i];
                auto check = [&](int u, int v){
                    if(u < 0 || u >= 7) return false;
                    if(v < 0 || v >= 6) return false;
                    if(d[u] > v) return false;
                    if(gr[j][i] == gr[v][u]) return true;
                    else return false;
                };
                for(int mv = 0;mv<=7;mv++){
                    bool okc = true;
                    for(int k=1;k<=3;k++){
                        okc &= check(i + dx[mv]*k, j+dy[mv]*k);
                    }
                    if(okc) iswin = true;
                }
                if(iswin){
                    if(gr[j][i] == 'C') pos1 = true;
                    else pos2 = true;
                }else{
                    q.push(d);
                }
                d[i]++;
            }
        }



        cout << "Case #" << i << ": ";
        if(pos1 && pos2) cout << "?\n";
        else if(pos1) cout << "C\n";
        else if(pos2) cout << "F\n";
        else cout << "0\n";
    }
}
