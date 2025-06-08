def encryption(text,key):
    output =""
    result = ""
    for c in text:
        if c.isupper():
            result += chr((ord(c) - 65 + key) % 26 + 65)
        elif c.islower():
            result += chr((ord(c) - 97 + key) % 26 + 97)
        else:
            result += c
    print(result)

text = input("Enter text: ")
key = int(input("Enter Key: "))
choice = input("What do you want to do? E/D :")

if choice=='E':
    encryption(text,key)
elif choice=='D':
    encryption(text,-key)
else:
    print("Enter Valid Choice !")
