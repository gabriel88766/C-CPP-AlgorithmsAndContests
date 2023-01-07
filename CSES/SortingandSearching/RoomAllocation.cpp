#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, ansmax = 1;
    
    vector<pair<pair<int,int>, int>> v;
    cin >> n;
    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pqends;
    for(int i=1;i<=n;i++) pq.push(i);
    
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({{a, b}, i});
    }

    sort(v.begin(), v.end());
    pqends.push({v[0].first.second, 1}); //end, room, index
    ans[v[0].second] = 1;
    pq.pop();
    for(int i=1;i<n;i++){
        while(!pqends.empty()){
            if(pqends.top().first < v[i].first.first){
                pq.push(pqends.top().second);
                pqends.pop();
            }else break;
        }
        int aux = pq.top();
        ansmax = max(aux, ansmax);
        pq.pop();
        ans[v[i].second] = aux;
        pqends.push({v[i].first.second, aux});
    }

    cout << ansmax << "\n";
    for(int i=0;i<n;i++) cout << ans[i] << " ";
}
