# ⚙️ Part 4: Feature Selection for Clustering

## Step 1: Selecting Key Features
```python
X = mall_data.iloc[:, [2, 3, 4]].values
```
### 💡 Explanation
Uses **Age**, **Annual Income**, and **Spending Score** as features — essential for understanding shopping behavior patterns.

## Step 2: Determine Optimal Clusters (Elbow Method)
```python
wcss = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', random_state=50)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)
```

## Step 3: Plot Elbow Graph
```python
sns.set()
plt.plot(range(1, 11), wcss)
plt.xlabel("Number of clusters")
plt.ylabel("WCSS value")
plt.show()
```
### 📉 Explanation
- **WCSS (Within Cluster Sum of Squares)** → measures compactness of clusters.  
- The “elbow point” in the curve shows the optimal cluster count.
