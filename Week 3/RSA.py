import random
import math

def isprime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0  # gcd, x, y
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y
    
def mod_inverse(a, m):
    gcd, x, _ = extended_gcd(a, m)
    if gcd != 1:
        return None  # Inverse doesn't exist if a and m are not coprime
    else:
        return x % m  # Ensure the result is positive
    
# Generate a random prime number
def generate_prime(bits=8):
    while True:
        p = random.getrandbits(bits)
        if isprime(p):
            return p
        
# RSA key generation
def generate_keys(bits=8):
    p = generate_prime(bits)
    q = generate_prime(bits)
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 65537
    d = mod_inverse(e, phi)
    return (e, d, n)

# Encryption and Decryption
def encrypt(m, e, n):
    return pow(m, e, n)
def decrypt(c, d, n):
    return pow(c, d, n)

e, d, n = generate_keys()
message = 42
cipher = encrypt(message, e, n)

print(e,d,n)
print("Encrypted:", cipher)
print("Decrypted:", decrypt(cipher, d, n))
