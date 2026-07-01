# ❤️ Part 4: Missing Values & Data Quality Checks

## Step 1: Check for Null Values
```python
print("", df[n].isnull())
df[n].isnull().sum().sort_values(ascending=False)
df[n].isnull().sum().sort_values(ascending=False)/len(df)
```

### ⚠️ Explanation
- Identifies missing or null values.
- Displays both total and percentage missing per column.
- Helps decide whether to impute or drop certain records.
