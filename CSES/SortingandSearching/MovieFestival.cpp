#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

set<pair<int,int>> sp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, count = 0, minbegin = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int aux1, aux2;
        cin >> aux1 >> aux2;
        sp.insert({aux2, aux1});
    }
    for(auto it : sp){
        if(it.second >= minbegin){
            count++;
            minbegin = it.first;
        }
    }
    cout << count;
}
