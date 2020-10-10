#include <bits/stdc++.h>
using namespace std;

int _pow10[] = { 1, 10 ,100 ,1000, 10000, 100000, 1000000, 10000000};

int main(){
//ios_base::sync_with_stdio(0), cin.tie(0);
int n,k,curdif,mindif = 0x3f3f3f3f;
int v[] = {0,1,2,3,4,5,6,7};
int numbers[8];
vector<string> nums;
string s;
cin >> n >> k;
for(int i=0;i<n;i++){
    cin >> s;
    nums.push_back(s);
}
do{
    for(int i=0;i<n;i++){
        numbers[i]=0;
        for(int j=0; j<k; j++){
            numbers[i] += nums[i][v[j]]*_pow10[j];
        }
    }
    sort(numbers,numbers+n);
    curdif = numbers[n-1] - numbers[0];
    mindif = min(curdif,mindif);
}
while(next_permutation(v,v+k));
cout << mindif;

}


