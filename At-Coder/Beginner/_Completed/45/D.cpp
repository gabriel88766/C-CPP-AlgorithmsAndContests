#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0,1,2,0,1,2,0,1,2};
int dy[] = {0,0,0,1,1,1,2,2,2};

ll ans[10];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll H,W,N; 
    cin >> H >> W >> N;
    ans[0] = (H-2)*(W-2);
    set<pair<int,int>> points;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        points.insert({a,b});
    }
    for(auto it = points.begin(); it != points.end(); it++){
        int a = it->first, b = it->second, cnt;
        bool ok;
        for(int i=a-2; i<=a;i++){
            if(i <= 0 || i > H) continue;
            for(int j=b-2;j<=b;j++){
                if(j <= 0 || j > W) continue;
                ok = true, cnt = 0;
                for(int k=0;k<9;k++){
                    pair<int,int> point = {i+dx[k], j+dy[k]};
                    if(point.first > H || point.first <= 0){
                        ok = false; break;
                    }
                    if(point.second > W || point.second <=0){
                        ok = false; break;
                    }
                    if(points.count(point)){
                        if(point < *it){
                            ok = false;
                            break;
                        }else cnt++;
                    }
                }
                if(ok){
                    ans[cnt]++;
                    ans[0]--;
                }
            }
        }
    }
    for(int i=0;i<=9;i++) cout << ans[i] << "\n";
}
