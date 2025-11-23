
def linear_search(arr, target):
    for i in range(len(arr)): # Iterate through the array
        if arr[i] == target: # If the target is found
            return i # Return its index
    return -1 # Target not found

# Test the function

arr = [10, 20, 30, 40, 50]
target = 30
print(f"Target {target} found at index: {linear_search(arr, target)}")