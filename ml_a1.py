# -*- coding: utf-8 -*-
"""ML-A1.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1J6M3DOs6nw0yDDzS6J9nmxWcWMzDTf4P
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

data = pd.read_csv('https://raw.githubusercontent.com/Tanmay49/SEM7/main/ML/uber.csv')
data.head()

data.info()

data.describe()

df = data.drop(['Unnamed: 0','key','pickup_datetime'],axis = 1)

df.dropna(inplace=True)

sns.boxplot(df['fare_amount'])

low = df['fare_amount'].quantile(0.05)
high = df['fare_amount'].quantile(0.95)
df = df[(df['fare_amount'] > low) & (df['fare_amount'] < high)]
sns.boxplot(df['fare_amount'])

corr = df.corr()
sns.heatmap(corr,annot = True)

from sklearn.model_selection import train_test_split
X = df.drop(['fare_amount'],axis = 1)
y = df['fare_amount']
X_train,X_test,y_train,y_test = train_test_split(X,y)

from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)

from sklearn.metrics import mean_squared_error, r2_score
RMSE = np.sqrt(mean_squared_error(y_test,y_pred))
print("RMSE - > ",RMSE)
R2 = r2_score(y_test,y_pred)
print("R2 - > ",R2)

from sklearn.ensemble import RandomForestRegressor
model = RandomForestRegressor()
model.fit(X_train,y_train)
y_pred = model.predict(X_test)

from sklearn.metrics import mean_squared_error, r2_score
RMSE = np.sqrt(mean_squared_error(y_test,y_pred))
print("RMSE - > ",RMSE)
R2 = r2_score(y_test,y_pred)
print("R2 - > ",R2)
