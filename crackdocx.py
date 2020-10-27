import msoffcrypto

found=0
NUMBERS="1234567890"
SYMBOLS="#@%&*"
LOWERCASE="abcdefghijklmnopqrstuvwxyz"
UPPERCASE="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
FILENAME=input("Target filepath : ")
OUTPUT_FILENAME=input("Decrypted file name : ")
MAX_LENGTH=int(input("Maximum length of password : "))
MIN_LENGTH=int(input("Minimum length of password : "))
LEVEL=int(input("Bruteforcing level : "))

file = msoffcrypto.OfficeFile(open(FILENAME, 'rb')) #file path

def Check_Password(password):
    global found
    file.load_key(password=password)
    file.decrypt(open(OUTPUT_FILENAME, "wb"))
    print("\nPassword found : "+password)
    input()
    found=1

def brute(string,Maxlength,Minlength,charset):
    if not found:
        if len(string) == Maxlength:
            return
        for char in charset:
            password = string + char 
            if len(password)>=Minlength and not found:
                print(".",end =" "),
                try:Check_Password(password)
                except:brute(password,Maxlength,Minlength,charset)
            elif found: break 
            else:brute(password,Maxlength,Minlength,charset)


print("Searching",end =" ")
brute("",MAX_LENGTH,MIN_LENGTH,NUMBERS+(SYMBOLS if LEVEL>1 else "")+(LOWERCASE if LEVEL>2 else "")+(UPPERCASE if LEVEL>3 else "") )
