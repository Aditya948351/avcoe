# 🧩 Part 7: Model Evaluation & Summary

## Step 1: Evaluate Model
```python
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

def print_score(clf, X_train, y_train, X_test, y_test, train=True):
    if train:
        pred = clf.predict(X_train)
        clf_report = pd.DataFrame(classification_report(y_train, pred, output_dict=True))
        print("Train Result:\n================================================")
        print(f"Accuracy Score: {accuracy_score(y_train, pred) * 100:.2f}%")
        print(f"Confusion Matrix: \n{confusion_matrix(y_train, pred)}\n")
    else:
        pred = clf.predict(X_test)
        clf_report = pd.DataFrame(classification_report(y_test, pred, output_dict=True))
        print("Test Result:\n================================================")
        print(f"Accuracy Score: {accuracy_score(y_test, pred) * 100:.2f}%")
        print(f"Confusion Matrix: \n{confusion_matrix(y_test, pred)}\n")

print_score(tree_clf, X_train, y_train, X_test, y_test, train=True)
print_score(tree_clf, X_train, y_train, X_test, y_test, train=False)
```

## Step 2: Summary of Results
```python
print("Training Accuracy (%):", accuracy_score(y_train, tree_clf.predict(X_train)) * 100)
print("Testing Accuracy (%):", accuracy_score(y_test, tree_clf.predict(X_test)) * 100)
```

### Explanation
- **Confusion Matrix** visualizes correct vs incorrect classifications.
- **Accuracy** quantifies model performance.
- **Classification Report** shows precision, recall, and F1-scores.
- Overfitting is detected if training accuracy >> testing accuracy.
