#include "GameObject.h"

GameObject::GameObject(const sf::Vector2f &p_Position, const sf::Vector2f &p_Size)
	: m_Position(p_Position), m_Size(p_Size) {

}

GameObject::~GameObject() {

}

sf::Vector2f GameObject::getPosition() {
	return m_Position;
}
void GameObject::setPosition(const sf::Vector2f &p_Position) {
	m_Position = p_Position;
}

sf::Vector2f GameObject::getSize() {
	return m_Size;
}
void GameObject::setSize(const sf::Vector2f &p_Size) {
	m_Size = p_Size;
}