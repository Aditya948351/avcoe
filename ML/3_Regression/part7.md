# 🌡️ Part 7: Model Evaluation

## Step 1: Evaluate Performance
```python
print('Mean absolute error is:', metrics.mean_absolute_error(y_test, y_pred))
print('Mean squared error is:', metrics.mean_squared_error(y_test, y_pred))
print('Root mean squared error is:', np.sqrt(metrics.mean_squared_error(y_test, y_pred)))
```

### 📊 Explanation
- **MAE (Mean Absolute Error)** → average absolute difference between predictions & actual values.  
- **MSE (Mean Squared Error)** → penalizes larger errors more heavily.  
- **RMSE (Root Mean Squared Error)** → interpretable in same units as temperature.
