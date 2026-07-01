# 🧩 Part 5: Feature Scaling (Normalization)

## Step 1: Copy and Scale Key Columns
```python
dataset = df.copy()

from sklearn.preprocessing import StandardScaler
s_sc = StandardScaler()

col_to_scale = ['GRE Score', 'CGPA']
dataset[col_to_scale] = s_sc.fit_transform(dataset[col_to_scale])
```

### Explanation
- **StandardScaler** standardizes features (mean = 0, variance = 1).  
- Helps models like Decision Trees and SVMs perform consistently.
- Normalization prevents features with large ranges (e.g., GRE vs CGPA) from dominating the model.
