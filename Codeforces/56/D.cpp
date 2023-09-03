#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
int dp[N][N];
pair<int,int> p[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(i == 0){
                 dp[i][j] = j;
                 p[i][j] = {i, j-1};
                 continue;
            }
            if(j == 0){
                dp[i][j] = i;
                p[i][j] = {i-1, j};
                continue;
            }
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1];
                p[i][j] = {i-1, j-1};
            }else{
                dp[i][j] = dp[i-1][j-1]+1;
                p[i][j] = {i-1, j-1};
            }
            
            if(dp[i-1][j] + 1 < dp[i][j]){
                dp[i][j] = dp[i-1][j]+1;
                p[i][j] = {i-1, j};
            }
            if(dp[i][j-1] + 1 < dp[i][j]){
                dp[i][j] = dp[i][j-1]+1;
                p[i][j] = {i, j-1};
            }
        }
    }

    //FINISHED EDIT DISTANCE, BEGIN PAIN!!!
    pair<int,int> cur = {s.size()-1, t.size()-1};
    vector<tuple<string, int, char>> ans;
    vector<pair<int,int>> path;
    path.push_back(cur);
    while(dp[cur.first][cur.second] != 0){
        cur = p[cur.first][cur.second];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    int len = path[0].first;
    for(int i=1;i<path.size();i++){
        if(dp[path[i-1].first][path[i-1].second] != dp[path[i].first][path[i].second]){
            if(path[i].first == path[i-1].first){
                ans.push_back({"INSERT", len+1, t[path[i].second]});
                len++;
            }else if(path[i].second == path[i-1].second){
                ans.push_back({"DELETE", len+1, 'x'});
            }else{
                ans.push_back({"REPLACE", len+1, t[path[i].second]});
                len++;
            }
        }else len++;
    }
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << get<0>(x) << " " << get<1>(x);
        if(get<0>(x) != "DELETE") cout << " " << get<2>(x);
        cout << "\n";
    }
}
