def count_1543_in_layers(n, m, carpet):
    target = "1543"
    occurrences = 0
    layers = min(n, m) // 2  # Number of layers

    for layer in range(layers):
        # Initialize the boundaries of the current layer
        top, bottom = layer, n - layer - 1
        left, right = layer, m - layer - 1
        
        # Collect numbers in clockwise order for the current layer
        sequence = []

        # Top row, left to right
        for j in range(left, right + 1):
            sequence.append(carpet[top][j])

        # Right column, top to bottom (skip the first corner)
        for i in range(top + 1, bottom + 1):
            sequence.append(carpet[i][right])

        # Bottom row, right to left (skip the first corner)
        if bottom > top:  # Ensure we have a distinct bottom row
            for j in range(right - 1, left - 1, -1):
                sequence.append(carpet[bottom][j])

        # Left column, bottom to top (skip the first corner)
        if left < right:  # Ensure we have a distinct left column
            for i in range(bottom - 1, top, -1):
                sequence.append(carpet[i][left])

        # Convert the sequence to a string and count occurrences of "1543"
        sequence_str = ''.join(sequence)
        occurrences += sequence_str.count(target)
    
    return occurrences

# Input and output handling
t = int(input())
results = []
for _ in range(t):
    n, m = map(int, input().split())
    carpet = [input().strip() for _ in range(n)]
    results.append(count_1543_in_layers(n, m, carpet))

print("\n".join(map(str, results)))
