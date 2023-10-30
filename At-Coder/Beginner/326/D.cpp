#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<string> c = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<vector<int>> pos;
    vector<int> perm;
    for(int i=0;i<n;i++) perm.push_back(i);
    do{
        vector<int> v;
        for(int i=0;i<3;i++) v.push_back(perm[i]);
        sort(v.begin(), v.end());
        bool ok = true;
        for(auto x : pos){
            if(v == x) ok = false;
        }
        if(ok) pos.push_back(v);
    }while(next_permutation(perm.begin(), perm.end()));

    int b = pos.size(); // 1 4 or 10
    int nm = 1;
    for(int i=0;i<n;i++) nm *= b; //1^3 or 4^4 or 10^5
    int n6 = 1; //6^n
    for(int j=0;j<n;j++) n6 *= 6;

    int ians = -1, jans = -1;
    for(int i=0;i<nm;i++){
        int ch[n];
        int aux = i;
        for(int j=0;j<n;j++){
            ch[j] = aux % b;
            aux /= b;
        }
        vector<int> ccnt(n, 0);
        for(int j=0;j<n;j++){
            for(int k=0;k<3;k++) ccnt[pos[ch[j]][k]]++;
        }
        bool ok = true;
        for(int j=0;j<n;j++){
            if(ccnt[j] != 3) ok = false;
        }
        if(ok){
            for(int j=0;j<n6;j++){
                ok = true;
                int ct[n];
                int aux = j;
                for(int k=0;k<n;k++){
                    ct[k] = aux % 6;
                    aux /= 6;
                }
                for(int k=0;k<n;k++){
                    if(c[ct[k]][0] != s[k]) ok = false;   
                }
                if(!ok) continue;
                vector<bool> vis(n, false);
                vector<vector<int>> cc(3, vector<int>(n, 0));
                for(int u=0;u<n;u++){
                    for(int v=0;v<3;v++){
                        if(!vis[pos[ch[u]][v]]){
                            vis[pos[ch[u]][v]] = true;
                            if(c[ct[u]][v] != t[pos[ch[u]][v]]) ok = false;
                        }
                        cc[c[ct[u]][v]-'A'][pos[ch[u]][v]]++;
                    }
                }
                for(int u=0;u<n;u++){
                    for(int v=0;v<3;v++){
                        if(cc[v][u] != 1) ok = false;
                    }
                }
                if(ok){
                    ians = i;
                    jans = j;
                    break;
                }
            }
            if(ok) break;
        }
    }
    if(ians != -1){
        int ct[n];
        int aux = jans;
        for(int k=0;k<n;k++){
            ct[k] = aux % 6;
            aux /= 6;
        }
        int ch[n];
        aux = ians;
        for(int j=0;j<n;j++){
            ch[j] = aux % b;
            aux /= b;
        }
        vector<vector<char>> ans(n, vector<char>(n, '.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                ans[i][pos[ch[i]][j]] = c[ct[i]][j];
            }
        }
        cout << "Yes\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }else cout << "No\n";

}
