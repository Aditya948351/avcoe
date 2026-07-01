# 📊 Part 3: Exploratory Data Analysis (EDA)

## Step 1: Correlation Heatmap
```python
corr = mall_data.corr(numeric_only=True)
plt.figure(figsize=(8,8))
sns.heatmap(corr, cbar=True, square=True, fmt='.1f', annot=True, cmap='Reds')
```
### 💬 Explanation
Visualizes correlation between numerical columns — higher correlation indicates stronger relationships.

## Step 2: Gender Distribution
```python
plt.figure(figsize=(10,10))
sns.countplot(x="Gender", data=mall_data)
```
### 💡 Explanation
Shows which gender shops more often — identifies demographic trends.

## Step 3: Age Distribution
```python
plt.figure(figsize=(16,10))
sns.countplot(x="Age", data=mall_data)
```
### 🧠 Explanation
Highlights age groups contributing most to mall purchases.

## Step 4: Income vs Spending
```python
plt.figure(figsize=(20,8))
sns.barplot(x='Annual Income (k$)', y='Spending Score (1-100)', data=mall_data)
```
### 💸 Explanation
Analyzes whether higher income implies higher spending — helps reveal luxury vs budget shoppers.
