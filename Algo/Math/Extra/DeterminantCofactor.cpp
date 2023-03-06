// O(N!)
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<vector<ll>> v(3, vector<ll> (3));

ll det(vector<vector<ll>> &v){
    int n = v.size();
    if(n == 2) {
        return v[0][0] * v[1][1] - v[1][0]*v[0][1];
    }
    vector<vector<ll>> aux(n-1, vector<ll> (n-1));
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            aux[i-1][j-1] = v[i][j];
        }
    }
    ll ans = det(aux) * v[0][0];
    for(int i=1;i<n;i++){
        for(int k=1;k<n;k++) aux[i-1][k-1] = v[i-1][k];
        if(i%2) ans -= v[i][0] * det(aux);
        else ans += v[i][0] * det(aux);
    }
    return ans;
}

int main(){
    vector<vector<ll>> tstMat = {{1,1,1,1,1}, {1,2,4,8,16}, {1,3,9,27,81}, {1,4,16,64,256}, {1,5,25,125,625}};
    ll sum = 0;
    for(int i=1;i<=1000000;i++){
        sum += det(tstMat);
    }
    cout << sum;

}