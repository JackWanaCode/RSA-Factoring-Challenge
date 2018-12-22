def root(num):
    root = 0;
    bit = num;
    trial = 0;

    # print(num);

    while bit > 0:
        trial = root + bit
        # print("trial is", trial)
        if (trial * trial <= num):
            # print("root is", root)
            root += bit
        # print("bit is", bit)
        bit >>= 1
    if ((root + 1) * (root + 1) == num):
        root += 1
    return root

def readfile(filename=""):
    num = 4
    root_num = root(num)
    print(num, root_num)
    num = 9
    root_num = root(num)
    print(num, root_num)
    num = 16
    root_num = root(num)
    print(num, root_num)
    num = 25
    root_num = root(num)
    print(num, root_num)
    num = 36
    root_num = root(num)
    print(num, root_num)
    num = 49
    root_num = root(num)
    print(num, root_num)
    num = 64
    root_num = root(num)
    print(num, root_num)
    num = 81
    root_num = root(num)
    print(num, root_num)

readfile("./tests/test00")
