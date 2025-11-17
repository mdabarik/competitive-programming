int mx = 3*1e3 + 123;
vector<bool> prime(mx+123, true);
vector<int> primeNum;

void primeGeneration() {
    prime[0] = prime[1] = false;

    // Remove even numbers (except 2)
    for (int i = 4; i <= mx; i += 2) {
        prime[i] = false;
    }

    int sq = sqrt(mx);
    for (int i = 3; i <= sq; i += 2) {
        if (prime[i]) {
            // j starts from i*i and jumps 2*i (only odd multiples)
            for (int j = i * i; j <= mx; j += 2 * i) {
                prime[j] = false;
            }
        }
    }

    // Collect primes (skip evens)
    primeNum.push_back(2);
    for (int i = 3; i <= mx; i += 2) {
        if (prime[i]) primeNum.push_back(i);
    }
}
