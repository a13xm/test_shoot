#ifndef BoardModel_h
#define BoardModel_h

#include <boost/ptr_container/ptr_vector.hpp>
#include "ModelTarget.h"

class ModelBoard;
typedef std::unique_ptr<ModelBoard> ModelBoardPtr;

/*
	Доска с мишенями, спавнит, удаленяет, двигает мишени
	Должна обновляться в основном игровом цикле
	Предоставляет контейнер с мишенями для отрисовки
 */
class ModelBoard {
	
public:
	ModelBoard();
	~ModelBoard();
	void Update(const float dt);
	void Draw();
	void CreateTargets();
	void Clear();

private:
	typedef boost::ptr_vector<ModelTarget> Targets;
	typedef Targets::iterator TargetIter;

	Targets _targets;
	EffectsContainer _effect_cont;
	
};

#endif /* BoardModel_h */
