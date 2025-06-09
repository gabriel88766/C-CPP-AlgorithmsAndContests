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
    int sum = 0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    vector<int> ann;
    for(int i=1;i*i<=sum;i++){
        if(sum % i == 0){
            ann.push_back(i);
            if(i*i != sum) ann.push_back(sum/i);
        }
    }
    sort(ann.begin(), ann.end());
    int ans;
    for(auto &x : ann){
        deque<int> acg;
        for(int j=0;j<n;j++){
            if(v[j] % x != 0) acg.push_back(v[j] % x);
        }
        sort(acg.begin(), acg.end());
        ll tt = 0;
        while(acg.size()){
            assert(acg.size() >= 2);

            int ms1 = acg.front();
            int ms2 = x - acg.back();
            if(ms1 == ms2){
                tt += ms1;
                acg.pop_front();
                acg.pop_back();
            }else if(ms1 < ms2){
                tt += ms1;
                acg.pop_front();
                acg.back() += ms1;
            }else{
                tt += ms2;
                acg.pop_back();
                acg.front() -= ms2;
            }
        }
        if(tt <= k) ans = x;
    }
    cout << ans << "\n";
}
