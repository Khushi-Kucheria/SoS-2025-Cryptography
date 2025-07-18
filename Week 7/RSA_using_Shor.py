from math import gcd
from random import randint

def find_period_brute_force(a, N):
    for r in range(1, N):
        if pow(a, r, N) == 1:
            return r
    return None

def shors_classical_sim(N):
    # Step 1: Pick a random a such that gcd(a, N) == 1
    a = randint(2, N - 2)
    while gcd(a, N) != 1:
        a = randint(2, N - 2)
    print(f"Chosen a = {a}")

    # Step 2: Find period r such that a^r mod N = 1
    r = find_period_brute_force(a, N)
    if r is None:
        print("No period found.")
        return

    print(f"Found period r = {r}")

    # Step 3: r must be even
    if r % 2 != 0:
        print("r is odd; try again.")
        return

    # Step 4: Compute a^(r/2)
    x = pow(a, r // 2, N)

    if x == N - 1:
        print("x = -1 mod N; try again.")
        return

    # Step 5: Compute GCDs
    factor1 = gcd(x - 1, N)
    factor2 = gcd(x + 1, N)

    if 1 < factor1 < N:
        print(f"Found factor: {factor1}")
    if 1 < factor2 < N:
        print(f"Found factor: {factor2}")

shors_classical_sim(13529227)