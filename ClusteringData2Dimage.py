import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('Clustered.csv', header=None)

# Extract the columns for x-axis, y-axis, and color
x = data[1]
y = data[2]
arr = data[3]

color = []
position = 0
for i in data[3]:
    if i == '1':
        color.insert(position, "black")
        position += 1
    elif i == '2':
        color.insert(position, "red")
        position += 1
    elif i == '3':
        color.insert(position, "pink")
        position += 1
    elif i == '4':
        color.insert(position, "purple")
        position += 1
    else:
        color.insert(position, "blue")
        position += 1

# Plot a scatter plot
plt.scatter(x, y, c=color)
plt.show()
