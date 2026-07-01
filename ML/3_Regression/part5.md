# 🌡️ Part 5: Model Training and Prediction

## Step 1: Train Linear Regression Model
```python
model = LinearRegression()
model.fit(X_train, y_train)
```

## Step 2: View Model Parameters
```python
print('Intercept is :', model.intercept_)
print('Coefficient is :', model.coef_)
```

### 💡 Explanation
- **Intercept** → base temperature value when JAN = 0.  
- **Coefficient** → slope showing how much FEB changes per 1°C change in JAN.

## Step 3: Predict Using Test Set
```python
y_pred = model.predict(X_test)
df = pd.DataFrame({'Actual': y_test.flatten(), 'Predicted': y_pred.flatten()})
print(df)
```
