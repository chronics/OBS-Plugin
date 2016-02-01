#pragma once

//#include <Windows.h>

#include "OBSApi.h"
extern "C" __declspec(dllexport) bool LoadPlugin();
extern "C" __declspec(dllexport) void UnloadPlugin();
extern "C" __declspec(dllexport) CTSTR GetPluginName();
extern "C" __declspec(dllexport) CTSTR GetPluginDescription();


class TutorialImage : public ImageSource{
    VertexBuffer *box;
    Texture *tex;

public:
    TutorialImage(XElement *data);
    void Render(const Vect2 &pos, const Vect2 &size);
    Vect2 GetSize() const;
};

class TestPlugin
{
public:
	TestPlugin();
	~TestPlugin();
	void getSystemInputs();
};

