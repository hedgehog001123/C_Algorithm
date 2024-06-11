#include <stdio.h>
#include <lapacke.h>

// 連立方程式 Ax = b を解く関数
void solve_linear_system(double A[], double b[], int n) {
    // LAPACKE_dgesvの引数として使用するパラメータ
    lapack_int N = n, NRHS = 1, LDA = n, LDB = n;
    lapack_int ipiv[n]; // ピボット選択の結果を格納する配列

    // 解を格納する配列
    double x[n];

    // 連立方程式を解く
    lapack_int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, N, NRHS, A, LDA, ipiv, b, LDB);

    // 解が求められた場合は、解を表示する
    if (info == 0) {
        printf("Solution:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %f\n", i, b[i]);
        }
    } else {
        printf("Failed to solve linear system.\n");
    }
}

int main() {
    // 連立方程式 Ax = b の係数行列 A と定数ベクトル b を定義
    double A[3][3] = {
        {2.0, 1.0, -1.0},
        {-3.0, -1.0, 2.0},
        {-2.0, 1.0, 2.0}
    };

    double b[3] = {8.0, -11.0, -3.0};

    // 係数行列 A と定数ベクトル b を1次元の配列に変換
    double A_flat[3 * 3], b_flat[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A_flat[i * 3 + j] = A[i][j];
        }
        b_flat[i] = b[i];
    }

    // 連立方程式を解く
    solve_linear_system(A_flat, b_flat, 3);

    return 0;
}
