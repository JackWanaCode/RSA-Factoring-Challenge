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
    num = 0
    temp = 2
    i = 3
    j = 0

    list_prime = [2, 3]
    check = 1
    if n % 2 == 0:
        print(n)
        return 2
    elif n % 5 == 0:
        return 5
    num = root(n)
    print(num)
    while(list_prime[-1] <= num and j < 300):
        for el in list_prime:
            if n % el == 0:
                print(list_prime)
                return el
        while (i < num):
            i += 2
            check = 1
            for el in list_prime:
                if i % el == 0:
                    check = 0
                    break
            if check == 1:
                list_prime.append(i)
        j += 1
    return 1

def readfile(filename=""):
    num = 0
    root_num = 0
    with open(filename, 'r') as f:
        for line in f:
            num = int(line)
            print(num)
            root_num = prime_ret(num)
            print("{}={}*{}".format(num, (num // root_num), root_num))

readfile("./tests/test00")
