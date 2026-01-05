#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
//matrix vector<vector<int>> matrix(row,vector<int>(col))

using namespace std;

int gcd(int a,int b){
    if(!(a&&b)) return a|b;
    else return gcd(b,a-b*(a/b));

}

int primes[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

void ffactors(vector<int> &v,vector <int> &di, int n){
    v.reserve(15);
    for(int i=0;i<15;i++){
        v[i]=0;
    }
    for(int i=0;i<15;i++){
        int k=n;
        while(!(k%primes[i])){
            k/=primes[i];
            v[i]++;
        }
    }
    di.push_back(1);
    for(int i=2;i<=50;i++){
        int curi = i;
        for(int j=0;j<15;j++){
            int rep = v[j];
            while(rep&&(curi%primes[j]==0)){
                curi/=primes[j];
                rep--;
            }
        }
        if(curi==1){
            di.push_back(i);
        }
    }


}


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int t,n,a,b,maxd,compd,begins,ends;
vector <int> factors;
vector <int> divisors;
cin >> t;

for(int i=0;i<t;i++){
    cin >> n >> a >> b;
    ffactors(factors,divisors,b-a);
    for(int i=0;i<divisors.size();i++){
        if( (n-1) >= divisors[i] ) maxd=divisors[i];
    }
    compd = (b-a)/maxd;
    int rem = n-(maxd+1);
    if(rem==0){
        begins = a;
        ends = b;
    }else{
        bool flag=true;
        int cura= a;
        while(rem&&flag){
            if((cura - compd)>=1){
                rem--;
                cura-=compd;
            }else  flag=false;
        }
        begins=cura;
        ends=b+rem*compd;
    }
    while(ends!=begins){
        cout << begins << " ";
        begins+=compd;
    }
    cout << ends << endl;
}


}
 