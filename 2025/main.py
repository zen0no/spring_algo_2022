for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]


    #Вычисляем количество боёв по формуле
    m = n // k
    
    n_1 = m * k

    sum1 = k * m * (n_1 - m) // 2
    sum2 = (n - n_1) * (n_1 - m)
    sum3 = (n - n_1) * (n - n_1 - 1) // 2
    print(sum1 + sum2 + sum3)