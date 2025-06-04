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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int lo = 0, hi = n;
    while(lo != hi){
        int mid = lo + (hi - lo + 1)/2;
        int tl = 0, lst = 0, dm = 0;
        for(int i=0;i<n;i++){
            if(v[i] != lst && v[i] <= mid){
                tl++;
                lst = v[i];
            }else dm++;
        }
        if(tl + dm/2 >= mid) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}
