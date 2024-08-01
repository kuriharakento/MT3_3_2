#include <imgui.h>
#include <Novice.h>
#include "MyFunctions.h"

const char kWindowTitle[] = "LC1A_13_クリハラ_ケント_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 a{ 0.2f,1.0f,0.0f };
	Vector3 b{ 2.4f,3.1f,1.2f };
	Vector3 c = a + b;
	Vector3 d = a - b;
	Vector3 e = a * 2.4f;
	Vector3 f = e / 2.0f;
	Vector3 rotate{ 0.4f,1.43f,-0.8f };
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateMatrix = Multiply(Multiply(rotateXMatrix, rotateYMatrix) , rotateZMatrix);
	Matrix4x4 m = {
		 1.0f,1.0f,1.0f,1.0f,
		 1.0f,1.0f,1.0f,1.0f,
		 1.0f,1.0f,1.0f,1.0f,
		 1.0f,1.0f,1.0f,1.0f
	};
	Matrix4x4 m1 = Add(rotateMatrix, m);
	Matrix4x4 m2 = Sub(rotateMatrix, m);

	Vector3 g = -a;
	Vector3 h = +g;


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		ImGui::Begin("window");

		ImGui::Text("c:%f, %f, %f", c.x, c.y, c.z);
		ImGui::Text("d:%f, %f, %f", d.x, d.y, d.z);
		ImGui::Text("e:%f, %f, %f", e.x, e.y, e.z);
		ImGui::Text("f:%f, %f, %f", f.x, f.y, f.z);
		ImGui::Text("matrix:\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n",
			rotateMatrix.m[0][0], rotateMatrix.m[0][1], rotateMatrix.m[0][2], rotateMatrix.m[0][3],
			rotateMatrix.m[1][0], rotateMatrix.m[1][1], rotateMatrix.m[1][2], rotateMatrix.m[1][3],
			rotateMatrix.m[2][0], rotateMatrix.m[2][1], rotateMatrix.m[2][2], rotateMatrix.m[2][3],
			rotateMatrix.m[3][0], rotateMatrix.m[3][1], rotateMatrix.m[3][2], rotateMatrix.m[3][3]);
		ImGui::Text("matrix:\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n",
			m1.m[0][0], m1.m[0][1], m1.m[0][2], m1.m[0][3],
			m1.m[1][0], m1.m[1][1], m1.m[1][2], m1.m[1][3],
			m1.m[2][0], m1.m[2][1], m1.m[2][2], m1.m[2][3],
			m1.m[3][0], m1.m[3][1], m1.m[3][2], m1.m[3][3]);
		ImGui::Text("matrix:\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n%f,%f,%f,%f\n",
			m2.m[0][0], m2.m[0][1], m2.m[0][2], m2.m[0][3],
			m2.m[1][0], m2.m[1][1], m2.m[1][2], m2.m[1][3],
			m2.m[2][0], m2.m[2][1], m2.m[2][2], m2.m[2][3],
			m2.m[3][0], m2.m[3][1], m2.m[3][2], m2.m[3][3]);
		ImGui::Text("g:%f, %f, %f", g.x, g.y, g.z);
		ImGui::Text("h:%f, %f, %f", h.x, h.y, h.z);

		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
