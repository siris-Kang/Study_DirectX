#include "Character/Character.h"


Character::Character(_In_ const std::filesystem::path& filePath)
    : Model(filePath)
	, m_targetPosition()
	, m_currentPosition()
	, m_moveLeftRight(0.0f)
	, m_moveBackForward(0.0f)
	, m_currentRotation(DOWN)
	, m_movementSpeed(10.0f)
{

}


void Character::HandleInput(const InputDirections& directions, FLOAT deltaTime)
{
    if (directions.bFront)
    {
        m_moveBackForward += m_movementSpeed * deltaTime;
        if (m_currentRotation == UP)
        {
            ;
        }
        else if (m_currentRotation == DOWN)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(180), m_currentPosition);
        }
        else if (m_currentRotation == RIGHT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(270), m_currentPosition);
        }
        else if (m_currentRotation == LEFT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(90), m_currentPosition);
        }
        m_currentRotation = UP;
    }

    if (directions.bLeft)
    {
        m_moveLeftRight -= m_movementSpeed * deltaTime;
        if (m_currentRotation == UP)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(270), m_currentPosition);
        }
        else if (m_currentRotation == DOWN)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(90), m_currentPosition);
        }
        else if (m_currentRotation == RIGHT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(180), m_currentPosition);
        }
        else if (m_currentRotation == LEFT)
        {
            ;
        }
        m_currentRotation = LEFT;
    }

    if (directions.bBack)
    {
        m_moveBackForward -= m_movementSpeed * deltaTime;
        if (m_currentRotation == UP)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(180), m_currentPosition);
        }
        else if (m_currentRotation == DOWN)
        {
            ;
        }
        else if (m_currentRotation == RIGHT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(90), m_currentPosition);
        }
        else if (m_currentRotation == LEFT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(270), m_currentPosition);
        }
        m_currentRotation = DOWN;
    }

    if (directions.bRight)
    {
        m_moveLeftRight += m_movementSpeed * deltaTime;
        if (m_currentRotation == UP)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(90), m_currentPosition);
        }
        else if (m_currentRotation == DOWN)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(270), m_currentPosition);
        }
        else if (m_currentRotation == RIGHT)
        {
            ;
        }
        else if (m_currentRotation == LEFT)
        {
            RotateYInObjectCoordinate(XMConvertToRadians(180), m_currentPosition);
        }
        m_currentRotation = RIGHT;
    }
}

void Character::Update(FLOAT deltaTime)
{
    m_targetPosition = m_currentPosition + (m_moveBackForward * DEFAULT_FORWARD) + (m_moveLeftRight * DEFAULT_RIGHT);

    m_moveLeftRight = 0.0f;
    m_moveBackForward = 0.0f;

    Translate(m_targetPosition - m_currentPosition);

    m_currentPosition = m_targetPosition;
}
