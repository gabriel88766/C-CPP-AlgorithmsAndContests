#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,m;
    cin >> n >> m;
    if(m != 1) cout << (m-1)*n;
    else cout << n-1;
}