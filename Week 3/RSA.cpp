#include <iostream>
#include <cmath>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Fast modular exponentiation: (base^exp) % mod
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Extended Euclidean Algorithm to find modular inverse
int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = t - quotient * newt;
        t = newt;
        newt = temp;
        temp = r - quotient * newr;
        r = newr;
        newr = temp;
    }
    if (r > 1) return -1;  // inverse does not exist
    if (t < 0) t += phi;
    return t;
}

// Check if number is prime (naive)
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    // Step 1: Select two prime numbers
    int p = 17, q = 11;
    if (!isPrime(p) || !isPrime(q) || p == q) {
        cout << "Invalid primes\n";
        return 1;
    }

    // Step 2: Compute n and phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose public key exponent e
    int e = 7;  // commonly used value
    if (gcd(e, phi) != 1) {
        cout << "e is not coprime with phi(n)\n";
        return 1;
    }

    // Step 4: Compute private key exponent d
    int d = modInverse(e, phi);
    if (d == -1) {
        cout << "Modular inverse of e does not exist\n";
        return 1;
    }

    // Output public and private keys
    cout << "Public Key: (e = " << e << ", n = " << n << ")\n";
    cout << "Private Key: (d = " << d << ", n = " << n << ")\n";

    // Step 5: Encrypt a message
    int message;
    cout << "\nEnter message to encrypt (as number < " << n << "): ";
    cin >> message;
    if (message >= n) {
        cout << "Message must be less than n\n";
        return 1;
    }

    int encrypted = modExp(message, e, n);
    cout << "Encrypted Message: " << encrypted << "\n";

    // Step 6: Decrypt the message
    int decrypted = modExp(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << "\n";

    return 0;
}
