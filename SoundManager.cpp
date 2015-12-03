#include "SoundManager.h"
#include <Windows.h>

CSoundManager::CSoundManager()
{
	_isSoundOn = false;
}


CSoundManager::~CSoundManager()
{
}

bool CSoundManager::Init()
{
	FMOD_System_Create(&_soundSystem);
	FMOD_System_Init(_soundSystem, 1, FMOD_INIT_NORMAL, NULL);

	return true;
}
FMOD_SOUND* CSoundManager::getFMOD_SOUND(const char* a_sFileName, bool repeat)
{
	FMOD_SOUND* temp;
	if (repeat)
	{
		FMOD_System_CreateSound(_soundSystem, a_sFileName, FMOD_LOOP_NORMAL, 0, &temp);
	}
	else
	{
		FMOD_System_CreateSound(_soundSystem, a_sFileName, FMOD_DEFAULT, 0, &temp);
	}

	return temp;
}
void CSoundManager::playSound(FMOD_SOUND* a_pSound)
{
	FMOD_System_PlaySound(_soundSystem, FMOD_CHANNEL_FREE, a_pSound, 0, &_channel);
	_isSoundOn = true;
}
void CSoundManager::stopSound()
{
	FMOD_Channel_Stop(_channel);
	_isSoundOn = false;
}
void CSoundManager::Update()
{
	if (_isSoundOn)
	{
		FMOD_System_Update(_soundSystem);
	}
}
void CSoundManager::Release()
{
	FMOD_System_Close(_soundSystem);
	FMOD_System_Release(_soundSystem);
}