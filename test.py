def multiples():
    multiples = 0

    for x in range(1000):
        if x%3 == 0 or x%5 ==0:
            multiples += x

    print(multiples)

def fibonacci():
    num = 4000000
    memo = [1,2]
    accum = 2
    next_n = 0

    while next_n <= num:
        next_n = memo[0] + memo[1]
        
        if next_n % 2 == 0:
            accum += next_n
        
        memo[0] = memo[1]
        memo[1] = next_n

    print(accum)

def largest_prime_factor(n):
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
    return n

print(largest_prime_factor(600851475143))

from functools import reduce
def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
print(factors(40))