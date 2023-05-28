#include "Player.h"
#include <cstdio>

Point* levelTwoPoint = new Point(9, 9);
Point* levelThreePoint = new Point(0, 2);
Point* levelLastPoint = new Point(9, 0);

Player::Player(Coordinate coordinate) : coord(coordinate), player{ *(new Point(1, 1)) } {}

void Player::movement() {
	KeyW();
	KeyS();
	KeyA();
	KeyD();
}

void Player::resetPlayerPosition() {

	switch (coord.getCurrentLevel())
	{
	case 1:
		this->player.setX(1);
		this->player.setY(1);
		break;
	case 2:
		this->player.setX(9);
		this->player.setY(9);
		break;
	case 3:
		this->player.setX(0);
		this->player.setY(2);
		break;
	default:
		break;
	}

}

void Player::displayDistanceFromF() {

	vPlayer.setPlayerPoint(&this->player);

	
		switch (coord.getCurrentLevel()) {
			case 1:
				vPlayer.setGoalPoint(levelTwoPoint);
				break;
			case 2:
				vPlayer.setGoalPoint(levelThreePoint);
				break;
			case 3:
				vPlayer.setGoalPoint(levelLastPoint);
				break;
		}
		
		if (coord.getCurrentLevel() < 4) {
			printf("Distance from [F]: %.2f meters", vPlayer.distance());
		}
	
}

void Player::KeyW() {
	if (GetAsyncKeyState('W')) {

		if (player.getY() > 0) {

			// Player moves in y axis per 1 unit
			player.setY(player.getY() - 1);

			string currentPlayerPoint = *(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX());

			if (currentPlayerPoint == "[F]") {
				// Player reached the [F]: Next Stage Level
				coord.nextLevel();
			}


			if (currentPlayerPoint == "[-]" || currentPlayerPoint == "[#]" || currentPlayerPoint == "[@]") {
				// Player touched the wall: Reset player position and retry the stage level

				player.setY(player.getY() + 1);

				resetPlayerPosition();
				coord.retryLevel();

			}
			else {
				// Player movement based on y and x variable which modifies the coordinate array
				*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) = "[*]";
			}
		}

		if (player.getY() < (coord.getY() - 1)) {
			// Clear the passed through path of the player
			*(*(coord.getCoordinate() + (int)player.getY() + 1) + (int)player.getX()) = "[ ]";
		}

		coord.Display();
		displayDistanceFromF();

	}
}

void Player::KeyS() {
	if (GetAsyncKeyState('S')) {

		if (player.getY() < (coord.getY() - 1)) {

			player.setY(player.getY() + 1);

			string currentPlayerPoint = *(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX());

			if (currentPlayerPoint == "[F]") {
				coord.nextLevel();
			}

			if (currentPlayerPoint == "[-]" || currentPlayerPoint == "[#]" || currentPlayerPoint == "[@]") {

				player.setY(player.getY() - 1);

				resetPlayerPosition();
				coord.retryLevel();

			}
			else {
				*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) = "[*]";
			}

		}

		if (player.getY() >= 1) {

			*(*(coord.getCoordinate() + (int)player.getY() - 1) + (int)player.getX()) = "[ ]";
		}

		coord.Display();
		displayDistanceFromF();
	}
}

void Player::KeyA() {
	if (GetAsyncKeyState('A')) {

		if (player.getX() > 0) {

			player.setX(player.getX() - 1);

			string currentPlayerPoint = *(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX());

			if (currentPlayerPoint == "[F]") {
				coord.nextLevel();
			}

			if (currentPlayerPoint == "[-]" || currentPlayerPoint == "[#]" || currentPlayerPoint == "[@]") {

				player.setX(player.getX() + 1);

				resetPlayerPosition();
				coord.retryLevel();

			}
			else {
				*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) = "[*]";
			}
		}

		if (player.getX() < (coord.getX() - 1)) {


			*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX() + 1) = "[ ]";
		}

		coord.Display();
		displayDistanceFromF();

	}
}

