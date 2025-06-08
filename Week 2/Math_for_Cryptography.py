def findGCD(a, b):
    if a == 0:
        return b
    return findGCD(b % a, a)

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0  # gcd, x, y
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y
    
def modulo(a,b):
    return a % b

def mod_inverse(a, m):
    gcd, x, _ = extended_gcd(a, m)
    if gcd != 1:
        return None  # Inverse doesn't exist if a and m are not coprime
    else:
        return x % m  # Ensure the result is positive
    
def is_quadratic_residue(a, n):
    for x in range(n):
        if (x * x) % n == a % n:
            return x
    return 0

def legendre_symbol(a, p):

    a = a % p  

    if a == 0:
        return 0
    elif pow(a, (p - 1) // 2, p) == 1:
        return 1
    else:
        return -1

def tonelli_shanks(a, p):
    if legendre_symbol(a, p) != 1:
        return None

    if p % 4 == 3:
        x = pow(a, (p + 1) // 4, p)
        return x

    q, s = p - 1, 0
    while q % 2 == 0:
        q //= 2
        s += 1

    z = 2
    while legendre_symbol(z, p) != -1:
        z += 1

    c = pow(z, q, p)
    x = pow(a, (q + 1) // 2, p)
    t = pow(a, q, p)
    m = s

    while t != 1:
        i = 1
        temp = pow(t, 2, p)
        while temp != 1:
            temp = pow(temp, 2, p)
            i += 1
            if i == m:
                return None
        b = pow(c, 2 ** (m - i - 1), p)
        x = (x * b) % p
        t = (t * b * b) % p
        c = (b * b) % p
        m = i

    return x

def chinese_remainder_theorem(a, m):
    M = 1
    for mod in m:
        M *= mod

    x = 0
    for ai, mi in zip(a, m):
        Mi = M // mi
        yi = mod_inverse(Mi, mi)
        x += ai * Mi * yi

    return x % M
