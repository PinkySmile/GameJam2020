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
		Rendering::Entity &_entity;
		float _speed = 0;
		Position<float> _pos;
		bool _destroyed = false;

	public:
		Entity(Rendering::Screen &screen, const std::string &entityJsonPath, float x, float y, Orientation r = SOUTH);
		virtual ~Entity() = default;

		template<typename type>
		type &to()
		{
			return dynamic_cast<type &>(*this);
		}
		bool destroyed() const;
		void destroy();
		virtual void render() = 0;
		virtual void update() = 0;

		const Position<float> &getPos() const;

		void setPos(const Position<float> &pos);
	};
}


#endif //DUNGEONINTERN_ENTITY_HPP
