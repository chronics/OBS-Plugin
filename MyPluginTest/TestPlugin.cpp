#include "TestPlugin.h"


UINT userColour = 0x801142FF, globColour = 0x800000FF;

void TestPlugin::getSystemInputs()
{

	if (GetAsyncKeyState('A') & 0x8000) // the 'A' key is currently being held down
	{
		globColour = userColour;
	}

}

TutorialImage::TutorialImage(XElement *data) {
	
	void getSystemInputs();
	
	VBData *points = new VBData;
	points->VertList.SetSize(4);              //Reserve space for the vertices
	box = CreateVertexBuffer(points, FALSE);  //Store the vertex list in a vertex buffer
	UINT color = globColour;                  //Color is 0xAABBGGRR on little-endian machines
	tex = CreateTexture(1, 1, GS_RGBA, &color, FALSE, TRUE);  //Create a 1x1 translucent red texture
}
void TutorialImage::Render(const Vect2 &pos, const Vect2 &size) {
	VBData *data = box->GetData();               //Fill our vertex buffer object with a square that
	data->VertList[0].Set(pos.x, pos.y, 0);      //occupies our entire drawing region
	data->VertList[1].Set(pos.x, pos.y + size.y, 0);
	data->VertList[2].Set(pos.x + size.x, pos.y, 0);
	data->VertList[3].Set(pos.x + size.x, pos.y + size.y, 0);
	box->FlushBuffers();         //Flush the software representation of the vertices to the GPU
	LoadVertexBuffer(box);     //Prepare the vertex buffer we just created for drawing
	LoadTexture(tex);          //Load our 1x1 texture for drawing
	Draw(GS_TRIANGLESTRIP);    //Draw our vertices as a triangle strip.
}
Vect2 TutorialImage::GetSize() const {  //Return the size of our image. This can be
	Vect2 ret;                         //anything you want. This just determines the
	ret.x = 100;                       //standard size of your plugin image.
	ret.y = 100;                       //You can also change this as much as you want
	return ret;                        //during runtime.
}

ImageSource* STDCALL CreateTutorialImage(XElement *data) {
	return new TutorialImage(data);
}

bool LoadPlugin()
{
	OBSRegisterImageSourceClass(TEXT("TutorialImage"), TEXT("My Image Source"), (OBSCREATEPROC)CreateTutorialImage, (OBSCONFIGPROC)NULL);
	return true;
}

void UnloadPlugin()
{
}

CTSTR GetPluginName()
{
	return TEXT("My plugin");
}

CTSTR GetPluginDescription()
{
	return TEXT("This should be a red box so far.");
}


TestPlugin::TestPlugin()
{
}


TestPlugin::~TestPlugin()
{
}
