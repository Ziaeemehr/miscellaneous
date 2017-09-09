import matplotlib.pyplot as plt

plt.hlines(7, 0, 2, linestyles='dashed')
plt.hlines(11, 0, 2, linestyles='dashed')
plt.hlines(10, 0, 2, linestyles='dashed')
plt.hlines(8, 0, 2, linestyles='dashed')
plt.annotate(
    '', xy=(1, 10), xycoords='data',
    xytext=(1, 8), textcoords='data',
    arrowprops={'arrowstyle': '<->'})
plt.annotate(
    'D = 1', xy=(1, 9), xycoords='data',
    xytext=(5, 0), textcoords='offset points')

# alternatively,
# plt.text(1.01, 9, 'D = 1')

plt.show()
