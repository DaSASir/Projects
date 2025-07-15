#include "TickyTack.h"
#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

TickTackToe::TickTackToe() {
	for (int i = 0; i < 3; ++i) {
		m_place.push_back(std::vector<char>(3, ' '));
	}
}

void TickTackToe::play() {
	play_2players();
}

void TickTackToe::playPC() {
	play_PC();
}

void TickTackToe::play_2players() {
	int step = 0;
	std::vector<char> XO = { 'X' , 'O' };
	while (!endGame()) {
		print();
		std::cout << "Player " << XO[step] << ", enter your move (row col): ";
		add(XO[step]);
		step = (step + 1) % 2;
	}
	finish();
}

void TickTackToe::play_PC() {
	while (!endGame()) {
		print();
		movePC('X');

		if (!endGame()) {
			print();
			movePC('O');
		}
	}
	/*while (!endGame()) {
		print();
		std::cout << "Your turn,  enter your move (row col): ";
		add('X');

		if (!endGame()) {
			movePC('O');
		}
	}*/
	finish();
}

void TickTackToe::movePC(const char XO) {
	if (tryWin(XO)) return;

	if (tryBlock((XO == 'X') ? 'O' : 'X', XO)) return;

	if (m_place[1][1] == ' ') {
		m_place[1][1] = XO;
		return;
	}

	int j = 0;
	for (int i = 0; i < 3; i += 2) {
		if (m_place[i][j] == ' ') {
			m_place[i][j] = XO;
			return;
		}
		else if (m_place[j][i] == ' ') {
			m_place[j][i] = XO;
			return;
		}
		if (j != i) j = i;
	}

	while (true) {
		int i = rand() % 3;
		int j = rand() % 3;
		if (m_place[i][j] == ' ') {
			m_place[i][j] = XO;
			break;
		}
	}
}

bool TickTackToe::tryWin(char XO) {
	for (int i = 0; i < 3; ++i) {
		// Horizontals
		if (m_place[i][0] == XO && m_place[i][1] == XO && m_place[i][2] == ' ') {
			m_place[i][2] = XO;
			return true;
		}
		if (m_place[i][0] == XO && m_place[i][2] == XO && m_place[i][1] == ' ') {
			m_place[i][1] = XO;
			return true;
		}
		if (m_place[i][1] == XO && m_place[i][2] == XO && m_place[i][0] == ' ') {
			m_place[i][0] = XO;
			return true;
		}

		// Verticals
		if (m_place[0][i] == XO && m_place[1][i] == XO && m_place[2][i] == ' ') {
			m_place[2][i] = XO;
			return true;
		}
		if (m_place[0][i] == XO && m_place[2][i] == XO && m_place[1][i] == ' ') {
			m_place[1][i] = XO;
			return true;
		}
		if (m_place[1][i] == XO && m_place[2][i] == XO && m_place[0][i] == ' ') {
			m_place[0][i] = XO;
			return true;
		}
	}

	// Diagonals
	if (m_place[0][0] == XO && m_place[1][1] == XO && m_place[2][2] == ' ') {
		m_place[2][2] = XO;
		return true;
	}
	if (m_place[0][0] == XO && m_place[2][2] == XO && m_place[1][1] == ' ') {
		m_place[1][1] = XO;
		return true;
	}
	if (m_place[1][1] == XO && m_place[2][2] == XO && m_place[0][0] == ' ') {
		m_place[0][0] = XO;
		return true;
	}

	if (m_place[0][2] == XO && m_place[1][1] == XO && m_place[2][0] == ' ') {
		m_place[2][0] = XO;
		return true;
	}
	if (m_place[0][2] == XO && m_place[2][0] == XO && m_place[1][1] == ' ') {
		m_place[1][1] = XO;
		return true;
	}
	if (m_place[1][1] == XO && m_place[2][0] == XO && m_place[0][2] == ' ') {
		m_place[0][2] = XO;
		return true;
	}

	return false;
}

