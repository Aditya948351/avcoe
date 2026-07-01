# 🧩 Part 2: Data Loading & Exploration

## Step 1: Load Dataset
```python
df = pd.read_csv("Admission_Predict.csv")
df.head()
```

> ✅ Ensure your dataset `Admission_Predict.csv` is in the same directory or specify its full path.

## Step 2: Inspect Dataset
```python
df.info()
print("Size of dataset is :", df.size)
print("Shape of dataset is :", df.shape)
```

### Explanation
- **`.info()`** → shows data types and null counts.
- **`size`** → total elements (rows × columns).
- **`shape`** → gives dataset dimensions `(rows, columns)`.
