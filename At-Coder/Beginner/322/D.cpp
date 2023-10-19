#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> ops(196);
vector<int> op(int x){
    vector<int> ans(3);
    ans[0] = (x % 7) - 3;
    x -= (x % 7);
    x /= 7;
    ans[1] = (x % 7) - 3;
    x -= (x % 7);
    x /= 7;
    ans[2] = x % 4;
    return ans;
}

bool up(vector<vector<char>> &v, int qt){
    vector<vector<char>> ans(4, vector<char>(4, '.'));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(v[i][j] == '#' && (i+qt >= 4 || i+qt < 0)) return false;
            else if(v[i][j] == '#'){
                ans[i+qt][j] = '#';
            }
        }
    }
    v = ans;
    return true;
}
bool left(vector<vector<char>> &v, int qt){
    vector<vector<char>> ans(4, vector<char>(4, '.'));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(v[i][j] == '#' && (j+qt >= 4 || j+qt < 0)) return false;
            else if(v[i][j] == '#'){
                ans[i][j+qt] = '#';
            }
        }
    }
    v = ans;
    return true;
}

void rot(vector<vector<char>> &v, int qt){
    vector<vector<char>> ans(4, vector<char>(4, '.'));
    for(int i=0;i<qt;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                ans[k][4-j-1] = v[j][k];
            }
        }
        v = ans;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<196;i++){
        ops[i] = op(i);
    }
    bool ok = false;
    vector<vector<vector<char>>> po(3, vector<vector<char>>(4, vector<char>(4)));
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cin >> po[i][j][k]; 
            }
        }
    }
    int cnt2 = 0;
    for(int i=0;i<196;i++){
        auto curi = po[0];
        if(!up(curi, ops[i][0])) continue;
        if(!left(curi, ops[i][1])) continue;
        rot(curi, ops[i][2]);

        for(int j=0;j<196;j++){
            auto curj = po[1];
            if(!up(curj, ops[j][0])) continue;
            if(!left(curj, ops[j][1])) continue;
            rot(curj, ops[j][2]);
            for(int k = 0; k < 196; k++){
                auto curk = po[2];
                if(!up(curk, ops[k][0])) continue;
                if(!left(curk, ops[k][1])) continue;
                rot(curk, ops[k][2]);
                bool ok2 = true;
                cnt2++;
                for(int w=0;w<4;w++){
                    for(int v=0;v<4;v++){
                        int cnt = 0;
                        if(curi[w][v] == '#') cnt++;
                        if(curj[w][v] == '#') cnt++;
                        if(curk[w][v] == '#') cnt++;
                        if(cnt != 1) ok2 = false;
                    }
                }
                if(ok2){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
}
