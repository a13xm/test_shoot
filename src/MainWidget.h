#ifndef MainWidget_h
#define MainWidget_h

#include "models/ModelBoard.h"

class MainWidget : public GUI::Widget {

public:
	MainWidget(const std::string& name, rapidxml::xml_node<>* xmlElement);
	void Update(float dt) override;
	void Draw() override;
	
	bool MouseDown(const IPoint& mouse_pos) override;
	void MouseMove(const IPoint& mouse_pos) override;
	void MouseUp(const IPoint& mouse_pos) override;

private:
	void Init();

	ModelBoardPtr _model_board;
};


#endif /* MainWidget_h */
