# 🌡️ Part 3: Data Visualization

## Step 1: Scatter Plot — January vs February
```python
dataset.plot(x='JAN', y='FEB', style='o')
plt.title('JAN vs FEB')
plt.xlabel('mintemp')
plt.ylabel('maxtemp')
plt.show()
```

### 💡 Explanation
Scatter plots reveal correlation and relationship strength between January and February temperatures.

## Step 2: Distribution Plot for February
```python
plt.figure(figsize=(15, 10))
plt.tight_layout()
seaborn.distplot(dataset['FEB'])
plt.show()
```

### 📊 Explanation
This histogram with a kernel density curve shows how February temperatures are distributed — helps check normality.
