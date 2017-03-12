#include "stdafx.h"
#include "MainWidget.h"

MainWidget::MainWidget(const std::string& name, rapidxml::xml_node<>* xmlElement) : Widget(name) {
	_model_board = ModelBoardPtr(new ModelBoard);
	_model_board->CreateTargets();
}

void MainWidget::Init() {
}

void MainWidget::Update(float dt) {
	_model_board->Update(dt);
}

void MainWidget::Draw() {
	_model_board->Draw();
}

bool MainWidget::MouseDown(const IPoint &mouse_pos) {
	return true;
}

void MainWidget::MouseUp(const IPoint &mouse_pos) {
}

void MainWidget::MouseMove(const IPoint &mouse_pos) {
}
