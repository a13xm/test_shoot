//
//  BoardController.h
//  Test
//
//  Created by alexandre on 05/03/2017.
//
//

#ifndef BoardController_h
#define BoardController_h

class BoardController : public IController {
	
public:
	BoardController() : IController("board_controller") {};

	void Update(float dt) override;
	bool isFinish() override;
	
};

#endif /* BoardController_h */
