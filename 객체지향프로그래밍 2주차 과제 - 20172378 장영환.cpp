#include <bangtal.h>
using namespace bangtal;

int main() {

	ScenePtr scene1 = Scene::create("룸 1", "images/배경-1.png");  
	ScenePtr scene2 = Scene::create("룸 2", "images/배경-2.png");
	ScenePtr scene3 = Scene::create("룸 3", "images/배경-2.png");


	//첫번째 방

	auto door1_opened = false, locked1 = true;
	auto door1 = Object::create("images/문-오른쪽-닫힘.png", scene1, 800, 270);
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (locked1) {		 	
			showMessage("문이 잠겨있다.");
		}
		else if (door1_opened) {         
			scene2->enter();

		}
		else {                // 문이 닫힌 상태  
			door1->setImage("images/문-오른쪽-열림.png");
			door1_opened = true;
		}

		return true;
	});

	door1->setOnKeypadCallback([&](ObjectPtr object)-> bool {
		locked1 = false;
		showMessage("띠리링~~");
		return true;
	});

	auto carpet = Object::create("images/카펫.png", scene1, 430, 70, true);
	carpet->setScale(0.35f);

	auto sofa1 = Object::create("images/소파-1.png", scene1, 920, 140);
	sofa1->setScale(0.17f);

	auto bed = Object::create("images/침대.png", scene1, 45, 130);
	bed->setScale(0.2f);

	auto password = Object::create("images/암호.png", scene1, 500, 108, false);
	password->setScale(0.25f);

	auto keypad = Object::create("images/키패드.png", scene1, 915, 400);
	keypad->setScale(2.5f);
	keypad->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("tea", door1);
		return true;
	});

	auto quizshown = false;
	auto quiz = Object::create("images/퀴즈.png", scene1, 80, 80, false);
	quiz->setScale(0.7f);
	quiz->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (quizshown) {
			quiz->hide();
		}
		return true;
		});

	auto letter = Object::create("images/편지.png", scene1, 40, 120, true);
	letter->setScale(0.04f);
	letter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (quizshown == false) {
			quiz->show();
			quizshown = true;
		}
		return true;
		});

	//두번째 방

	auto door2 = Object::create("images/문-왼쪽-열림.png", scene2, 320, 270);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
	});

	auto key = Object::create("images/열쇠.png", scene2, 1100, 230);
	key->setScale(0.3f);

	key->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		key->pick();

		return true;
	});

	auto chairMoved = false;
	auto chair = Object::create("images/의자.png", scene2, 350, 70);
	chair->setScale(0.17f);
	chair->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (chairMoved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				chair->locate(scene2, 350, 120);
				chairMoved = true;
			}
		}
		return true;
	});

	auto tableMoved = false;
	auto table = Object::create("images/테이블.png", scene2, 500, 60);
	table->setScale(0.25f);
	table->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (tableMoved == false) {
			if (action == MouseAction::MOUSE_DRAG_UP) {
				table->locate(scene2, 500, 90);
				tableMoved = true;
			}
		}
		return true;
	});

	auto flowerpotMoved = false;
	auto flowerpot = Object::create("images/화분.png", scene2, 50, 100);
	flowerpot->setScale(1.0f);
	flowerpot->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (flowerpotMoved == false) {
			if (action == MouseAction::MOUSE_DRAG_RIGHT) {
				flowerpot->locate(scene2, 80, 100);
				flowerpotMoved = true;
			}
			else if (action == MouseAction::MOUSE_DRAG_LEFT) {
				flowerpot->locate(scene2, 20, 100);
				flowerpotMoved = true;
			}
		}
		return true;
	});

	auto sofa2Moved = false;
	auto sofa2 = Object::create("images/소파-2.png", scene2, 980, 170);
	sofa2->setScale(0.15f);
	sofa2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (sofa2Moved == false) {
			if (action == MouseAction::MOUSE_DRAG_DOWN) {
				sofa2->locate(scene2, 980, 60);
				sofa2Moved = true;
			}
		}
		return true;
	});

	auto door3_opened = false;
	auto door3 = Object::create("images/문-오른쪽-닫힘.png", scene2, 850, 280);
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (door3_opened == true) {  // 문이 열린 상태
			scene3->enter();
		}
		else if (key->isHanded()) {                // 문이 닫힌 상태  
			door3->setImage("images/문-오른쪽-열림.png");
			door3_opened = true;
			showMessage("잠금 장치 해제.");
		}

		else {
			showMessage("문이 잠겨있다.");
		}
		return true;
	});

	//세번째 방

	auto door4 = Object::create("images/문-왼쪽-열림.png", scene3, 320, 270);
	door4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene2->enter();
		return true;
		});

	auto chair2 = Object::create("images/의자.png", scene3, 350, 70);
	chair2->setScale(0.17f);

	auto table2 = Object::create("images/테이블.png", scene3, 500, 60);
	table2->setScale(0.25f);

	auto table3found = false;
	auto table3 = Object::create("images/테이블2.png", scene3, 800, 70);
	table3->setScale(0.12f);
	table3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		table3->hide();
		table3found = true;
		return true;
		});

	auto flowerpot2 = Object::create("images/화분.png", scene3, 50, 100);
	flowerpot2->setScale(1.0f);

	auto sofa3 = Object::create("images/소파-2.png", scene3, 980, 170);
	sofa3->setScale(0.15f);

	auto door5_opened = false;
	auto door5 = Object::create("images/문-오른쪽-닫힘.png", scene3, 850, 280);
	door5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (door5_opened == true) {  // 문이 열린 상태
			endGame();
		}
		else if (table3found) {                // 문이 닫힌 상태  
			door5->setImage("images/문-오른쪽-열림.png");
			door5_opened = true;
			showMessage("잠금 장치 해제. 문을 열고 나가세요!");
		}

		else {
			showMessage("두번째 방과 다른 부분들을 찾아 클릭하세요!");
		}
		return true;
		});

	// 게임 시작

	startGame(scene1);
	return 0;
}