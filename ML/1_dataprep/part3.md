# ❤️ Part 3: Statistical Summary & Data Types

## Step 1: Statistical Summary
```python
print(df.describe())
print(df.head())
```

### 🧮 Explanation
- `.describe()` provides quick stats: mean, std, min, max, quartiles.  
- Helps understand feature ranges and identify outliers.

## Step 2: Data Type Distribution
```python
print("Data Type for Each Columns are\n", df.dtypes.value_counts())
df.dtypes == 'object'
n = df.columns[df.dtypes != 'object']
df[n]
```

### 💡 Explanation
- Counts how many columns are **numeric** vs **categorical**.
- Numeric columns (`n`) are crucial for correlation and ML modeling.
