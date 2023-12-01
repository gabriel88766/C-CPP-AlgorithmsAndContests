#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
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
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=n-1;i>=1;i--){
        //from 0 to i; best i sums
        ll fs = v[0] + v[1];
        // fs+MOD >= sums >= fs 
        ll lo = fs-1, hi = fs+MOD;
        while(lo != hi){ //lo+1 is the limit
            ll mid = lo + (hi - lo) / 2;
            int p = i;
            ll qt = 0;
            for(int j=0;j<i;j++){
                while(p > 0){
                    if(v[j] + v[p] <= mid) break;
                    else --p;
                }
                if(p > j) qt += p-j;
                else break;
            }
            if(qt >= i) hi = mid;
            else lo = mid+1;
        }
        int p2 = i;
        vector<ll> news;
        for(int j=0;j<i;j++){
            while(p2 > 0){
                if(v[j] + v[p2] < lo) break;
                else --p2;
            }
            if(p2 <= j) break;
            for(int k=j+1;k<=p2;k++){
                news.push_back(v[j] + v[k]);
            }
        }
        while(news.size() < i) news.push_back(lo);
        assert(news.size() == i);
        sort(news.begin(), news.end());
        for(int j=0;j<i;j++) v[j] = news[j];
        if(v[0] >= MOD){
            ll d = v[0]/MOD;
            ll dm = d*MOD;
            for(int j=0;j<i;j++) v[j] -= dm; 
        }
    }
    cout << v[0] << "\n";
}