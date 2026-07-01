# 🌡️ Part 6: Visualization of Predictions

## Step 1: Compare Actual vs Predicted (Bar Graph)
```python
df1 = df.head(25)
df1.plot(kind='bar', figsize=(16, 10))
plt.grid(which='major', linestyle='-', linewidth='0.5', color='green')
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.show()
```

### 💡 Explanation
Bar charts show model accuracy visually — close bars mean better fit.

## Step 2: Regression Line Visualization
```python
plt.scatter(X_test, y_test, color='gray')
plt.plot(X_test, y_pred, color='red', linewidth=2)
plt.show()
```

### 💬 Explanation
Gray dots → actual values, red line → predicted regression line.
Closer alignment = higher prediction accuracy.
