from ctypes import *
from Gkit import *
import numpy as np
from math import *
M_size: int = 700000
Wsize: float = 1000
X: list[float] = []
Y: list[float] = []
Z: list[float] = []
Xplot: list[float] = []
Yplot: list[float] = []
N: int = 0
def translate(dx: float, dy: float, dz: float) -> int:
    global N, X, Y, Z
    for i in range(N):
        X[i] += dx
        Y[i] += dy
        Z[i] += dz
def rotate_x(degrees: float) -> int:
    radians: float = 0.0
    c: float = 0.0
    s: float = 0.0
    temp: float = 0.0
    i: int = 0
    radians = degrees * (pi/180)
    c = cos(radians)
    s = sin(radians)
    for i in range(N):
        temp = c*Y[i] - s*Z[i]
        Z[i] = s*Y[i] + c*Z[i]
        Y[i] = temp
def rotate_y(degrees: float) -> int:
    radians: float = 0.0
    c: float = 0.0
    s: float = 0.0    
    temp: float = 0.0
    i: int = 0 
    radians = degrees*pi/180
    c = cos(radians)
    s = sin(radians)
    for i in range(N):
        temp = c*X[i] + s*Z[i]
        Z[i] = -s*X[i] + c*Z[i]
        X[i] = temp
def rotate_z(degrees: float) -> int:
    radians: float = 0.0
    c: float = 0.0
    s: float = 0.0
    temp: float = 0.0
    i: int = 0
    radians = degrees * (pi/180)
    c = cos(radians)
    s = sin(radians)
    for i in range(N):
        temp = c*X[i] - s*Y[i]
        Y[i] = s*X[i] + c*Y[i]
        X[i] = temp
def project(observer_distance: float, halfangle_degrees: float) -> int:
    global Xplot, Yplot, X, Y, Z
    i: int = 0
    for i in range(0, M_size, 1):
        Xplot[i] = (X[i] / (observer_distance+Z[i])) * (Wsize / (2*tan(halfangle_degrees))) + (Wsize/2)
        Yplot[i] = (Y[i] / (observer_distance+Z[i])) * (Wsize / (2*tan(halfangle_degrees))) + (Wsize/2)
def draw():
    global Xplot, Yplot, N
    i: int = 0
    for i in range(0, N, 2):
        G_line(Xplot[i], Yplot[i], Xplot[i+1], Yplot[i+1])
def print_object() -> int:
    global X, Y, Z, N
    i: int = 0
    for i in range(0, N, 2):
        print(f"X: {X[i]} Y: {Y[i]} Z: {Z[i]}")
        print(f"X: {X[i+1]} Y: {Y[i+1]} Z: {Z[i+1]}")
    print("===============================\n")
    for i in range(0, N, 2):
        print(f"Xplot: {Xplot[i]} Yplot: {Yplot[i]}")
        print(f"Xplot: {Xplot[i+1]} Yplot: {Yplot[i+1]}")
def save_line(xs: float, ys: float, zs: float, xe: float, ye: float, ze: float) -> int:
    global X, Y, Z, N, M_size
    if N+1 >= M_size:
        print("full\n")
        return 0
    X.append(xs)
    Y.append(ys)
    Z.append(zs)
    N += 1
    X.append(xe)
    Y.append(ye)
    Z.append(ze)
    N += 1
    return 1
def build_pyramid() -> int:
    global X, Y, Z, N
    n: int = 0
    k: int = 0
    a: float = 0.0
    x: list[float] = []
    z: list[float] = []
    yv: float = 0.0
    N = 0
    n = 4
    for k in range(0, n+1, 1):
        a = k * (2 * pi / n)
        x.append(cos(a))
        z.append(sin(a))
    yv = -1
    for k in range(0, n, 1):
        save_line(0, 2, 0, x[k], yv, z[k])
        save_line(x[k], yv, z[k], x[k+1], yv, z[k+1])
def test_pyramid():
    G_init_graphics(Wsize, Wsize)
    G_rgb(0, 0, 0)
    G_clear()
    G_rgb(0, 1, 0)
    build_pyramid()
    project(3, 45)
    draw()
    print_object()
    G_wait_key()
def test_pyramid_rotate():
    pass
def main():
    test_pyramid()

if __name__ == "__main__":
    main()
