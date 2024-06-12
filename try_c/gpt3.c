#include <GL/glut.h>

// ウィンドウの初期化
void init() {
    // 背景色を黒に設定
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// ウィンドウの描画
void display() {
    // バッファをクリア
    glClear(GL_COLOR_BUFFER_BIT);

    // 画面の更新
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // GLUTの初期化
    glutInit(&argc, argv);
    // ウィンドウの作成
    glutCreateWindow("Simple OpenGL Program");
    // ウィンドウのサイズを設定
    glutInitWindowSize(800, 600);
    // ウィンドウの位置を設定
    glutInitWindowPosition(100, 100);
    // グラフィックスの初期化
    init();
    // 描画関数の登録
    glutDisplayFunc(display);
    // イベントループの開始
    glutMainLoop();

    return 0;
}
