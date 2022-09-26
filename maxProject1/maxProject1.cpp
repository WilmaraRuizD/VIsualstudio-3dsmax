//**************************************************************************/
// Copyright (c) 1998-2018 Autodesk, Inc.
// All rights reserved.
// 
// Use of this software is subject to the terms of the Autodesk license 
// agreement provided at the time of installation or download, or which 
// otherwise accompanies this software in either electronic or hard copy form.
//**************************************************************************/
// DESCRIPTION: Appwizard generated plugin
// AUTHOR: 
//***************************************************************************/

#include "maxProject1.h"


#define maxProject1_CLASS_ID Class_ID(0x44f1e80f, 0x75c164db)

class maxProject1 : public UtilityObj
{
public:
	// Constructor/Destructor
	maxProject1();
	virtual ~maxProject1();

	virtual void DeleteThis() override {}
	
	virtual void BeginEditParams(Interface *ip,IUtil *iu) override;
	virtual void EndEditParams(Interface *ip,IUtil *iu) override;

	virtual void Init(HWND hWnd);
	virtual void Destroy(HWND hWnd);
	
	// Singleton access
	static maxProject1* GetInstance() { 
		static maxProject1 themaxProject1;
		return &themaxProject1; 
	}

private:
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND hPanel;
	IUtil* maxiu;
};


class maxProject1ClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return maxProject1::GetInstance(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return UTILITY_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return maxProject1_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("maxProject1"); } // Returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetmaxProject1Desc()
{
	static maxProject1ClassDesc maxProject1Desc;
	return &maxProject1Desc; 
}




//--- maxProject1 -------------------------------------------------------
maxProject1::maxProject1()
	: maxiu(nullptr)
	, hPanel(nullptr)
{

}

maxProject1::~maxProject1()
{

}

void maxProject1::BeginEditParams(Interface* maxint,IUtil* maxiu) 
{
	this->maxiu = maxiu;
	hPanel = maxint->AddRollupPage(
		hInstance,
		MAKEINTRESOURCE(IDD_PANEL),
		DlgProc,
		GetString(IDS_PARAMS),
		0);

	maxint->PushPrompt(_M("Hola Mundo, Creado por Wilmara Ruiz"));
	//se imprimer el mensaje cuando se hace click en el marcador indicado
	DebugPrint(_M("Se a realizado click en el indicador"));
}

void maxProject1::EndEditParams(Interface* ip,IUtil*)
{
	this->maxiu = nullptr;
	ip->DeleteRollupPage(hPanel);
	hPanel = nullptr;
	//se imprimer el mensaje cuando se hace click en el marcador indicado
	DebugPrint(_M("La promesa se a disparado "));

}

void maxProject1::Init(HWND /*handle*/)
{

}

void maxProject1::Destroy(HWND /*handle*/)
{

}

INT_PTR CALLBACK maxProject1::DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
		case WM_INITDIALOG:
			maxProject1::GetInstance()->Init(hWnd);
			break;

		case WM_DESTROY:
			maxProject1::GetInstance()->Destroy(hWnd);
			break;

		case WM_COMMAND:
			#pragma message(TODO("React to the user interface commands.  A utility plug-in is controlled by the user from here."))
			break;

		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_MOUSEMOVE:
			GetCOREInterface()->RollupMouseMessage(hWnd,msg,wParam,lParam);
			break;

		default:
			return 0;
	}
	return 1;
}
