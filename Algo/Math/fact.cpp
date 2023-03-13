//some routines of factorization up to 10^12

//all divs
vector<ll> divs;
for(ll i = 1; i*i <= n; i++){
    if(!(n%i)){
        divs.push_back(i);
        if(i*i != n) divs.push_back(n/i);
    }
}
sort(divs.begin(), divs.end());
//factorize
vector<pair<ll,ll>> facts;
ll aux2 = n;
for(ll i = 2; i*i <= n; i++){
    ll aux = 1, cnt = 0;
    while(!(aux2%(aux*i))) aux *= i, cnt++;
    if(cnt){
        facts.push_back({i, cnt});
    }
    aux2 /= aux;
}
if(aux2 != 1) facts.push_back({aux2,1});
