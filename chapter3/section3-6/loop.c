long fact_do(long n) {
    long result = 1;
    do {
        result *= n;
        n = n-1;
    } while (n > 1);
    return result;
}

long fact_while(long n) {
    long result = 1;
    while (n > 1) {
        result *= n;
        n = n-1;
    }
    return result;
}

long fact_for(long n) {
    long result = 1;
    for (long i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
