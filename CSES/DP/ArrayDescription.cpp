#include <bits/stdc++.h>

using namespace std;

unsigned int matrix[100005][102];
const int MOD = 1e9+7;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
//freopen("test_input.txt", "r", stdin);
int n,k;
cin >> n >> k;
vector<unsigned int> v(n,0);
for(int i=0;i<n;i++){
    cin >> v[i];
}
if(!v[0]){
    for(int i=1;i<=100;i++){
        matrix[0][i]=1;
    }
}else{
    matrix[0][v[0]]=1;
}
for(int i=1;i<n;i++){
    if(v[i]==0) {
        matrix[i][1] = (matrix[i-1][1]+matrix[i-1][2])%MOD;
        for(int j=2;j<k;j++){
            matrix[i][j] = (matrix[i-1][j]+matrix[i-1][j+1]+matrix[i-1][j-1])%MOD;
        }
        matrix[i][k] = (matrix[i-1][k]+matrix[i-1][k-1])%MOD;
    }else{
        if(v[i]==1) matrix[i][1] = (matrix[i-1][1]+matrix[i-1][2])%MOD;
        else if(v[i]==k) matrix[i][k] = (matrix[i-1][k]+matrix[i-1][k-1])%MOD;
        else{
            matrix[i][v[i]] = (matrix[i-1][v[i]]+matrix[i-1][v[i]+1]+matrix[i-1][v[i]-1])%MOD;

        }
    }
}

if(v[n-1]){
    cout << matrix[n-1][v[n-1]];
}else{
    unsigned int  ans=0;
    for(int i=1;i<=100;i++){
        ans+= matrix[n-1][i];
        ans%=MOD;
    }
    cout << ans;
}
}
