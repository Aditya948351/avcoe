# ❤️ Part 5: Feature Insights & Visualization

## Step 1: Analyze Key Columns
```python
df['age']
average = s.mean(df['age'])
print("Average age : ", average)
print(df['age'], df['sex'], df['trestbps'], df['chol'])
```

### 🧠 Explanation
- Displays individual feature data like `age`, `sex`, `trestbps`, and `chol`.
- `statistics.mean()` calculates the **average age** of patients.

## Step 2: Correlation Matrix Visualization
```python
corr_matrix = df.corr()
fig, ax = plt.subplots(figsize=(15, 15))
ax = sns.heatmap(corr_matrix, annot=True, linewidths=0.5, fmt=".2f", cmap="YlGnBu")
bottom, top = ax.get_ylim()
ax.set_ylim(bottom + 0.5, top - 0.5)
```

### 🎨 Explanation
- **Correlation Matrix**: shows how strongly features relate to each other.
- **Heatmap**: helps visually identify positive or negative relationships (e.g., cholesterol vs. target).
