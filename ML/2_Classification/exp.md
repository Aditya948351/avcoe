# -----------------------------------------------------------
# 🧠 EXPLANATION OF THE CODE
# -----------------------------------------------------------
# 1. Libraries imported:
#    - pandas: Used for loading and handling the dataset.
#    - matplotlib.pyplot & seaborn: Used for data visualization and setting visual styles.
#    - sklearn: Used for preprocessing, splitting data, and building the Decision Tree model.
#
# 2. Dataset loading:
#    - The dataset 'Admission_Predict.csv' is loaded using pandas.
#    - .head(), .info(), .describe(), .shape, and .size are used to understand its structure.
#
# 3. Data preprocessing:
#    - Checked the datatype of each column and identified numeric columns.
#    - Checked for missing values and calculated the total and percentage of missing data.
#
# 4. Feature scaling:
#    - Scaled 'GRE Score' and 'CGPA' using StandardScaler to normalize values for better model performance.
#
# 5. Splitting dataset:
#    - Data is divided into training (80%) and testing (20%) subsets using train_test_split.
#    - X contains input features, and y contains the target variable.
#
# 6. Model building:
#    - A DecisionTreeClassifier model is created and trained on the training dataset.
#
# 7. Evaluation:
#    - The function 'print_score' calculates and prints the accuracy, confusion matrix, and classification report
#      for both training and testing datasets.
#    - Accuracy scores for training and testing are displayed at the end.
#
# 8. Output:
#    - Displays all important details: dataset summary, model performance, and metrics.
#
# -----------------------------------------------------------
# ⚙️ HOW TO INSTALL REQUIRED LIBRARIES (Run these in Anaconda Prompt or Terminal)
# -----------------------------------------------------------
# conda install pandas matplotlib seaborn numpy scikit-learn
# or (if using pip)
# pip install pandas matplotlib seaborn numpy scikit-learn
#
# -----------------------------------------------------------
# 💡 NOTE:
# - Ensure 'Admission_Predict.csv' is in the same directory as your Python file.
# - Replace 'target' with the actual name of your dependent variable column (e.g., 'Chance of Admit').
# - You can run each section in Spyder using F9.
# -----------------------------------------------------------