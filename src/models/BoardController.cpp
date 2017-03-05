#include "stdafx.h"
#include "BoardController.h"

void BoardController::Update(float dt) {
	Log::Debug(std::string("update[") + getName() + std::string("]; dt = ") + utils::lexical_cast(dt));
}

bool BoardController::isFinish() {
	return false;
}
