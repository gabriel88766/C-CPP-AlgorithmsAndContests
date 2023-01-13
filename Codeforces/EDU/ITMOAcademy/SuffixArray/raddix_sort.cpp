#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

const int N = 2e5;
int ans[N], cnt[N], aux[N];

void raddix_sort(vector<pair<int,int>> &v){
    for(int i=0; i<v.size(); i++) cnt[v[i].second]++;
    for(int i=1;i<v.size(); i++) cnt[i] += cnt[i-1];
    for(int i=0;i<v.size();i++) aux[--cnt[v[i].second]] = i;

    
    
}


void test(vector<int> &v, vector<int> &mp){
    for(int j=0;j<5;j++){
        ans[mp[j]] = v[j];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<int,int>> pairs = {{3, 3}, {2, 1}, {2, 3}, {1, 3}, {1,2}};
    raddix_sort(pairs);

    vector<int> v = {1 ,2, 3, 4, 5}, mp = {4, 2, 3, 0, 1}, invmp = {3, 4, 1, 2, 0};
    test(v, mp);
    for(int i=0;i<5;i++) cout << ans[i] << " ";
}
