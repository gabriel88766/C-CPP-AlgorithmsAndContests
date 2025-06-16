#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void check(vector<pair<int, int>> &ans, int n, int m){
    vector<string> ch(n, string(m, '.'));
    for(auto [a, b] : ans) ch[a-1][b-1] = 'x';
    for(auto &s : ch) cout << s << "\n";
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int lx, ly, rx, ry;
        int n, m;
        cin >> n >> m;
        ly = ry = (n+1)/2;
        lx = rx = (m+1)/2;
        vector<pair<int, int>> ans;
        while(lx >= 1 && ly >= 1){
            //do..
            int clx = (m+1)/2;
            int crx = clx;
            while(clx >= lx + 1){
                if(clx != crx){
                    ans.push_back({ly, clx});
                    ans.push_back({ry, clx});
                    ans.push_back({ly, crx});
                    ans.push_back({ry, crx});
                }else{
                    ans.push_back({ly, clx});
                    ans.push_back({ry, clx});
                }
                clx--;
                crx++;
            }
            int cly = (n+1)/2;
            int cry = cly;
            while(cly >= ly + 1){
                if(cly != cry){
                    ans.push_back({cly, lx});
                    ans.push_back({cly, rx});
                    ans.push_back({cry, lx});
                    ans.push_back({cry, rx});
                }else{
                    ans.push_back({cly, lx});
                    ans.push_back({cly, rx});
                }
                cly--;
                cry++;
            }
            //corners
            if(lx != rx){
                ans.push_back({ly, lx});
                ans.push_back({ly, rx});
                ans.push_back({ry, lx});
                ans.push_back({ry, rx});
            }else{
                //mid
                ans.push_back({ly, lx});
            }

            lx--; ly--; rx++; ry++;
        }
        if(lx == 0 && ly == 0);//done
        else if(lx == 0){
            while(ly){
                int mid = (m+1)/2;
                ans.push_back({ly, mid});
                ans.push_back({ry, mid});
                for(int i=1;i<mid;i++){
                    int lf = mid - i;
                    int rg = mid + i;
                    ans.push_back({ly, lf});
                    ans.push_back({ry, lf});
                    ans.push_back({ly, rg});
                    ans.push_back({ry, rg});
                }
                ly--; ry++;
            }
        }else{  
            while(lx){
                int mid = (n+1)/2;
                ans.push_back({mid, lx});
                ans.push_back({mid, rx});
                for(int i=1;i<mid;i++){
                    int lf = mid - i;
                    int rg = mid + i;
                    ans.push_back({lf, lx});
                    ans.push_back({lf, rx});
                    ans.push_back({rg, lx});
                    ans.push_back({rg, rx});
                }
                lx--; rx++;
            }
        }
        for(auto [a, b] : ans) cout << a << " " << b << "\n";
        cout << "\n";
    }
}
