from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("Clustered2.csv", header=0)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

x = df['Customer ID'].apply(float)      #read column 1 of csv and saves
y = df[' Annual Income'].apply(float)   #read column 4 of csv and saves
z = df[' Speeding Score'].apply(float) #read column 5 of csv and saves
# these are x y z corrdinates these haev been saved in the array

#this is the column with the cluster number
#each numebr has different color
color = df[' Cluster no.'].apply(int)

# builtin command takes x y and z coordinate and also takes the cluster numebr to assign color
ax.scatter(x, y, z, c=color, marker='x')
# its python noone undersands anything someone else made it XD
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()
