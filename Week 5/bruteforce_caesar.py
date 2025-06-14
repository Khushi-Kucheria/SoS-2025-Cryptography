def caesar_decrypt(ciphertext, shift):
    decrypted = ''
    for char in ciphertext:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            decrypted += chr((ord(char) - base - shift) % 26 + base)
        else:
            decrypted += char
    return decrypted

def brute_force_caesar(ciphertext):
    print("Brute Force Attack Results:")
    for key in range(1, 26):
        attempt = caesar_decrypt(ciphertext, key)
        print(f"Key {key:2}: {attempt}")

# Example Ciphertext (encrypted "THIS IS A SECRET")
ciphertext = "Wklv lv d vhfuhw"
brute_force_caesar(ciphertext)
