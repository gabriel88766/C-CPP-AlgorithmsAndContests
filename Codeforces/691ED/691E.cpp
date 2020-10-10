#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
const long long int MOD = 1e9+7;

using namespace std;

long long int n;

bool seet(long long int a,long long int b){
    long long int k = a^b;
    int cont=0;
    while(k!=0){
        if(k%2){
            cont++;
        }
        k/=2;
    }
    if(cont%3) return false;
    else return true;
}

void xoruples(vector<long long int> v,vector<vector<long long int>> &matrix, long long int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(seet(v[i],v[j])) matrix[i][j]=1;
            else matrix[i][j]=0;
        }
    }
}

vector<vector<long long int>> multiply(vector<vector<long long int>> mat,vector<vector<long long int>> mat2,int n){
    vector<vector<long long int>> v(n,vector<long long int> (n));
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<n;j++){
            v[i][j]=0;
            for(long long int k=0;k<n;k++){
                v[i][j] += (mat[i][k]*mat2[k][j]);
                v[i][j] = v[i][j]%MOD;
            }
        }
    }
    return v;
}

void fastexp(vector<vector<long long int>> &matrix,long long int n,long long int exp){
    vector<vector<long long int>> res(n,vector<long long int> (n,0));
    for(int i=0;i<n;i++){
        res[i][i]=1;
    }
    while(exp){
        if(exp&1){
            res = multiply(res,matrix,n);
        }
        matrix = multiply(matrix,matrix,n);
        exp/=2;
    }
    matrix = res;
}



long long int sum(vector<vector<long long int>> &mat,int n){
    long long int Sum=0;
    for(long long int i = 0;i<n;i++){
        for(long long int j=0;j<n;j++){
            Sum+=mat[i][j];
            Sum%=MOD;
        }
    }

    return Sum;
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
long long int  k, aux;
cin >> n >> k;
vector<vector<long long int>> matrix(n,vector<long long int>(n)),w(n,vector<long long int>(n));
vector<long long int> numbers;

for(long long int i=0;i<n;i++){
    cin >> aux;
    numbers.push_back(aux);
}


xoruples(numbers,matrix,n);


if(k==1){
    cout << n;
}else{
    fastexp(matrix,n,k-1);

    cout << sum(matrix,n);
}
}


