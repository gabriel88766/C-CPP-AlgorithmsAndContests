#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> v(10);
string s;
int n;
int solve(int a, int b){
    int res = INF_INT;
    if(max(v[a][0], v[b][0]) != n-1){
        if(v[a][0] < v[b][0]) return v[a][0] + v[b][0] - 1;
        else return v[a][0] + v[b][0];
    }else if(max(v[a][0], v[b][0]) == n-1 && min(v[a][0], v[b][0]) == n-2){
        if(n == 2){
            if(v[a][0] < v[b][0]) return 0;
            else return 1;
        }else if(s[n-3] != '0'){
            if(v[a][0] < v[b][0]) return v[a][0] + v[b][0] - 1;
            else return v[a][0] + v[b][0];
        }else{
            //then 50 is better
            return res;
        }
    }else{
        if(s[n-2] == '0'){
            int ind = -1;
            for(int i=n-2;i>=0;i--){
                if(i != v[a][0] && i != v[b][0] && s[i] != '0'){
                    ind = i;
                    break;
                }
            }
            if(ind > min(v[b][0], v[a][0])){
                res = n-2-ind;
            }else{
                res = n-2-ind-1;
            }
            if(v[a][0] < v[b][0]) return res + v[a][0] + v[b][0] - 1;
            else return res + v[a][0] + v[b][0];
        }else{
            if(v[a][0] < v[b][0]) return v[a][0] + v[b][0] - 1;
            else return v[a][0] + v[b][0];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    
    cin >> s;
    n = s.size();
    reverse(s.begin(), s.end());
    if(s.size() == 1) cout << "-1\n";
    else{
        
        for(int i=0;i<s.size();i++){
            v[s[i]-'0'].push_back(i);
        }
        //check 0 0
        int ans = INF_INT;
        if(v[0].size() >= 2){
            ans = min(ans, v[0][0] + v[0][1] - 1);
        }
        if(v[5].size()){
            //check 25
            if(v[2].size()){
                ans = min(ans, solve(5, 2));
            }
            //check 75
            if(v[7].size()){
                ans = min(ans, solve(5, 7));
            }
            //check 50
            if(v[0].size()){
                //..
                if(v[5][0] != n-1){
                    if(v[0][0] > v[5][0]) ans = min(ans, v[0][0] + v[5][0]);
                    else ans = min(ans, v[0][0] + v[5][0] - 1);
                }else if(n == 2){
                    ans = 0;
                }else{
                    int ind = -1;
                    for(int i=n-2;i>=0;i--){
                        if(s[i] != '0'){
                            ind = i;
                            break;
                        }
                    }
                    if(ind != -1){
                        if(ind > v[0][0]){
                            ans = min(ans, n-2-ind + n-2 + v[0][0]);
                        }else{
                            ans = min(ans, n-2-ind + n-3 + v[0][0]);
                        }
                    }
                }
            }
            
        }
        if(ans == INF_INT) cout << "-1\n";
        else cout << ans << "\n";
    }
}
