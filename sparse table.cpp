const int MOD = 1e9 + 7;
const int N = 1e5+5;
const int lg = 20;
ll sp[N][lg];
ll a[N],n;
// for any operation $ where x $ x = x, you can make a sparse table to answer quereies for it
void pre(){
    for (int i = 0; i < lg; ++i) {
        for (int j = 0; j + (1 << i) - 1 < n; ++j) {
            if(!i){
                sp[j][i] = a[j];
                continue;
            }
            if(j + (1 << (i-1)) < N)
                sp[j][i] = gcd(sp[j][i-1],sp[j + (1 << (i-1))][i-1]);
        }
    }
}

ll query(ll l, ll r){
    ll k = 31 - __builtin_clz(r-l+1);
    return gcd (sp[l][k],sp[r - (1 << k) + 1][k]);
}
