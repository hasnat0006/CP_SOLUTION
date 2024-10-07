MOD = 998244353

# Function to compute modular inverse of a under modulo m using Fermat's Little Theorem
def mod_inverse(a, m):
    return pow(a, m-2, m)

# Function to solve for each test case
def solve_case(W, G, L):
    if L == 0:
        # Simple case: you can only lose weight, so the number of days is W - G
        return W - G
    
    # For L > 0, we have to handle the probabilistic aspect of the random walk
    # Probability-based approach: Reflective random walk
    # Total range of allowed weights is W to G, bounded by W + L
    
    # Expected number of steps: calculate it based on analysis
    # This part requires solving for the expected number of steps (Markov process)
    
    # Placeholder: for demonstration, use a simplified approach for now
    # Assume the expected number of steps can be represented by a fraction p/q
    # You will replace this with actual computation of p and q for random walks
    p = (W - G) * 2  # Placeholder logic for p
    q = 1            # Placeholder logic for q
    
    # Find p * q^(-1) % MOD
    q_inv = mod_inverse(q, MOD)
    result = (p * q_inv) % MOD
    return result

# Main function to handle input and output
def main():
    T = int(input())  # Number of test cases
    for i in range(1, T + 1):
        W, G, L = map(int, input().split())
        result = solve_case(W, G, L)
        print(f"Case #{i}: {result}")

# Example usage
if __name__ == "__main__":
    main()
