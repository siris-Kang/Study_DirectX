#pragma once

#include "Renderer/Renderable.h"
#include "Model/Model.h"

enum CharacterDirection
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
};

class Character : public Model
{
public:
	Character() = default;
	Character(const std::filesystem::path& filePath);
	virtual ~Character() = default;

	void HandleInput(const InputDirections& directions, FLOAT deltaTime);
	virtual void Update(FLOAT deltaTime);


	XMVECTOR m_targetPosition;
	XMVECTOR m_currentPosition;

protected:
	static constexpr const XMVECTORF32 DEFAULT_FORWARD = { 0.0f, 0.0f, 1.0f, 0.0f };
	static constexpr const XMVECTORF32 DEFAULT_RIGHT = { 1.0f, 0.0f, 0.0f, 0.0f };

	FLOAT m_moveLeftRight;
	FLOAT m_moveBackForward;

	CharacterDirection m_currentRotation;
	FLOAT m_movementSpeed;
};