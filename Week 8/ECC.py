# Elliptic curve parameters over F_p
class Curve:
    def __init__(self, a, b, p):
        self.a = a  # coefficient a
        self.b = b  # coefficient b
        self.p = p  # prime field p

        # Ensure the curve is non-singular
        if (4 * a**3 + 27 * b**2) % p == 0:
            raise ValueError("Singular curve!")

    def is_on_curve(self, point):
        if point is None:
            return True  # Point at infinity
        x, y = point
        return (y**2 - (x**3 + self.a*x + self.b)) % self.p == 0

def inverse_mod(k, p):
    """Returns the modular inverse of k modulo p."""
    return pow(k, -1, p)  

def point_add(P, Q, curve):
    """Adds two points P and Q on the elliptic curve."""
    if P is None: return Q
    if Q is None: return P

    x1, y1 = P
    x2, y2 = Q
    p = curve.p

    if x1 == x2 and y1 != y2:
        return None  # Point at infinity

    if P == Q:
        # Point doubling
        m = (3 * x1 * x1 + curve.a) * inverse_mod(2 * y1, p)
    else:
        # Point addition
        m = (y2 - y1) * inverse_mod(x2 - x1, p)

    m %= p
    x3 = (m * m - x1 - x2) % p
    y3 = (m * (x1 - x3) - y1) % p
    return (x3, y3)

def scalar_mult(k, P, curve):
    """Performs scalar multiplication k * P."""
    result = None  # Start with point at infinity
    addend = P

    while k:
        if k & 1:
            result = point_add(result, addend, curve)
        addend = point_add(addend, addend, curve)
        k >>= 1

    return result

import random

def generate_keypair(G, curve, n):
    """Generates a private/public key pair."""
    private_key = random.randint(1, n - 1)
    public_key = scalar_mult(private_key, G, curve)
    return private_key, public_key

if __name__ == "__main__":
    # Define curve
    p = 17
    a, b = 2, 2
    curve = Curve(a, b, p)

    # Base point G on the curve
    G = (5, 1)

    # Check that G is on the curve
    assert curve.is_on_curve(G)

    # Generate key pair
    private_key, public_key = generate_keypair(G, curve, n=19)

    print("Private key:", private_key)
    print("Public key: ", public_key)

    # Validate key
    assert curve.is_on_curve(public_key)
    assert scalar_mult(private_key, G, curve) == public_key
