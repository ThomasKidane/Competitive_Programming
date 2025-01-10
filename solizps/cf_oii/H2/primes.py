import sympy
import random

def generate_random_primes(count, lower_bound, upper_bound):
    primes = set()
    while len(primes) < count:
        # Generate a random number within the specified range
        candidate = random.randint(lower_bound, upper_bound)
        # Check if the candidate is prime
        if sympy.isprime(candidate):
            primes.add(candidate)
    return sorted(primes)

if __name__ == "__main__":
    COUNT = 500
    LOWER_BOUND = 10**8
    UPPER_BOUND = 10**9

    primes_list = generate_random_primes(COUNT, LOWER_BOUND, UPPER_BOUND)

    # Optionally, write the primes to a file
    with open("500_random_primes.txt", "w") as file:
        for prime in primes_list:
            file.write(f"{prime}\n")

    print(f"Generated {len(primes_list)} prime numbers between {LOWER_BOUND} and {UPPER_BOUND}.")
    print("The primes have been saved to '500_random_primes.txt'.")
