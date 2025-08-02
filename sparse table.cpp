const int N = 1e5+5;
const int lg = 20;
ll sp[N][lg];
ll a[N],n;

void pre(){
    for (int i = 0; i < lg; ++i) {
        for (int j = 0; j + (1 << i) - 1 < n; ++j) {
            if(!i){
                sp[j][i] = a[j];
                continue;
            }
            if(j + (1 << (i-1)) < N)
                sp[j][i] = min(sp[j][i-1],sp[j + (1 << (i-1))][i-1]);
        }
    }
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pre();
    ll q;cin >> q;
    while(q--){
        ll l,r;cin >> l >> r;
        ll k = 31 - __builtin_clz(r-l+1);
        cout << min (sp[l][k],sp[r - (1 << k) + 1][k]) << endl;
    }

}
