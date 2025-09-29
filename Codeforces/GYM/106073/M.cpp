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
    int n, k;
    cin >> n >> k;
    vector<int> vx(n+1);
    for(int i=1;i<=n;i++) cin >> vx[i];
    int lo = 1, hi = 2e9;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        vector<int> cv;
        for(int i=1;i<=n;i++){
            cv.push_back(max(0, mid - vx[i]));
        }
        while(cv.size()){
            if(cv.back() == 0) cv.pop_back();
            else break;
        }
        int ck = k;
        bool ok = true;
        while(cv.size()){
            if(ck >= cv.back()){
                if(ck != 0) ck--;
                cv.pop_back();
            }else{
                ok = false;
                break;
            }
        }
        if(ok) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}   
