#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int cnt[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    vector<pair<int,int>> vq; //value, quantity
    for(int i=0;i<N;i++){
        if(cnt[i]) vq.push_back({cnt[i], i});
    }
    sort(vq.begin(), vq.end(), greater<pair<int,int>>());
    int lo = 1, hi = 2e5, mid;
    while(lo!=hi){
        mid = (hi+lo)/2;
        int qt = 0;
        for(int i = 0; i < vq.size();i++){
            qt += vq[i].first/mid;
        }
        if(qt < k) hi = mid;
        else lo = mid + 1;
    }
    lo--;
    int bp = 0;
    vector<int> ans;
    for(int i=0;i<k;i++){
        if(vq[bp].first < lo) bp++, i--;
        else{
            vq[bp].first -= lo;
            ans.push_back(vq[bp].second);
        }
    }
    for(auto u: ans) cout << u << " ";
}
