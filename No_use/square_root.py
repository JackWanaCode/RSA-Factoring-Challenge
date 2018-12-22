def root(num):
    root = 0;
    bit = num;
    trial = 0;

    # print(num);

    while bit > 0:
        trial = root + bit
        if (trial * trial <= num):
            root += bit
        bit >>= 1
    # print("in root", root)
    return root

def check_prime(n):
    num = n
    sum = 0
    i = 0
    if (num % 10 == 5):
        return 0
    while (num > 0):
        sum += num % 10
        num /= 10
    if sum == 3:
        return 0

    i = root(n);
    if i % 2 == 0:
        i += 1
    if (n == 2):
        return 0
    while (i > 2):
        if (n % i == 0):
            return i
        i -= 2
    return 0

def prime_ret(n):
    num = root(n)
    temp = 2
    temp2 = 0
    # print(num)
    while(temp <= num):
        if (n % temp == 0):
            temp2 = check_prime(temp)
            if temp2 == 0:
                # print(temp)
                return temp
        else:
            if temp == 2:
                temp += 1
            else:
                temp += 2

def readfile(filename=""):
    num = 81
    root_num = 0
    print(num)
    root_num = prime_ret(num)
    print("{}={}*{}".format(num, (num // root_num), root_num))

readfile("./tests/test00")
