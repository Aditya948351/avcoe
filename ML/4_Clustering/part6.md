# 📈 Part 6: 3D Visualization of Clusters

## Step 1: Visualize with Matplotlib 3D Scatter Plot
```python
fig = plt.figure(figsize=(10,10))
ax = fig.add_subplot(111, projection='3d')

ax.scatter(X[y == 0,0], X[y == 0,1], X[y == 0,2], s=40, color='red', label='Cluster 1')
ax.scatter(X[y == 1,0], X[y == 1,1], X[y == 1,2], s=40, color='blue', label='Cluster 2')
ax.scatter(X[y == 2,0], X[y == 2,1], X[y == 2,2], s=40, color='green', label='Cluster 3')
ax.scatter(X[y == 3,0], X[y == 3,1], X[y == 3,2], s=40, color='yellow', label='Cluster 4')
ax.scatter(X[y == 4,0], X[y == 4,1], X[y == 4,2], s=40, color='purple', label='Cluster 5')

ax.set_xlabel('Age of a customer-->')
ax.set_ylabel('Annual Income-->')
ax.set_zlabel('Spending Score-->')
ax.legend()
plt.show()
```

### 🧭 Explanation
Displays customers grouped into 3D space — visually showing patterns in spending and income.  
Each color corresponds to a distinct customer segment.
