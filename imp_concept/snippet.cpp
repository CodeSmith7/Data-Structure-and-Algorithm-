// 1. Count set bits (popcount)
bitset<32> b(n);
int cnt = b.count();  // same as __builtin_popcount(n)

// 2. Check if power of 2
bitset<32> b(n);
bool isPow2 = (b.count() == 1);

// 3. Sieve of Eratosthenes
bitset<1000001> isPrime;
isPrime.set();       // all 1s
isPrime[0] = isPrime[1] = 0;
for (int i = 2; i * i <= 1000000; i++)
    if (isPrime[i])
        for (int j = i*i; j <= 1000000; j += i)
            isPrime[j] = 0;
