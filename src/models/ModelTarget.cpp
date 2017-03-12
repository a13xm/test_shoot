#include "stdafx.h"
#include "ModelTarget.h"
#include <boost/geometry/geometry.hpp>

ModelTarget::ModelTarget():_all_transforms(math::Matrix4::Identity) {
	_target_tex = Core::resourceManager.Get<Render::Texture>("Circle");
}

ModelTarget::~ModelTarget() {
	
}

void ModelTarget::Update(float dt) {
	position.x += math::cos(angle) * speed * dt;
	position.y += math::sin(angle) * speed * dt;
	if (position.x >= 800.0f) {
		position.x = 800.0f;
		angle = math::PI - angle;
	} else if (position.x <= 0.0f) {
		position.x = 0.0f;
		angle = math::PI - angle;
	}
	
	if (position.y >= 600.0f) {
		position.y = 600.0f;
		angle = 2*math::PI - angle;
	} else if (position.y <= 0.0f	) {
		position.y = 0.0f;
		angle = 2*math::PI - angle;
	}
	_all_transforms = math::Matrix4::Identity;
}

void ModelTarget::Draw() {
	
	IRect texRect = _target_tex->getBitmapRect();
	FRect rect(texRect);
	FRect uv(0, 1, 0, 1);
	
	_target_tex->TranslateUV(rect, uv);
	
	Render::device.PushMatrix();
	Render::device.MatrixTranslate(position.x, position.y, 0.0f);
	Render::device.MatrixScale(100.0f/texRect.width);
	Render::device.MatrixRotate(math::Vector3(0, 0, 1), boost::geometry::math::r2d * angle);
	Render::device.MatrixTranslate(-texRect.width * 0.5f, -texRect.height * 0.5f, 0.0f);
	_target_tex->Bind();
	Render::DrawQuad(rect, uv);
	Render::device.PopMatrix();
	
}
