#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;




const int N = 200005, M = 20; // M >= log2(N)
ll sp1[N][M], sp2[N][M];
vector<int> v;

void build(){
    int n = v.size();
    for(int i=0;i<n;i++) sp1[i][0] = sp2[i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sp1[i][j] = min(sp1[i][j-1], sp1[i + (1 << (j-1))][j-1]), sp2[i][j] = min(sp2[i][j-1], sp2[i + (1 << (j-1))][j-1]);
            else sp1[i][j] = sp1[i][j-1], sp2[i][j] = sp2[i][j-1];
        }
    }
}

int qmin(int a, int b){
    if(b < a) return INF_INT;
    if(a == b) return sp1[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return min(sp1[a][pot], sp1[b - (1 << pot) + 1][pot]);
}

int qmax(int a, int b){
    if(b < a) return 0;
    if(a == b) return sp2[a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sp2[a][pot], sp2[b - (1 << pot) + 1][pot]);
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    for(int i=0;i<n;i++) v.push_back(vp[i].second);
    build();

    int lo = 0, hi = 1000000000;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        int p1 = 0, p2 = 0;
        int maxv = 0;
        for(int i=0;i<n;i++){
            while(p2 < n && vp[p2].first - vp[i].first < mid){
                p2++;
            }
            while(p1 < n && vp[i].first - vp[p1].first >= mid){
                p1++;
            }
            if(p2 != n || p1 != 0){
                int maxp = max(qmax(p2, n-1), qmax(0, p1-1));
                int minp = min(qmin(p2, n-1), qmin(0, p1-1));
                if(minp != INF_INT) maxv = max(maxv, vp[i].second - minp);
                if(maxp != 0) maxv = max(maxv, maxp - vp[i].second);
            }
        }
        if(maxv >= mid) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}   
