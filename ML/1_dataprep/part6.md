# ❤️ Part 6: Model Preparation & Helper Functions

## Step 1: Import Evaluation Metrics
```python
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
```

### ⚙️ Explanation
- **accuracy_score** → overall correctness of model.
- **confusion_matrix** → details true/false positives & negatives.
- **classification_report** → shows precision, recall, F1-score.

## Step 2: Define Scoring Function
```python
def print_score(clf, X_train, y_train, X_test, y_test, train=True):
    if train:
        pred = clf.predict(X_train)
        clf_report = pd.DataFrame(classification_report(y_train, pred, output_dict=True))
        print("Train Result:\n================================================")
        print("Accuracy Score: {accuracy_score(y_train, pred) * 100:.2f}%")
        print("Confusion Matrix: \n {confusion_matrix(y_train, pred)}\n")
    elif train==False:
        pred = clf.predict(X_test)
        clf_report = pd.DataFrame(classification_report(y_test, pred, output_dict=True))
        print("Test Result:\n================================================")        
        print("Accuracy Score: {accuracy_score(y_test, pred) * 100:.2f}%")
        print("Confusion Matrix: \n {confusion_matrix(y_test, pred)}\n")
```

### 🧾 Explanation
Encapsulates model evaluation — provides accuracy and confusion matrix for both training and testing datasets.
