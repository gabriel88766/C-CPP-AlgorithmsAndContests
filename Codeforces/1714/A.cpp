#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, H, M;
        cin >> n >> H >> M;
        pair<int,int> best = {24,0};
        pair<int,int> cur;
        for(int i=0;i<n;i++){
            int h, m;
            cin >> h >> m;
            if(h > H || (h == H && m >= M)){
                cur.second = m-M;
                cur.first = h-H;
                if(cur.second < 0){cur.second += 60; cur.first--;}
            }else{
                cur.first = 23-H+h;
                cur.second = m+60-M;
                if(cur.second >= 60){cur.first++; cur.second-=60;}
            }
            best = min(cur, best);
        }
        cout << best.first << " " << best.second << "\n";
    }
}   
