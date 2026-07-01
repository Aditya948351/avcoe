# 🌡️ Part 4: Data Preparation for Model

## Step 1: Split Independent & Dependent Variables
```python
X = dataset['JAN'].values.reshape(-1, 1)
y = dataset['FEB'].values.reshape(-1, 1)
```

### 💡 Explanation
- `X` (independent) → January temperatures.  
- `y` (dependent) → February temperatures.  
- `.reshape(-1, 1)` ensures correct format for sklearn models.

## Step 2: Split into Train & Test Sets
```python
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)
```

### ⚙️ Explanation
Splits dataset — 80% for training, 20% for testing, ensuring model generalization.
