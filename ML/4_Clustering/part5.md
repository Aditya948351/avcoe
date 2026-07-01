# 🧮 Part 5: Building and Training K-Means Model

## Step 1: Train KMeans Model
```python
kmeans = KMeans(n_clusters=5, init='k-means++', random_state=0)
y = kmeans.fit_predict(X)
```
### 💡 Explanation
- Creates 5 clusters based on Age, Income, and Spending.  
- Each customer gets a **label (0–4)** based on cluster assignment.
