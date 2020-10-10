#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
vector<int> some_primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void init(){

}


int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
char indexes[1005];
vector<int> nums;
int n,aux,cont=0;
cin >> n;
for(int i=0;i<n;i++){
    cin >> aux;
    nums.push_back(aux);
}
for(int i=0;i<(n-1);i++){
    if(__gcd(nums[i],nums[i+1])!=1){
        indexes[i]=true;
        cont++;
    }else indexes[i]=false;
}
indexes[n-1] =false;
cout << cont << endl;
for(int i=0;i<n;i++){
    cout << nums[i] << " ";
    if(indexes[i]){
        for(int j=0;j<some_primes.size();j++){
            int u = __gcd(some_primes[j],nums[i]);
            int v = __gcd(some_primes[j],nums[i+1]);
            if (u==1 && v==1){
                cout << some_primes[j] << " ";
                break;
            }
        }
    }
}

}
