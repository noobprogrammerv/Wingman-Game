#include "Game.h"

Game::Game(RenderWindow* window) {
	this->window = window;
	this->window->setFramerateLimit(60);

	//Init textures
	this->playerTexture.loadFromFile("C:/Users/Alex/source/repos/SFML/Wingman/Textures/ship.png");
	this->bulletTexture.loadFromFile("C:/Users/Alex/source/repos/SFML/Wingman/Textures/missile1.png");

	//Init player
	this->players.push_back(Player(&playerTexture, &bulletTexture));

}

Game::~Game() {

}

void Game::Update() {
	for (size_t i = 0; i < this->players.size(); i++)	{
		this->players[i].Update();
	}
}

void Game::Draw() {
	this->window->clear();

	for (size_t i = 0; i < this->players.size(); i++) {
		players[i].Draw(*this->window);
	}

	this->window->display();
}