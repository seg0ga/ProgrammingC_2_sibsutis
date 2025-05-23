import matplotlib.pyplot as plt

x=[0, 16, 256, 1000, 1700,2500]
y1=[0, 0.000305, 0.082239, 5.490029, 34.863328,158.239867,]
y2=[0,0.000400,0.042056,2.528819,15.982726,75.219546]
y3=[0,0.000564,0.048222,1.230541,4.469586,19.826122]
y4=[0,0.001988,0.043858,1.042493,3.284425,14.604082]
y5=[0,0.013242,0.046186,0.994964,3.094185,14.312091]
fig, ax = plt.subplots()

ax.plot(x, y1, label='1')

ax.plot(x, y2, label='2')
ax.plot(x, y3, label='8')
ax.plot(x, y4, label='32')
ax.plot(x, y5, label='128')

ax.legend()
plt.show()
