#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<int>> allx;
vector<int> cur;
int h, w, k;
void gen(){
    int sum = h;
    for(auto x : cur) sum -= x;
    for(int i=1;i<=sum;i++){
        if(i == sum){
            cur.push_back(i);
            allx.push_back(cur);
            cur.pop_back();
        }else{
            cur.push_back(i);
            gen();
            cur.pop_back();
        }
    }
}
char gr[11][1001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> h >> w >> k;
    gen();
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    int ans = INF_INT;
    for(auto &v : allx){
        vector<int> mp(h + 1);
        int l = 1;
        for(int i=0;i<v.size();i++){
            for(int j=l;j<l+v[i];j++) mp[j] = i;
            l += v[i];
        }
        int cur = 0;
        vector<int> cv(v.size());
        for(int j=1;j<=w;j++){
            vector<int> pls(v.size());
            for(int i=1;i<=h;i++){
                if(gr[i][j] == '1') pls[mp[i]]++;
            }
            bool reset = false;
            for(int i=0;i<v.size();i++){
                if(pls[i] > k){
                    cur = INF_INT;
                    break;
                }
                if(pls[i] + cv[i] > k){
                    reset = true;
                }
            }
            if(reset){
                cur++;
                for(int i=0;i<v.size();i++) cv[i] = pls[i];
            }else{
                for(int i=0;i<v.size();i++) cv[i] += pls[i];
            }
            if(cur == INF_INT) break;
        }
        ans = min(ans, cur + (int)v.size() - 1);
    }
    cout << ans << "\n";
}
