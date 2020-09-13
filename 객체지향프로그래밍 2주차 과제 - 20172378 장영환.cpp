#include <bangtal.h>
using namespace bangtal;

int main() {

	ScenePtr startPage = Scene::create("STARTPAGE","images/startpage.png");
	ScenePtr scene1 = Scene::create("ROOM 1", "images/배경-1.png");
	ScenePtr scene2 = Scene::create("ROOM 2", "images/배경-2.png");
	ScenePtr scene3 = Scene::create("ROOM 3", "images/배경-2.png");

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	auto startButton = Object::create("images/start.png", startPage, 565, 50);

	startButton->setScale(0.07f);
	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);
		setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, true);
		return true;
		});


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
		else {            
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

	auto bed = Object::create("images/침대.png", scene1, 45, 130);
	bed->setScale(0.2f);

	auto password = Object::create("images/암호.png", scene1, 500, 108, false);
	password->setScale(0.25f);

	auto keypad = Object::create("images/키패드.png", scene1, 920, 400);
	keypad->setScale(2.5f);
	keypad->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		showKeypad("tea", door1);
		return true;
		});

	auto letter = Object::create("images/편지.png", scene1, 40, 120, true);
	auto quiz1 = Object::create("images/퀴즈1.png", scene1, 80, 80, false);

	letter->setScale(0.04f);
	letter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {	
		quiz1->show();
		return true;
		});

	quiz1->setScale(0.7f);
	quiz1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		quiz1->hide();
		return true;
		});

	auto sofa1 = Object::create("images/소파-1.png", scene1, 920, 140);
	sofa1->setScale(0.17f);

	auto letter2 = Object::create("images/편지2.png", scene1, 1100, 250, true);
	auto hint = Object::create("images/hint.png", scene1, 400, 160, false);

	letter2->setScale(0.04f);
	letter2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		hint->show();
		return true;
		});

	hint->setScale(0.7f);
	hint->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		hint->hide();
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
	auto complexLock = Object::create("images/complexlock.png", scene2, 820, 460);
	complexLock->setScale(0.02f);


	auto quiz2solved = false;
	auto quiz2 = Object::create("images/퀴즈2.png", scene2, 190, 480, false);
	quiz2->setScale(0.57f);

	auto quiz2field = Object::create("images/빈화면.png", scene2, 190, 30, false);
	quiz2field->setScale(0.57f);

	auto usbGate1X = 300, usbGateY = 320;
	auto usbGate1 = Object::create("images/usb입구.png", scene2, usbGate1X, usbGateY, false);
	usbGate1->setScale(0.08f);

	auto usbGate2X = 580;
	auto usbGate2 = Object::create("images/usb입구.png", scene2, usbGate2X, usbGateY, false);
	usbGate2->setScale(0.08f);

	auto usbGate3X = 860;
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
		else if ((quizUsbX > 900) || (quizUsbX < 300)) {
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
		else if ((quizUsbX > 900)|| (quizUsbX < 300)) {
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
		else if ((quizUsbX > 900) || (quizUsbX < 300)) {
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
	complexLock->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (quiz2solved) {
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
			showMessage("복잡한 잠금 장치가 있다. 문을 해킹할 수단을 찾아보자!");
		}

		return true;
		});

	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (door3_opened == true) {
			scene3->enter();
			setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
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
			showMessage("복잡한 잠금 장치가 있다. 문을 해킹할 수단을 찾아보자!");
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

	auto differenceFound = 0;
	auto mask = Object::create("images/마스크.png", scene3, 570, 165);
	auto check1 = Object::create("images/check.png", scene3, 570, 165, false);
	check1->setScale(0.05f);
	mask->setScale(0.04f);
	mask->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		mask->hide();
		differenceFound++;
		check1->show();
		return true;
		});

	auto table3 = Object::create("images/테이블2.png", scene3, 450, 250);
	auto check2 = Object::create("images/check.png", scene3, 500, 300, false);
	check2->setScale(0.05f);
	table3->setScale(0.1f);
	table3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		table3->hide();
		differenceFound++;
		check2->show();
		return true;
		});

	auto shoes = Object::create("images/신발.png", scene3, 800, 30);
	auto check3 = Object::create("images/check.png", scene3, 810, 40, false);
	check3->setScale(0.05f);
	shoes->setScale(0.07f);
	shoes->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		shoes->hide();
		differenceFound++;
		check3->show();
		return true;
		});

	auto flowerpot2 = Object::create("images/화분.png", scene3, 50, 100);
	flowerpot2->setScale(1.0f);

	auto flowerpot3 = Object::create("images/화분2.png", scene3, 200, 100);
	auto check4 = Object::create("images/check.png", scene3, 210, 110, false);
	check4->setScale(0.05f);
	flowerpot3->setScale(0.1f);
	flowerpot3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		flowerpot3->hide();
		differenceFound++;
		check4->show();
		return true;
		});

	auto sofa3 = Object::create("images/소파-2.png", scene3, 950, 155);
	sofa3->setScale(0.17f);

	auto camera = Object::create("images/카메라.png", scene3, 1080, 265);
	auto check5 = Object::create("images/check.png", scene3, 1080, 265, false);
	check5->setScale(0.05f);
	camera->setScale(0.032f);
	camera->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		camera->hide();
		differenceFound++;
		check5->show();
		return true;
		});

	auto door5_opened = false;
	auto door5 = Object::create("images/문-오른쪽-닫힘.png", scene3, 850, 280);
	door5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

		if (door5_opened == true) {
			endGame();
		}
		else if (differenceFound == 5) {
			door5->setImage("images/문-오른쪽-열림.png");
			door5_opened = true;
			showMessage("모든 미션 성공! 문을 열고 나가세요!");
		}

		else {
			showMessage("두번째 방과 다른 부분을 찾아 체크해보자!");
		}
		return true;
		});

	// 게임 시작

	startGame(startPage);
	return 0;
}