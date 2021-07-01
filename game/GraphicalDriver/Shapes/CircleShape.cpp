#include "CircleShape.h"

using namespace se;

CircleShape::CircleShape() {
    circle_shape_ = new sf::CircleShape;
    object_ = circle_shape_;
    size_object_ = circle_shape_;
}

void CircleShape::setRadius(float radius) {
    circle_shape_->setRadius(radius);
}

void CircleShape::setFillColor(const Color& color) {
    circle_shape_->setFillColor(color.getColor());
}

void CircleShape::setOutlineColor(const Color& color) {
    circle_shape_->setOutlineColor(color.getColor());
}

void CircleShape::setOutlineThickness(float thickness) {
    circle_shape_->setOutlineThickness(thickness);
}

// Getters
float CircleShape::getRadius() {
    return circle_shape_->getRadius();
}

Color CircleShape::getFillColor() {
    sf::Color tmp = circle_shape_->getFillColor();
    return Color(tmp.r, tmp.g, tmp.b);
}
        
Color CircleShape::getOutlineColor() {
    sf::Color tmp = circle_shape_->getOutlineColor();
    return Color(tmp.r, tmp.g, tmp.b);
}

float CircleShape::getOutlineThickness() {
    return circle_shape_->getOutlineThickness();
}

CircleShape::~CircleShape() {
    delete object_;
}