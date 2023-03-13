#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Interval{
    int a,b,c;
};


int maxv[20005]; //maxv in time T.



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, T = 0;
    cin >> n;
    vector<int> v(n), t(n);
    vector<pair<int,int>> vp(n+1);
    vector<Interval> vi;
    for(int i=0;i<n;i++){
        vp[i].first = T;
         cin >> t[i];
         T += t[i];
    }
    if(T == 1){
        cout << "0.25";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
        vp[i].second = v[i];
    }
    vp[n] = {T, 0};
    double ans = 0;
    maxv[0] = maxv[T] = 0;
    for(int i=1;i<T;i++){ //O(2e6)
        int up1 = maxv[i-1] + 1;
        int ind = lower_bound(vp.begin(), vp.end(), make_pair(i, 0)) - vp.begin();
        int lo = vp[ind-1].second;
        for(int j=ind;j<=n;j++){
            lo = min(lo, vp[j].second + (vp[j].first - i));
        }
        maxv[i] = min(lo, up1);

        if(maxv[i] == maxv[i-1] && vp[ind-1].second > maxv[i]) ans += 0.25;
    }
    int sign = 1, bp = 0;
    for(int i=1;i<=T;i++){
        if((maxv[i] > maxv[i-1] && sign != 1) || (maxv[i] < maxv[i-1] && sign != -1) || (maxv[i] == maxv[i-1] && sign != 0)){
            Interval in;
            in.c = sign, in.a = bp, in.b = i-1;
            vi.push_back(in);
            bp = i-1;
        }
        if(maxv[i] > maxv[i-1]) sign = 1;
        else if(maxv[i] < maxv[i-1]) sign = -1;
        else sign = 0;
    }
    Interval in2;
    in2.a = bp, in2.b = T, in2.c = -1;
    vi.push_back(in2);
    
    for(int i=0;i<vi.size();i++){
        auto &x = vi[i];
        ans += min(maxv[x.a], maxv[x.b])*(x.b-x.a);
        if(x.c){
            ans += ((double)(abs(maxv[x.a] - maxv[x.b])*(x.b-x.a)))/2;
        }
    }
    cout << fixed << setprecision(10) << ans;
}   