bool TickTackToe::tryBlock(char opponent, char XO) {
	for (int i = 0; i < 3; ++i) {
		// Horizontals
		if (m_place[i][0] == opponent && m_place[i][1] == opponent && m_place[i][2] == ' ') {
			m_place[i][2] = XO;
			return true;
		}
		if (m_place[i][0] == opponent && m_place[i][2] == opponent && m_place[i][1] == ' ') {
			m_place[i][1] = XO;
			return true;
		}
		if (m_place[i][1] == opponent && m_place[i][2] == opponent && m_place[i][0] == ' ') {
			m_place[i][0] = XO;
			return true;
		}

		// Verticals
		if (m_place[0][i] == opponent && m_place[1][i] == opponent && m_place[2][i] == ' ') {
			m_place[2][i] = XO;
			return true;
		}
		if (m_place[0][i] == opponent && m_place[2][i] == opponent && m_place[1][i] == ' ') {
			m_place[1][i] = XO;
			return true;
		}
		if (m_place[1][i] == opponent && m_place[2][i] == opponent && m_place[0][i] == ' ') {
			m_place[0][i] = XO;
			return true;
		}
	}

	// Diagonals
	if (m_place[0][0] == opponent && m_place[1][1] == opponent && m_place[2][2] == ' ') {
		m_place[2][2] = XO;
		return true;
	}
	if (m_place[0][0] == opponent && m_place[2][2] == opponent && m_place[1][1] == ' ') {
		m_place[1][1] = XO;
		return true;
	}
	if (m_place[1][1] == opponent && m_place[2][2] == opponent && m_place[0][0] == ' ') {
		m_place[0][0] = XO;
		return true;
	}

	if (m_place[0][2] == opponent && m_place[1][1] == opponent && m_place[2][0] == ' ') {
		m_place[2][0] = XO;
		return true;
	}
	if (m_place[0][2] == opponent && m_place[2][0] == opponent && m_place[1][1] == ' ') {
		m_place[1][1] = XO;
		return true;
	}
	if (m_place[1][1] == opponent && m_place[2][0] == opponent && m_place[0][2] == ' ') {
		m_place[0][2] = XO;
		return true;
	}

	return false;
}

void TickTackToe::finish() {
	std::cout << "\nResult of game:\n";
	print();

	if (haveWinner()) {
		std::cout << "WINNER - Player " << checkWinner() << "!\n";
	}
	else if (isFull()) {
		std::cout << "DRAW! No winner.\n";
	}
}

void TickTackToe::add(const char XO) {
	int x, y;
	std::cin >> x >> y;
	while (x > 2 || y > 2 || m_place[x][y] != ' ') {
		std::cout << "Invalid move. Try again: ";
		std::cin >> x >> y;
	}
	m_place[x][y] = XO;
}

void TickTackToe::print() {
	for (int i = 0; i < 3; ++i) {
		std::cout << std::endl;
		for (int j = 0; j < 3; ++j) {
			std::cout << " " << m_place[i][j];
			if (j < 2)
				std::cout << " |";
		}
		std::cout << std::endl;
		if(i < 2)
			std::cout << " -- --- -- ";
	}
}

bool TickTackToe::isEmpty() const {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (m_place[i][j] != ' ')
				return false;
		}
	}
	return true;
}

bool TickTackToe::isFull() const {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (m_place[i][j] == ' ')
				return false;
		}
	}
	return true;
}

bool TickTackToe::haveWinner() const {
	return (checkWinner() != ' ');
}

char TickTackToe::checkWinner() const {
	for (int i = 0; i < 3; ++i) {
		if (m_place[i][0] != ' ' &&
			m_place[i][0] == m_place[i][1] &&
			m_place[i][1] == m_place[i][2]) {
			return m_place[i][0];
		}
		if (m_place[0][i] != ' ' &&
			m_place[0][i] == m_place[1][i] &&
			m_place[1][i] == m_place[2][i]) {
			return m_place[0][i];
		}
	}

	if (m_place[0][0] != ' ' &&
		m_place[0][0] == m_place[1][1] &&
		m_place[1][1] == m_place[2][2]) {
		return m_place[0][0];
	}
	if (m_place[0][2] != ' ' &&
		m_place[0][2] == m_place[1][1] &&
		m_place[1][1] == m_place[2][0]) {
		return m_place[0][2];
	}

	return ' ';
}

bool TickTackToe::endGame() const {
	return (haveWinner() || isFull());
}