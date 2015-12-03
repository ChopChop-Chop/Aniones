#pragma once
#include <fmod.h>

class CSoundManager
{
public:
	bool Init();
	FMOD_SOUND* getFMOD_SOUND(const char* a_sFileName, bool repeat);
	void playSound(FMOD_SOUND* a_pSound);
	void stopSound();
	void Update();
	void Release();

	CSoundManager();
	~CSoundManager();

public:
	bool _isSoundOn;

	FMOD_SYSTEM* _soundSystem;
	FMOD_CHANNEL* _channel;

};

