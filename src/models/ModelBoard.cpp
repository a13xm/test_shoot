#include "stdafx.h"
#include "ModelBoard.h"

ModelBoard::ModelBoard() {
}

ModelBoard::~ModelBoard() {
	_targets.clear();
}

void ModelBoard::Update(const float dt) {
//	Log::Debug(std::string("update dt = ") + utils::lexical_cast(dt));
	for (auto it = _targets.begin(), e = _targets.end(); it != e;) {
		if (false) {
			it = _targets.erase(it);
			e = _targets.end();
		} else {
			it->Update(dt);
			it++;
		}
	}
}

void ModelBoard::Draw() {
//	Render::device.PushMatrix();
//	Render::device.MatrixRotate(math::Vector3(0, 0, 1), 30);
//	Render::device.PushMatrix();
//	Render::device.MatrixScale(1.5, 0.75, 1);

	Render::device.SetTexturing(false);
	Render::BeginColor(Color(255, 0, 0, 255));
	Render::DrawFrame(IRect(0, 0, 800, 600));
	Render::EndColor();
	Render::device.SetTexturing(true);

	for (ModelTarget target : _targets) {
		target.Draw();
	}
//	Render::device.PopMatrix();
//	Render::device.PopMatrix();
}

void ModelBoard::CreateTargets() {
	for (size_t i = 0; i < 10; i++) {
		ModelTarget* target = new ModelTarget;
		target->position.x = math::random(0, 800);
		target->position.y = math::random(0, 600);
		target->angle = math::random(0.0f, 2*math::PI);
		target->speed = math::random(170.0f, 200.0f);
		target->radius = 50;
		_targets.push_back(target);
	}
}

void ModelBoard::Clear() {
	_targets.clear();
}
