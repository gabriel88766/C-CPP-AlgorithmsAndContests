//Ultra OverKill, this question is just sorting and searching + nCr
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

pair<ll, ll> bs1[26], bs2[26];
ll bestsum[51];

ll v[51];
void weird_sum(int cur, int cnt, int maxv, ll sum, pair<ll,ll> *bs){
    if(cur == maxv) return;
    sum += v[cur];
    if(bs[cnt+1].first == sum) bs[cnt+1].second++;
    else if(bs[cnt+1].first < sum) bs[cnt+1] = {sum, 1LL};
    weird_sum(cur+1, cnt+1, maxv, sum, bs);
    sum -= v[cur];
    weird_sum(cur+1, cnt, maxv, sum, bs);
}

bool cmp(ll a, ll b){
    if(bestsum[a] * b != bestsum[b] * a) return bestsum[a] * b > bestsum[b] * a;
    else return a > b;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, a, b;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) cin >> v[i];
    int mid = n/2;
    bs1[0] = bs2[0] = {0LL, 1};
    weird_sum(0, 0, mid, 0, bs1);
    weird_sum(mid, 0, n, 0, bs2);

    for(int i=0;i<=mid;i++){
        for(int j=0;j<=(n-mid);j++){
            bestsum[i+j] = max(bestsum[i+j], bs1[i].first + bs2[j].first);
        }
    }

    vector<ll> v;
    for(ll i=a;i<=b;i++) v.emplace_back(i);
    sort(v.begin(), v.end(), cmp);
    int ind = 0;
    for(int i=0; i < v.size(); i++){
        if(i == (v.size()-1)) break;
        int aa = v[i], ab = v[i+1];
        if(bestsum[aa] * ab != bestsum[ab] * aa) break;
        else ind = i+1;
    }
    ll ans = 0;
    for(int i=0;i<=ind;i++){
        int cur = v[i];
        for(int j=0;j<=mid;j++){
            for(int k=0;k<=(n-mid);k++){
                if((j+k) != cur) continue;
                if(bs1[j].first + bs2[k].first == bestsum[cur]){
                    ans += bs1[j].second * bs2[k].second;
                }
            }
        }
    }
    long double ansavg = bestsum[v[0]];
    ansavg /= v[0];
    cout << setprecision(6) << fixed << ansavg << "\n" << ans;
}
