int mx = 3*1e3 + 123;
vector<bool> prime(mx+123, true);
vector<int> primeNum;

void primeGeneration() {
    prime[0] = prime[1] = false;
    
    for (int i = 4; i <= mx; i += 2) {
        prime[i] = false;
    }

    int sq = sqrt(mx);
    for (int i = 3; i <= sq; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= mx; j += 2 * i) {
                prime[j] = false;
            }
        }
    }
    primeNum.push_back(2);
    for (int i = 3; i <= mx; i += 2) {
        if (prime[i]) primeNum.push_back(i);
    }
}

vector<int> primeFactors (int n ){
    vector<int> factors;
    for ( auto p : primeNum ) {
        if( 1LL * p * p > n ) break;
        if( n % p == 0 ) {
            while ( n % p == 0 ) {
                factors.push_back(p);
                n /= p;
            }
        }
    }
    if(n > 1) {
        factors.push_back(n);
    }
    return factors;
}
