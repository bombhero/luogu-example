import numpy as np


def mat_pow(mat_s, n):
    if n == 1:
        return mat_s
    if n == 2:
        tmp = np.matmul(mat_s, mat_s)
        return tmp
    if n % 2 == 0:
        tmp = mat_pow(mat_s, int(n/2))
        return np.matmul(tmp, tmp)
    else:
        tmp = mat_pow(mat_s, int(n/2))
        tmp = np.matmul(tmp, tmp)
        return np.matmul(tmp, mat_s)


def main():
    rabbit_mat = np.array([[1, 0]], dtype=np.int128)
    count_mat = np.array([[1, 1], [1, 0]], dtype=np.int128)
    n = int(input())
    # n = 100
    if n == 1:
        print('1')
        return
    result_mat = np.matmul(rabbit_mat, mat_pow(count_mat, n-1))
    result = result_mat[0, 0] % 1000000007
    print('{}'.format(result))


if __name__ == '__main__':
    main()
