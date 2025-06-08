def encryption(plaintext,keyword):
    plaintext=plaintext.upper()
    keyword=keyword.upper()
    ciphertext = ""
    key_len=len(keyword)
    for i in range(len(plaintext)):
        if plaintext[i].isalpha():
            p_index = ord(plaintext[i])-65
            k_index= ord(keyword[i%key_len])-65
            c_index=(p_index+k_index)%26
            ciphertext += chr(c_index + 65)
        else:
            ciphertext+=plaintext[i]
    print(ciphertext)

def decryption(ciphertext,keyword):
    ciphertext=ciphertext.upper()
    keyword=keyword.upper()
    plaintext = ""
    key_len=len(keyword)
    for i in range(len(ciphertext)):
        if ciphertext[i].isalpha():
            c_index = ord(ciphertext[i])-65
            k_index= ord(keyword[i%key_len])-65
            p_index=(c_index-k_index+26)%26
            plaintext += chr(p_index + 65)
        else:
            plaintext+=ciphertext[i]
    print(plaintext)

text = input("Enter text: ")
keyword = input("Enter Keyword: ")
choice = input("What do you want to do? E/D :")

if choice=='E':
    encryption(text,keyword)
elif choice=='D':
    decryption(text,keyword)
else:
    print("Enter Valid Choice !")

