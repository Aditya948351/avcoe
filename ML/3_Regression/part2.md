# 🌡️ Part 2: Load and Inspect Dataset

## Step 1: Load the Dataset
```python
dataset = pd.read_csv(r"C:\Users\Hp\OneDrive\Desktop\lp-1\temperatures.csv")
```

## Step 2: Inspect Data Shape and Stats
```python
print(dataset.shape)
print(dataset.describe())
```

### 🧩 Explanation
- `.shape` → gives number of rows and columns.  
- `.describe()` → provides mean, std, min, and max — useful for data understanding.
