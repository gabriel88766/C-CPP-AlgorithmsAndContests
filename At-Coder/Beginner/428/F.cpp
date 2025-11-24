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
    int n, q;
    cin >> n;
    vector<int> wv(n+2);
    for(int i=1;i<=n;i++) cin >> wv[i];
    wv[n+1] = INF_INT;
    cin >> q;
    vector<tuple<int, int, int>> cv;
    cv.push_back({n+1, 0, 0});
    for(int i=0;i<q;i++){
        int tq, x, y;
        cin >> tq >> x;
        if(tq <= 2){
            while(true){
                auto [a, b, c] = cv.back();
                if(a <= x) cv.pop_back();
                else break;
            } //find y
            auto [a, b, c] = cv.back();
            y = b;
            if(c == 1){//then sum diffs from x to a
                y += wv[a] - wv[x];
            }
            if(tq == 1){
                if(c != 0) cv.push_back({x, y, 0});
            }else{
                if(c != 1) cv.push_back({x, y, 1});
            }
        }
        if(tq == 3){
            int lo = 0, hi = cv.size() - 1;
            while(lo != hi){
                int mid = lo + (hi - lo + 1) / 2;
                auto [a, b, c] = cv[mid];
                if(b <= x && b + wv[a] > x){
                    lo = mid;
                }else hi = mid - 1;
            }
            auto [a, b, c] = cv[lo];
            int lo2 = 1, hi2 = a;
            while(lo2 != hi2){
                int mid2 = lo2 + (hi2 - lo2)/2;
                int l = b, r = b + wv[a]; 
                if(c == 0) r -= (wv[a] - wv[mid2]);
                else l += (wv[a] - wv[mid2]);
                if(l <= x && r > x) hi2 = mid2;
                else lo2 = mid2 + 1;
            }  
            cout << n - lo2 + 1 << "\n";
        }
    }
}
