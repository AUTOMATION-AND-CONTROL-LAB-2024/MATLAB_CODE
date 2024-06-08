import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
import numpy as np


filename_linear = 'acquisition.xlsx'


def read_data(filename, num_sheet):
    data = []
    for i in range(num_sheet):
        temp_data = pd.read_excel(filename, sheet_name = 'Motor'+str(i+1))
        temp_data = temp_data.dropna(subset= ['THRUST'])
        data.append(temp_data)
    return data

def plot_motor(data, ind):
    x = data['PWM']
    y = data['THRUST']*g*gain
    plt.subplot(2,2,ind)
    plt.plot(x,y,'.')
    plt.xlabel('PWM')
    plt.ylabel('THRUST[N]')
    plt.title('WEIGHT-PWM COEFFICIENT')
    plt.grid()

def plot_motor_array(data):
    fig, axes = plt.subplots(2,2, constrained_layout=True)
    for ind, df in enumerate(data, start = 1):
        plot_motor(df, ind)
    plt.show()
    fig.savefig('plots/motor_array.png')

def plot_motor_comparison(data):
    legend = []
    for ind, df in enumerate(data, start = 1):
        x = df['PWM']
        y = df['PESO']*g*gain
        plt.scatter(x,y)
        plt.xlabel('PWM')
        plt.ylabel('THRUST[N]')
        plt.title('WEIGHT-PWM COEFFICIENT')
        legend.append('Motor'+str(ind))
    plt.legend(legend)
    plt.grid()
    plt.savefig('plots/motor_comparison.png')
    plt.show()
    

def plot_motor_LR(data, ind):
    x = data['PWM']
    y = data['THRUST']
    x = np.array(x).reshape(-1, 1)
    y = np.array(y).reshape(-1, 1)
    model = LinearRegression().fit(x, y)
    score = model.score(x, y)
    X_new = np.array([[100], [900]])
    y_pred = model.predict(X_new)
    K = model.coef_
    plt.plot(x, y,'.')
    plt.plot(X_new, y_pred, color='red', label='Linear Regression')
    plt.xlabel('PWM')
    plt.ylabel('THRUST [N]')
    plt.title('RANSAC REGRESSOR')
    plt.grid()
    plt.show()
    print(K)
    return K[0]

# def plot_motor_array_LR(data):
#     fig, axes = plt.subplots(2,2, constrained_layout=True)
#     list = []
#     for ind, df in enumerate(data, start = 1):
#         list.append(plot_motor_LR(df, ind))
#     #plt.show()
#     df = pd.DataFrame(list, columns = ['K'])
#     df.to_excel(filename_linear, index_label= False)
#     fig.savefig('plots/motor_array_LR.png')

def plot_motor_POLY(data, ind):
    x = data['PWM']
    y = data['PESO']*g*gain
    x = np.array(x).reshape(-1, 1)
    y = np.array(y).reshape(-1, 1)
    x_ = PolynomialFeatures(degree=2, include_bias=False).fit_transform(x)
    model = LinearRegression().fit(x_, y)
    K = model.coef_
    score = model.score(x_, y)
    y_pred = model.predict((x_))
    plt.subplot(2,2,ind)
    plt.plot(x, y,'.')
    plt.plot(x_, y_pred, color='red', label='Linear Regression')
    plt.xlabel('PWM')
    plt.ylabel('THRUST[N]')
    plt.title('POLYNOMIAL REGRESSOR')
    ax = plt.gca()
    ax.set_xlim([0,500])
    plt.grid()
    print(K)
    return K[0][0],K[0][1]

def plot_motor_array_POLY(data):
    fig, axes = plt.subplots(2,2, constrained_layout=True)
    list = []
    for ind, df in enumerate(data, start = 1):
        list.append(plot_motor_POLY(df, ind))
    #plt.show()
    df = pd.DataFrame(list, columns = ['K0','K1'])
    df.to_excel(filename_poly, index_label= False)
    fig.savefig('plots/motor_array_POLY.png')


#main
#filename = 'data.xlsx'
#n_mot = 4

data = pd.read_excel(filename_linear, sheet_name = 'Sheet1')
print(data)
plot_motor_LR(data,1)

