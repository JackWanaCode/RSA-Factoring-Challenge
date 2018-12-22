# def root(num):
#     root = 0;
#     bit = num;
#     trial = 0;
#
#     while bit > 0:
#         trial = root + bit
#         if (trial * trial <= num):
#             root += bit
#         bit >>= 1
#     return root

def loop_to_n(n):
    i = 3;
    check = 1
    list_prime = [2, 3]
    while (i < n):
        i += 2
        check = 1
        for el in list_prime:
            # print(i, el)
            if i % el == 0:
                check = 0
                break
        if check == 1:
            list_prime.append(i)
        # print(i)
    print(list_prime)


loop_to_n(100)
