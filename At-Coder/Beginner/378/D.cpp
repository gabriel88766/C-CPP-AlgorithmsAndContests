#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<string> pm;
vector<string> gstr;
int k;
void genall(string cur){
    if(cur.size() == k){
        pm.push_back(cur);
        return;
    }
    if(cur.size() == 0){
        for(char c='0';c<='3';c++) genall(cur + c);
    }else{
        for(char c='0';c<='3';c++){
            if(cur.back() == '1' || cur.back() == '3'){
                if(c == cur.back() - 1) continue;
            }else if(c == cur.back() + 1) continue;
            genall(cur + c);
        }
    }
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char gr[15][15];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w;
    cin >> h >> w >> k;
    genall("");
    for(auto &s : pm){
        set<pair<int,int>> vis;
        int bx = 12, by = 12;
        vis.insert({bx, by});
        for(auto &c : s){
            bx += dx[c - '0'];
            by += dy[c - '0'];
            vis.insert({bx, by});
        }
        if(k+1 == vis.size()){ gstr.push_back(s);}
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    
    int ans = 0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(gr[i][j] == '.'){
                for(auto &s : gstr){
                    bool ok = true;
                    int bx = i, by = j;
                    for(auto &c : s){
                        bx += dx[c - '0'];
                        by += dy[c - '0'];
                        if(gr[bx][by] != '.'){
                            ok = false;
                            break;
                        }
                    }
                    if(ok) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}
