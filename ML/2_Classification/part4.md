# 🧩 Part 4: Missing Values Analysis

## Step 1: Identify Missing Data
```python
print("Missing values in numeric columns:\n", df[n].isnull())
print("Total Missing Values per Column:\n", df[n].isnull().sum().sort_values(ascending=False))
print("Percentage of Missing Values:\n", df[n].isnull().sum().sort_values(ascending=False) / len(df))
```

### Explanation
- Missing data can bias results if not handled.
- We check **total** and **percentage** of missing values to decide if imputation or removal is necessary.
- Datasets with <5% missing data are usually fine after mean/median imputation.
