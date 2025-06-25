#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> lose = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
int gr[3][3];
map<string, int> mp;
void solve(string st){
    if(mp.count(st)) return;
    int c0 = 0, c1 = 0, c2 = 0;
    for(auto &x : st){
        if(x == '0') c0++;
        else if(x == '1') c1++;
        else c2++;
    }
    char nxt;
    if(c1 > c2) nxt = '2';
    else nxt = '1';
    for(auto &x : lose){
        if(st[x[0]] == st[x[1]] && st[x[1]] == st[x[2]] && st[x[0]] != '0'){
            mp[st] = 0;
            return;
        }
    }
    if(c0 == 0){
        ll p1 = 0, p2 = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(st[3*i + j] == '1') p1 += gr[i][j];
                else p2 += gr[i][j];
            }
        }
        if(p1 > p2){
            mp[st] = 0; //I lose, "Aoki turn -- not actually"
        }else{
            mp[st] = 1;
        }
        return;
    }
    
    bool hzr = false;
    for(int i=0;i<9;i++){
        if(st[i] == '0'){
            auto chk = st;
            chk[i] = nxt;
            solve(chk);
            if(mp[chk] == 0) hzr = true;
        }
    }
    if(hzr) mp[st] = 1;
    else mp[st] = 0;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> gr[i][j];
        }
    }
    string st = "000000000";
    solve(st);
    if(mp[st]) cout << "Takahashi\n";
    else cout << "Aoki\n";
}
