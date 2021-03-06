from __future__ import division

import copy
import time

import numpy as np



def lu_solvable(A):
    return all(not np.linalg.det(np.array(A)[0:k, 0:k]) == 0 for k in range(1, len(A) + 1))

def upper_tri_solver(a, b):
    n = len(b)
    x = [0] * n
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - sum(a[i][j] * x[j] for j in range(n))) / a[i][i]
    return x



def diagonal_solver(a, b):
    return [b[i] / a[i] for i in range(len(b))]


def lower_tri_solver(a, b):
    n = len(b)
    x = [0] * n
    for i in range(n):
        x[i] = (b[i] - sum(a[i][j] * x[j] for j in range(n))) / a[i][i]
    return x


def symmetric_possitve_difinite(D):
    return all(i > 0 for i in D)


def LDLt(A):
    n = len(A)
    L = [x[:] for x in [[0] * n] * n]
    D = [0] * n
    for i in range(n):
        L[i][i] = 1
    for i in range(n):
        D[i] = A[i][i] - sum(D[k] * L[i][k] ** 2 for k in range(n - 1))
        for j in range(i + 1, n):
            L[j][i] = (A[i][j] - sum(D[k] * L[i][k] * L[j][k] for k in range(n - 1))) / D[i]
    return D, L

n = 3
A = np.random.uniform(-1, 1, (n, n))
A = A + A.T
B = np.random.uniform(-10, 10, n)

A = [[2, -1, 0], [-1, 2, -1], [0, -1, 1]]
B = [1, 0, 0]

if not np.array_equal(np.array(A), np.array(A).transpose()):
    raise ValueError("O determinante precisa ser simetrico!")

if not lu_solvable(A):
    raise ValueError("O determinante precisa ser maior que zero!")

D, L = LDLt(copy.deepcopy(A))

L = np.around(L, 5)
D = np.around(D, 5)

print("Matrix L:\n{}".format(L))
print("Matriz Transporta\n{}".format(L.transpose()))
print("Matrix Diagonal:\n{}".format(D))

# LY = B 
Y = lower_tri_solver(L, B)

# DZ = Y 
Z = diagonal_solver(D, Y)

# LtX = Z 
X = upper_tri_solver(np.array(L).T, Z)

# solucao of AX = B
real = np.dot(np.linalg.inv(A), B)

real, X = np.around([real, X], 5)

assert np.allclose(X, real, rtol=0, atol=1e-1)

print(
    """
    Decomposicao LU: {0}

    Matrix de Solucao: {1}
    """.format(X, real))
