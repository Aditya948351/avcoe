# 🧩 Part 6: Train-Test Split & Model Building

## Step 1: Split Dataset
```python
from sklearn.model_selection import train_test_split

X = dataset.drop('target', axis=1)
y = dataset.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
```

## Step 2: Build Decision Tree Model
```python
from sklearn.tree import DecisionTreeClassifier

tree_clf = DecisionTreeClassifier(random_state=42)
tree_clf.fit(X_train, y_train)
```

### Explanation
- **Train-test split** ensures model generalization — training on 80% data, testing on 20%.
- **Decision Tree** is a non-linear model ideal for interpretability and small datasets.
- Random seed (42) ensures reproducibility.
