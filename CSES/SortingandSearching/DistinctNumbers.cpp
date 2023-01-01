#include <bits/stdc++.h>
typedef long long int ll;
const ll MAX_LL = 0x3f3f3f3f3f3f3f3f;
const int MAX_INT = 0x3f3f3f3f;
using namespace std;

set<int> ss;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, aux;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> aux;
        ss.insert(aux);
    }
    cout << ss.size();
}
