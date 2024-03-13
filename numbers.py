import random

numbers = random.sample(range(-500, 500), 100)
sequence = ' '.join(str(num) for num in numbers)

print(sequence)