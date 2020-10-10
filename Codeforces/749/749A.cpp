#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,k;
cin >> n;
k = n/2;
cout << k << "\n";
for(int i=0;i<(k-1);i++){
    cout << 2 << " ";
}
if(n%2) cout << 3;
else cout << 2;
}
