#pragma once

#include "GameState.hpp"

#include <stack>

class StateManager {
public:
	void pushState(GameState* state) { this->states.push(state); }
	void popState() { this->states.pop(); }
	void changeState(GameState* state) {
		if (!this->states.empty())
			popState();

		pushState(state);
	}

	GameState* peekState() {
		if (this->states.empty())
			return nullptr;

		return this->states.top();
	}

public:
	std::stack<GameState*> states;
};