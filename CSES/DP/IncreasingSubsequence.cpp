#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 200005;
vector<int> d(N,INF);

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,cont;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    d[0]=-INF;
    for(int i=0;i<n;i++){
        auto it = lower_bound(d.begin(),d.end(),v[i]);
        int k = it - d.begin();
        d[k] = min(d[k],v[i]);
    }
    int ans;
    for(ans=0;ans < N;ans++){
        if(d[ans]==INF) break;
    }
    cout << ans-1;

}
