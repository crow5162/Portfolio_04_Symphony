#include "stdafx.h"
#include "action.h"


action::action()
{
}


action::~action()
{
}

HRESULT action::init()
{
	_callbackFunction = NULL;
	_worldTimeCount = 0;
	_isMoving = false;

	return S_OK;
}

void action::release()
{
}

void action::update()
{
	//moving();
	TestMoving();
}

void action::render()
{
}

void action::TestMoveTo(float startX, float startY, float endX, float endY, float time)
{
	if (!_isMoving)
	{
		_callbackFunction = NULL;

		_startX = startX;
		_startY = startY;

		_endX = endX;
		_endY = endY;

		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		_angle = getAngle(_startX, _startY, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;

	}
}

void action::moveTo(image * image, float endX, float endY, float time)
{
	if (!_isMoving)
	{
		_callbackFunction = NULL;

		_image = image;

		_startX = _image->getX();
		_startY = _image->getY();

		_endX = endX;
		_endY = endY;

		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		_angle = getAngle(_startX, _startY, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;

	}

}

void action::moveTo(image * image, float endX, float endY, float time, CALLBACK_FUNCTION cbFunction)
{
	if (!_isMoving)
	{
		_callbackFunction = static_cast<CALLBACK_FUNCTION>(cbFunction);

		_image = image;

		_startX = _image->getX();
		_startY = _image->getY();

		_endX = endX;
		_endY = endY;

		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		_angle = getAngle(_startX, _startY, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;

	}
}

void action::moving()
{
	if (!_isMoving) return;

	float elapsedTime = TIMEMANAGER->getElapsedTime();

	float moveSpeed = (elapsedTime / _time) * _travelRange;

	_image->setX(_image->getX() + cosf(_angle) * moveSpeed);
	_image->setY(_image->getY() + (-sinf(_angle) * moveSpeed));

	float time = TIMEMANAGER->getElapsedTime();

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_image->setX(_endX);
		_image->setY(_endY);
		_isMoving = false;

		if (_callbackFunction != NULL)
		{
			_callbackFunction();
		}

	}

}

void action::TestMoving()
{
	if (!_isMoving) return;

	float elapsedTime = TIMEMANAGER->getElapsedTime();

	float moveSpeed = (elapsedTime / _time) * _travelRange;

	_startX += cosf(_angle) * moveSpeed;
	_startY += -sinf(_angle) * moveSpeed;

	float time = TIMEMANAGER->getElapsedTime();

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_startX = _endX;
		_startY = _endY;
		_isMoving = false;

		if (_callbackFunction != NULL)
		{
			_callbackFunction();
		}

	}
}
