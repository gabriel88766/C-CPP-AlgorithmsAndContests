#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

bool compare(pair<pair<int,int>,int> &left, pair<pair<int,int>,int> &right){
    if(left.first.first != right.first.first ) return left < right;
    else return left.first.second > right.first.second;
}

bool compare2(pair<pair<int,int>,int> &left, pair<pair<int,int>,int> &right){
    if(left.first.second != right.first.second) return left.first.second < right.first.second;
    else return left.first.first > right.first.first;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<pair<int,int>,int>> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({{a,b}, i});
    }
    sort(v.begin(), v.end(), compare);
    int curmax = v[0].first.second;
    vector<int> ans1(n), ans0(n);
    for(int i=1;i<n;i++){
        if(v[i].first.second <= curmax){
            ans1[v[i].second] = 1;
        }
        curmax = max(v[i].first.second, curmax);
    }

    sort(v.begin(), v.end(), compare2);
    curmax = v[0].first.first;

    for(int i=1;i<n;i++){
        if(v[i].first.first <= curmax){
            ans0[v[i].second] = 1;
        }
        curmax = max(v[i].first.first, curmax);
    }


    for(int i=0;i<n;i++) cout << ans0[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++) cout << ans1[i] << " ";
   // pq.clear();
}
