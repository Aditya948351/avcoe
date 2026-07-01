# 🧩 Part 3: Statistical & Data Type Analysis

## Step 1: Statistical Summary
```python
print(df.describe())
print(df.head())
```

## Step 2: Data Type Insights
```python
print("Data Type for Each Column:\n", df.dtypes.value_counts())
n = df.columns[df.dtypes != 'object']
df[n]
```

### Explanation
- **Descriptive stats** reveal distribution (mean, std, min, max).
- **Data types** confirm which features are numeric (vital for ML algorithms).
- Helps decide which columns may need scaling or encoding later.
