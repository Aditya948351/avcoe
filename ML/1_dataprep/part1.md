# ❤️ Part 1: Environment Setup & Library Imports

## Objective
Prepare the working environment and import all required libraries for heart disease data analysis.

### 🧰 Step 1: Install Required Libraries
Run this in **Anaconda Prompt** before opening Spyder:
```bash
conda install pandas matplotlib seaborn numpy scikit-learn
```

### 🧠 Step 2: Import Libraries
```python
import pandas as pd                # Handles data loading, cleaning, and analysis
import matplotlib.pyplot as plt     # For plotting and data visualization
import seaborn as sns               # Provides advanced visualization tools
import numpy as np                  # For numerical computations
import statistics as s              # To perform basic statistical operations (mean, mode, etc.)
```

### 🎨 Step 3: Configure Plot Aesthetics
```python
sns.set_style("whitegrid")          # Gives charts a clean, grid-based appearance
plt.style.use("fivethirtyeight")    # Applies a professional visual theme
```

### 💡 Explanation
- **pandas**: Essential for structured data manipulation.
- **matplotlib**: Foundation for all plots.
- **seaborn**: Built on matplotlib, provides heatmaps and complex visualizations.
- **numpy**: Optimized for fast numerical operations.
- **statistics**: Useful for simple, descriptive statistical calculations.
