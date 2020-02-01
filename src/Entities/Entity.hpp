//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ENTITY_HPP
#define DUNGEONINTERN_ENTITY_HPP


#include "../Position.hpp"
#include "../Rendering/Entity.hpp"

namespace DungeonIntern
{
	class Entity {
	private:
		//! @brief The entity used by the renderer.
		Rendering::Entity &_entity;
		//! @brief The speed at witch the entity move in the direction indicated by the _pos orientation value.
		float _speed = 0;
		//! @brief Position + Orientation of the entity.
		Position<float> _pos;
		//! @brief Will be deleted soon by the engine.
		bool _destroyed = false;
		Rendering::Screen &_screen;

	public:
		Entity(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, Orientation r = SOUTH);
		virtual ~Entity();

		template<typename type>
		type &to()
		{
			return dynamic_cast<type &>(*this);
		}
		bool destroyed() const;
		void destroy();
		void render();
		virtual void update() = 0;

		const Position<float> &getPos() const;

		void setPos(const Position<float> &pos);
	};
}


#endif //DUNGEONINTERN_ENTITY_HPP
