#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
long long int n,k,sqroot;
char isqrt = false;
vector<long long int> divisors;
cin >> n >> k;
sqroot = (long long int)(sqrt(n)+0.01);
if(sqroot*sqroot == n) isqrt = true;

for(int i=1;i<=sqroot;i++){
    if(!(n%i)) divisors.push_back(i);
}
if(k<=divisors.size()) cout << divisors[k-1];
else if(k<(2*divisors.size())){
    long long int fac = 0;
    if(isqrt) fac = 1;
    cout << n/divisors[ 2*divisors.size()-k -fac ];
}else if(k==(2*divisors.size()) && !isqrt){
    cout << n;
}else cout << -1;
}
