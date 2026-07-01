# ❤️ Part 2: Data Loading & Initial Exploration

## Step 1: Load the Dataset
```python
df = pd.read_csv(r"C:\Users\Hp\OneDrive\Desktop\lp-1\heart.csv")
df.head()
```

### 🧾 Explanation
This loads the heart disease dataset into a pandas DataFrame and shows the first few records.

## Step 2: View Basic Information
```python
df.info()
print("Size of dataset is :", df.size)
print("Shape of dataset is :", df.shape)
```

### 🧩 Explanation
- `.info()` → displays column types and missing value counts.  
- `.size` → gives total elements (rows × columns).  
- `.shape` → gives dimensions `(rows, columns)`.  
These checks confirm data integrity and completeness.
