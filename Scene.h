#pragma once
#include "Node.h"

class CScene : public CNode
{
public:
	virtual void Update() {}

	virtual void KeyDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void KeyUp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void LButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void LButtonUp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void RButtonDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void RButtonUp(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void LButtonDBClick(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {}
	virtual void RButtonDBClick(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {}

	CScene();
	virtual ~CScene();
};

