#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
int ans[N], cnt[N], aux[N];

void raddix_sort(vector<pair<int,int>> &v, int bounds){ //for pairs
    int n = v.size();
    for(int i=0; i<n; i++) cnt[v[i].second+1]++; //strategy, bounds next element
    for(int i=2; i<=(bounds+1); i++) cnt[i] += cnt[i-1];
    for(int i=0;i<n;i++) aux[cnt[v[i].second]++] = i;
    for(int i=0;i<=(bounds+1); i++) cnt[i] = 0;
    for(int i=0; i<n; i++) cnt[v[i].first+1]++; 
    for(int i=2; i<=(bounds+1); i++) cnt[i] += cnt[i-1];
    for(int i=0;i<n;i++) ans[cnt[v[aux[i]].first]++] = aux[i];    
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<pair<int,int>> pairs = {{3, 3}, {2, 1}, {2, 3}, {1, 3}, {1,2}};
    raddix_sort(pairs, 3);

    for(int i=0;i<5;i++) cout << ans[i] << " "; //index ordered;
}
