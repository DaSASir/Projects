#pragma once
#include <string>
#include <vector>

class TickTackToe {
public:
	TickTackToe();
	void play();
	void playPC();

private:
	void play_2players();
	void play_PC();
	bool tryWin(char XO);
	bool tryBlock(char opponent, char XO);

	void add(const char XO);
	void movePC(const char XO);
	
	void print();

	void finish();
	bool endGame() const;

	bool isEmpty() const;
	bool isFull() const;
	bool haveWinner() const;
	char checkWinner() const;

private:
	std::vector<std::vector<char>> m_place;
};