void Player::KeyD() {
	if (GetAsyncKeyState('D')) {

		if (player.getX() < (coord.getX() - 1)) {

			player.setX(player.getX() + 1);

			string currentPlayerPoint = *(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX());

			if (currentPlayerPoint == "[F]") {
				coord.nextLevel();
			}

			if (currentPlayerPoint == "[-]" || currentPlayerPoint == "[#]" || currentPlayerPoint == "[@]") {

				player.setX(player.getX() - 1);

				resetPlayerPosition();
				coord.retryLevel();

			}
			else {
				*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) = "[*]";
			}
		}

		if (player.getX() >= 1) {

			*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX() - 1) = "[ ]";

		}

		coord.Display();
		displayDistanceFromF();

	}
}

/*
class Player {

private:
	Point player{};
	Vector vPlayer{};

	Coordinate coord;

public:
	Player(Coordinate coordinate) : coord(coordinate) {}

	void movement() {

		int xCoord = coord.getX();
		int yCoord = coord.getY();

		string** coordinate = coord.getCoordinate();

		KeyW();

		if (GetAsyncKeyState('S')) {

			if (player.getY() < (yCoord - 1)) {

				player.setY(player.getY() + 1);

				int y = player.getY();
				int x = player.getX();

				if (*(*(coordinate + y) + x) == "[F]") {
					coord.nextLevel();
				}

				if (*(*(coordinate + y) + x) == "[-]") {

					resetPlayerPosition();

					coord.retryLevel();

					player.setY(player.getY() - 1);
				}
				else {
					*(*(coordinate + y) + x) = "[*]";
				}

			}

			if (player.getY() >= 1) {
				int y = player.getY();
				int x = player.getX();

				*(*(coordinate + y - 1) + x) = "[ ]";
			}

			coord.Display();
			//	keyPressed = "S";
		}

		if (GetAsyncKeyState('A')) {

			if (player.getX() > 0) {

				player.setX(player.getX() - 1);

				int y = player.getY();
				int x = player.getX();

				if (*(*(coordinate + y) + x) == "[F]") {
					coord.nextLevel();
				}

				if (*(*(coordinate + y) + x) == "[-]") {

					resetPlayerPosition();

					coord.retryLevel();

					player.setX(player.getX() + 1);
				}
				else {

					*(*(coordinate + y) + x) = "[*]";
				}
			}

			if (player.getX() < (xCoord - 1)) {

				int y = player.getY();
				int x = player.getX();

				*(*(coordinate + y) + x + 1) = "[ ]";
			}

			coord.Display();

			//keyPressed = "A";
		}

		if (GetAsyncKeyState('D')) {

			if (player.getX() < (xCoord - 1)) {

				player.setX(player.getX() + 1);

				int y = player.getY();
				int x = player.getX();

				if (*(*(coordinate + y) + x) == "[F]") {
					coord.nextLevel();
				}

				if (*(*(coordinate + y) + x) == "[-]") {

					resetPlayerPosition();

					coord.retryLevel();
					player.setX(player.getX() - 1);

				}
				else {
					*(*(coordinate + y) + x) = "[*]";
				}
			}

			// For clearing the path of the player (i.e
			if (player.getX() >= 1) {

				int y = player.getY();
				int x = player.getX();

				*(*(coordinate + y) + x - 1) = "[ ]";

			}

			coord.Display();

		}

	}

	void KeyW() {
		if (GetAsyncKeyState('W')) {

			if (player.getY() > 0) {

				// Player moves in y axis per 1 unit
				player.setY(player.getY() - 1);

				if (*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) == "[F]") {
					// Player reached the [F]: Next Stage Level
					coord.nextLevel();
				}

				if (*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) == "[-]") {
					// Player touched the wall: Reset player position and retry the stage level

					resetPlayerPosition();

					coord.retryLevel();

					player.setY(player.getY() + 1);
				}
				else {
					// Player movement based on y and x variable which modifies the coordinate array
					*(*(coord.getCoordinate() + (int)player.getY()) + (int)player.getX()) = "[*]";
				}
			}

			if (player.getY() <= (coord.getY() - 1)) {
				// Clear the passed through path of the player
				*(*(coord.getCoordinate() + (int)player.getY() + 1) + (int)player.getX()) = "[ ]";
			}

			coord.Display();

		}
	}

	void resetPlayerPosition() {
		player.setX(1);
		player.setY(1);
	}
};*/