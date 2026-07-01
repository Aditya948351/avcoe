# 🧩 Part 1: Environment Setup & Library Imports

## Objective
Before any data analysis or ML modeling, ensure your environment is correctly configured and dependencies are installed.

### Step 1: Install Required Libraries
Run the following command in your **Anaconda Prompt**:

```bash
conda install pandas matplotlib seaborn numpy scikit-learn
```

### Step 2: Import Required Libraries
```python
import pandas as pd                # Data manipulation
import matplotlib.pyplot as plt     # Data visualization
import seaborn as sns               # Advanced plotting
sns.set_style("whitegrid")          # Modern grid-style visuals
plt.style.use("fivethirtyeight")    # Clean, minimalist chart aesthetics
```

### Explanation
- **Pandas** → handles data like Excel sheets (reading, cleaning, transforming).  
- **Matplotlib** → standard for charts & visual storytelling.  
- **Seaborn** → enhances visual clarity using statistical plots.  
- Styling ensures a consistent and professional visual theme.
