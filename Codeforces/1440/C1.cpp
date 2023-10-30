#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0,0,1,1};
int dy[] = {0,1,0,1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<int>> ops;
        for(int i=0;i<n;i++) cin >> v[i];
        if(n % 2 && m % 2){
            //change v[n-1][m-1] to 0
            if(v[n-1][m-1] == '1'){
                vector<int> op1;
                op1.push_back(n-1);
                op1.push_back(m-1);
                op1.push_back(n-2);
                op1.push_back(m-1);
                op1.push_back(n-1);
                op1.push_back(m-2);
                ops.push_back(op1);
                v[n-1][m-1] ^= 1;
                v[n-2][m-1] ^= 1;
                v[n-1][m-2] ^= 1;
            }
        }
        if(n % 2){
            for(int i=0;i<m-1;i+=2){ //handle odd
                if(v[n-1][i] == '1' || v[n-1][i+1] == '1'){
                    int cnt = 0;
                    vector<int> op1;
                    if(v[n-1][i] == '1'){
                        cnt++;
                        op1.push_back(n-1);
                        op1.push_back(i);
                    }
                    if(v[n-1][i+1] == '1'){
                        cnt++;
                        op1.push_back(n-1);
                        op1.push_back(i+1);
                    }
                    op1.push_back(n-2);
                    op1.push_back(i);
                    v[n-2][i] ^= 1;
                    cnt++;
                    if(cnt != 3){
                        op1.push_back(n-2);
                        op1.push_back(i+1);
                        v[n-2][i+1] ^= 1;
                    }
                    ops.push_back(op1);
                }
            }
            n--;
        }
        if(m % 2){
            for(int i=0;i<n-1;i+=2){ //handle odd
                if(v[i][m-1] == '1' || v[i+1][m-1] == '1'){
                    int cnt = 0;
                    vector<int> op1;
                    if(v[i][m-1] == '1'){
                        cnt++;
                        op1.push_back(i);
                        op1.push_back(m-1);
                    }
                    if(v[i+1][m-1] == '1'){
                        cnt++;
                        op1.push_back(i+1);
                        op1.push_back(m-1);
                    }
                    op1.push_back(i);
                    op1.push_back(m-2);
                    v[i][m-2] ^= 1;
                    cnt++;
                    if(cnt != 3){
                        op1.push_back(i+1);
                        op1.push_back(m-2);
                        v[i+1][m-2] ^= 1;
                    }
                    ops.push_back(op1);
                }
            }
            m--;
        }

        for(int i=0;i<n;i+=2){
            for(int j=0;j<m;j+=2){
                int cnt = 0;
                do{
                    cnt = 0;
                    vector<pair<int,int>> vc0, vc1;
                    for(int k=0;k<4;k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(v[x][y] == '1'){
                            vc1.push_back({x, y});
                            cnt++;
                        }else{
                            vc0.push_back({x, y});
                        }
                    }
                    vector<int> op;
                    int tt1 = 0;
                    if(cnt == 1 || cnt == 2){
                        for(int k=0;k<2;k++){
                            auto x = vc0[k];
                            op.push_back(x.first);
                            op.push_back(x.second);
                            v[x.first][x.second] ^= 1;
                        }
                        tt1 = 1;
                    }else tt1 = 3;
                    if(cnt != 0){
                        for(int k=0;k<tt1;k++){
                            auto x = vc1[k];
                            op.push_back(x.first);
                            op.push_back(x.second);
                            v[x.first][x.second] ^= 1;
                        }
                        ops.push_back(op);
                    }
                }while(cnt != 0);
            }
        }
        cout << ops.size() << "\n";
        for(auto x : ops){
            for(auto y : x) cout << y+1 << " ";
            cout << "\n";
        }
    }
}
