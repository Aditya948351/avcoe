# ❤️ Part 7: Model Training (Logistic Regression & KNN)

## Step 1: Data Splitting
```python
from sklearn.model_selection import train_test_split

X = df.drop('target', axis=1)
y = df.target

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=56)
print(X_train)
```

### ⚙️ Explanation
- Splits dataset into 80% training, 20% testing.
- `random_state` ensures reproducibility.

## Step 2: Logistic Regression Model
```python
from sklearn.linear_model import LogisticRegression

lr_clf = LogisticRegression(solver='liblinear')
lr_clf.fit(X_train, y_train)

print_score(lr_clf, X_train, y_train, X_test, y_test, train=True)
print_score(lr_clf, X_train, y_train, X_test, y_test, train=False)
```

### 💡 Explanation
- Logistic Regression predicts binary outcomes (heart disease or not).  
- `liblinear` solver is optimized for small datasets.

## Step 3: Evaluate Logistic Regression
```python
test_score = accuracy_score(y_test, lr_clf.predict(X_test)) * 100
train_score = accuracy_score(y_train, lr_clf.predict(X_train)) * 100

results_df = pd.DataFrame(data=[["Logistic Regression", train_score, test_score]], 
                          columns=['Model', 'Training Accuracy %', 'Testing Accuracy %'])
results_df
```

## Step 4: K-Nearest Neighbors (KNN)
```python
from sklearn.neighbors import KNeighborsClassifier

knn_clf = KNeighborsClassifier()
knn_clf.fit(X_train, y_train)

print_score(knn_clf, X_train, y_train, X_test, y_test, train=True)
print_score(knn_clf, X_train, y_train, X_test, y_test, train=False)

test_score = accuracy_score(y_test, knn_clf.predict(X_test)) * 100
train_score = accuracy_score(y_train, knn_clf.predict(X_train)) * 100

results_df_2 = pd.DataFrame(data=[["K-nearest neighbors", train_score, test_score]], 
                          columns=['Model', 'Training Accuracy %', 'Testing Accuracy %'])
results_df = results_df.append(results_df_2, ignore_index=True)
results_df
```

### 📊 Explanation
- **KNN**: simple distance-based classifier.
- Compares accuracy of Logistic Regression vs. KNN to identify best model for heart disease prediction.
