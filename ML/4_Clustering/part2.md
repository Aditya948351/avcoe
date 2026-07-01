# 🧩 Part 2: Load and Inspect Dataset

## Step 1: Load Dataset
```python
mall_data = pd.read_csv("Mall_Customers.csv")
mall_data.head()
```

## Step 2: Basic Info
```python
mall_data.info()
```

### 🧾 Explanation
- Displays dataset’s structure: number of rows, columns, and data types.  
- Helps confirm successful data loading and reveals if preprocessing is required.
