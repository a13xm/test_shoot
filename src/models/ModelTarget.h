#ifndef ModelTarget_h
#define ModelTarget_h

#include <stdio.h>

/*
	Мишень, хранит позицию, скорость, направление, размер
	Умеет отрисовываться - хранит текстуру, еффекты
	Должна обновляться в основном игровом цикле
 */
class ModelTarget {
	
public:
	FPoint position;
	float radius;
	float angle;
	float speed;
	Render::TexturePtr texture;

	ModelTarget();
	~ModelTarget();
	void Update(float dt);
	void Draw();
	
private:
	Render::TexturePtr _target_tex;
	math::Matrix4 _all_transforms;

};

#endif /* ModelTarget_h */
