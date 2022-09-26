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

#include "maxProject4.h"


#define maxProject4_CLASS_ID Class_ID(0x59a83256, 0x70799e98)

class maxProject4 : public UtilityObj
{
public:
	// Constructor/Destructor
	maxProject4();
	virtual ~maxProject4();

	virtual void DeleteThis() override {}
	
	virtual void BeginEditParams(Interface *ip,IUtil *iu) override;
	virtual void EndEditParams(Interface *ip,IUtil *iu) override;

	virtual void Init(HWND hWnd);
	virtual void Destroy(HWND hWnd);
	
	// Singleton access
	static maxProject4* GetInstance() { 
		static maxProject4 themaxProject4;
		return &themaxProject4; 
	}

private:
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND hPanel;
	IUtil* iu;
};


class maxProject4ClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return maxProject4::GetInstance(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return UTILITY_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return maxProject4_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("maxProject4"); } // Returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetmaxProject4Desc()
{
	static maxProject4ClassDesc maxProject4Desc;
	return &maxProject4Desc; 
}




//--- maxProject4 -------------------------------------------------------
maxProject4::maxProject4()
	: iu(nullptr)
	, hPanel(nullptr)
{

}

maxProject4::~maxProject4()
{

}

void maxProject4::BeginEditParams(Interface* ip,IUtil* iu) 
{
	this->iu = iu;
	hPanel = ip->AddRollupPage(
		hInstance,
		MAKEINTRESOURCE(IDD_PANEL),
		DlgProc,
		GetString(IDS_PARAMS),
		0);
}

void maxProject4::EndEditParams(Interface* ip,IUtil*)
{
	this->iu = nullptr;
	ip->DeleteRollupPage(hPanel);
	hPanel = nullptr;
}

void maxProject4::Init(HWND /*handle*/)
{

}

void maxProject4::Destroy(HWND /*handle*/)
{

}

INT_PTR CALLBACK maxProject4::DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
		case WM_INITDIALOG:
			maxProject4::GetInstance()->Init(hWnd);
			break;

		case WM_DESTROY:
			maxProject4::GetInstance()->Destroy(hWnd);
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
