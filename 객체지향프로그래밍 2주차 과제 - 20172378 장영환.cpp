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

	auto keypad = Object::create("images/키패드.png", scene1, 920, 400);
	keypad->setScale(2.5f);
	keypad->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("b", door1);
		return true;
	});

	auto quiz1shown = false;
	auto quiz1 = Object::create("images/퀴즈1.png", scene1, 80, 80, false);
	quiz1->setScale(0.7f);
	quiz1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (quiz1shown) {
			quiz1->hide();
		}
		return true;
		});

	auto letter = Object::create("images/편지.png", scene1, 40, 120, true);
	letter->setScale(0.04f);
	letter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (quiz1shown == false) {
			quiz1->show();
			quiz1shown = true;
		}
		return true;
		});

	//두번째 방

	auto door2 = Object::create("images/문-왼쪽-열림.png", scene2, 320, 270);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		return true;
	});

	auto getUsb = false;
	auto usb = Object::create("images/usb.png", scene2, 1100, 140);
	usb->setScale(0.02f);

	usb->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		usb->pick();
		getUsb = true;
		return true;
	});

	auto chair = Object::create("images/의자.png", scene2, 350, 70);
	chair->setScale(0.17f);

	auto table = Object::create("images/테이블.png", scene2, 500, 60);
	table->setScale(0.25f);

	auto flowerpot = Object::create("images/화분.png", scene2, 50, 100);
	flowerpot->setScale(1.0f);

	auto sofa2 = Object::create("images/소파-2.png", scene2, 950, 155);
	sofa2->setScale(0.17f);

	auto door3 = Object::create("images/문-오른쪽-닫힘.png", scene2, 850, 280);

	auto quiz2solved = false;
	auto quiz2 = Object::create("images/퀴즈2.png", scene2, 130, 420, false);
	quiz2->setScale(0.53f);

	auto quiz2field = Object::create("images/빈화면.png", scene2, 130, 30, false);
	quiz2field->setScale(0.53f);

	auto usbGate1X = 200, usbGateY = 320;
	auto usbGate1 = Object::create("images/usb입구.png", scene2, usbGate1X, usbGateY, false);
	usbGate1->setScale(0.08f);

	auto usbGate2X = 480;
	auto usbGate2 = Object::create("images/usb입구.png", scene2, usbGate2X, usbGateY, false);
	usbGate2->setScale(0.08f);

	auto usbGate3X = 760;
	auto usbGate3 = Object::create("images/usb입구.png", scene2, usbGate3X, usbGateY, false);
	usbGate3->setScale(0.08f);

	auto quizUsbX = usbGate2X + 25, quizUsbY = usbGateY - 200;
	auto quizUsb = Object::create("images/usb.png", scene2, quizUsbX, quizUsbY, false);
	quizUsb->setScale(0.08f);

	auto arrowLeft = Object::create("images/왼쪽화살표.png", scene2, usbGate2X - 80, usbGateY - 280, false);
	auto arrowUp = Object::create("images/위쪽화살표.png", scene2, usbGate2X + 20, usbGateY - 280, false);
	auto arrowRight = Object::create("images/오른쪽화살표.png", scene2, usbGate2X + 120, usbGateY - 280, false);
	arrowUp->setScale(0.05f);
	arrowRight->setScale(0.05f);
	arrowLeft->setScale(0.05f);

	arrowUp->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		quizUsbY += 50;
		quizUsb->locate(scene2, quizUsbX, quizUsbY);

		if ((quizUsbX != usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quizUsbX = usbGate2X + 25;
			quizUsbY = usbGateY - 200;
			quizUsb->locate(scene2, quizUsbX, quizUsbY);
		}
		else if ((quizUsbX == usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quiz2->hide();
			quiz2field->hide();
			arrowRight->hide();
			arrowLeft->hide();
			arrowUp->hide();
			quizUsb->hide();
			usbGate1->hide();
			usbGate2->hide();
			usbGate3->hide();
			showMessage("해킹 성공!");
			quiz2solved = true;
		}

		return true;
		});


	arrowRight->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		quizUsbX += 280;
		quizUsb->locate(scene2, quizUsbX, quizUsbY);

		if ((quizUsbX != usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quizUsbX = usbGate2X + 25;
			quizUsbY = usbGateY - 200;
			quizUsb->locate(scene2, quizUsbX, quizUsbY);
		}
		else if ((quizUsbX == usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quiz2->hide();
			quiz2field->hide();
			arrowRight->hide();
			arrowLeft->hide();
			arrowUp->hide();
			quizUsb->hide();
			usbGate1->hide();
			usbGate2->hide();
			usbGate3->hide();
			showMessage("해킹 성공!");
			quiz2solved = true;
		}


		return true;
		});


	arrowLeft->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)-> bool {
		quizUsbX -= 280;
		quizUsb->locate(scene2, quizUsbX, quizUsbY);

		if ((quizUsbX != usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quizUsbX = usbGate2X + 25;
			quizUsbY = usbGateY - 200;
			quizUsb->locate(scene2, quizUsbX, quizUsbY);
		}
		else if ((quizUsbX == usbGate3X + 25) && (quizUsbY >= usbGateY)) {
			quiz2->hide();
			quiz2field->hide();
			arrowRight->hide();
			arrowLeft->hide();
			arrowUp->hide();
			quizUsb->hide();
			usbGate1->hide();
			usbGate2->hide();
			usbGate3->hide();
			showMessage("해킹 성공!");
			quiz2solved = true;
		}


		return true;
		});

	auto door3_opened = false;
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (door3_opened == true) { 
			scene3->enter();
		}
		else if (quiz2solved) {              
			door3->setImage("images/문-오른쪽-열림.png");
			door3_opened = true;
			showMessage("잠금 장치 해제.");
		}

		else if ((quiz2solved == false) && (getUsb == true)) {
			quiz2->show();
			quiz2field->show();
			arrowRight->show();
			arrowLeft->show();
			arrowUp->show();
			quizUsb->show();
			usbGate1->show();
			usbGate2->show();
			usbGate3->show();
		}

		else {
			showMessage("문이 잠겨있다. 단서를 찾아보자!");
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



	auto table3Found = false;
	auto table3 = Object::create("images/테이블2.png", scene3, 450, 250);
	auto check1 = Object::create("images/check.png", scene3, 500, 300, false);
	check1->setScale(0.05f);
	table3->setScale(0.1f);
	table3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		table3->hide();
		table3Found = true;
		check1->show();
		return true;
		});

	auto shoesFound = false;
	auto shoes = Object::create("images/신발.png", scene3, 800, 30);
	auto check2 = Object::create("images/check.png", scene3, 810, 40, false);
	check2->setScale(0.05f);
	shoes->setScale(0.05f);
	shoes->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		shoes->hide();
		shoesFound = true;
		check2->show();
		return true;
		});

	auto flowerpot2 = Object::create("images/화분.png", scene3, 50, 100);
	flowerpot2->setScale(1.0f);

	auto flowerpot3Found = false;
	auto flowerpot3 = Object::create("images/화분2.png", scene3, 200, 100);
	auto check3 = Object::create("images/check.png", scene3, 210, 110, false);
	check3->setScale(0.05f);
	flowerpot3->setScale(0.1f);
	flowerpot3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		flowerpot3->hide();
		flowerpot3Found = true;
		check3->show();
		return true;
		});

	auto sofa3 = Object::create("images/소파-2.png", scene3, 950, 155);
	sofa3->setScale(0.17f);

	auto cameraFound = false;
	auto camera = Object::create("images/카메라.png", scene3, 1080, 265);
	auto check4 = Object::create("images/check.png", scene3, 1080, 265, false);
	check4->setScale(0.05f);
	camera->setScale(0.032f);
	camera->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		camera->hide();
		cameraFound = true;
		check4->show();
		return true;
		});

	auto door5_opened = false;
	auto door5 = Object::create("images/문-오른쪽-닫힘.png", scene3, 850, 280);
	door5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (door5_opened == true) {  // 문이 열린 상태
			endGame();
		}
		else if ((table3Found && shoesFound) && (flowerpot3Found && cameraFound)) {                // 문이 닫힌 상태  
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