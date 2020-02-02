//
// Created by andgel on 31/01/2020
//

#ifndef DUNGEONINTERN_ENTITY_HPP
#define DUNGEONINTERN_ENTITY_HPP


#include "../Position.hpp"
#include "../Size.hpp"
#include "../Rendering/Entity.hpp"

namespace DungeonIntern
{
	struct EntityConfig {
		Rendering::Screen &screen;
		const std::string &entityJsonPath;
		class Map &map;
	};

	class Entity {
	protected:
		//! @brief The entity used by the renderer.
		Rendering::Entity &_entity;
		//! @brief The speed at witch the entity move in the direction indicated by the _pos orientation value.
		float _speed = 0;
		float _maxSpeed = 0;
		const unsigned _maxHealth;
		unsigned _health;
		bool _dead = false;
		//! @brief Position + Orientation of the entity.
		Position<float> _pos;
		//! @brief Old Position for colision
		Position<float> _old_position = 0;
		//! @brief Size of the entity.
		Size<unsigned> _size;
		class Map &_map;
	protected:
		//! @brief Will be deleted soon by the engine.
		bool _destroyed = false;
		Rendering::Screen &_screen;

	public:
		Entity(unsigned maxHealth, EntityConfig cfg, float maxSpeed, float x, float y, unsigned sx, unsigned sy, Orientation r = SOUTH);
		virtual ~Entity();

		template<typename type>
		type &to()
		{
			return dynamic_cast<type &>(*this);
		}
		bool destroyed() const;
		void destroy();
		virtual void render();
		virtual void onCollide(Entity &other) = 0;
		virtual void update();
		bool collideWith(const Position<int> &pos, const Size<unsigned> &size) const;
		const Position<float> &getPos() const;

		void setPos(const Position<float> &pos);

		void move(double angle);

		float getSpeed() const;

		void setSpeed(float speed);

		virtual void takeDamage(unsigned damages);

		const Size<unsigned> & getSize() const;

		const Position<float> &getOldPosition() const;
		bool isDead() const;
		virtual void onDeath() = 0;
	};
}


#endif //DUNGEONINTERN_ENTITY_HPP
