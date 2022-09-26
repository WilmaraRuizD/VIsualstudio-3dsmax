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

#include "maxProject3.h"
#include <simpobj.h>


#define maxProject3_CLASS_ID Class_ID(0x61affe28, 0x553aa216)

class maxProject3 : public UtilityObj
{
public:
	// Constructor/Destructor
	maxProject3();
	virtual ~maxProject3();

	virtual void DeleteThis() override {}
	
	virtual void BeginEditParams(Interface *ip,IUtil *iu) override;
	virtual void EndEditParams(Interface *ip,IUtil *iu) override;

	virtual void Init(HWND hWnd);
	virtual void Destroy(HWND hWnd);
	
	// Singleton access
	static maxProject3* GetInstance() { 
		static maxProject3 themaxProject3;
		return &themaxProject3; 
	}

private:
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND hPanel;
	IUtil* iu;
};


class maxProject3ClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return maxProject3::GetInstance(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return UTILITY_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return maxProject3_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("maxProject3"); } // Returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetmaxProject3Desc()
{
	static maxProject3ClassDesc maxProject3Desc;
	return &maxProject3Desc; 
}




//--- maxProject3 -------------------------------------------------------
maxProject3::maxProject3()
	: iu(nullptr)
	, hPanel(nullptr)
{

}
//se rea una clase 
maxProject3::~maxProject3()
{

}
///se define la clase para modificar el ojeto 
class SampleGObject : public SimpleObject2
{
public:

	SampleGObject() : objSize(2.0) { }

	// Member variable
	double objSize;

	// From BaseObject
	CreateMouseCallBack* GetCreateMouseCallBack() { return NULL; }

	// From SimpleObject
	void BuildMesh(TimeValue t);

	//From Animatable
	//Class_ID ClassID() { return SampleGObject_CLASS_ID; }
	//SClass_ID SuperClassID() { return GEOMOBJECT_CLASS_ID; }
	//void GetClassName(TSTR& s) { s = "Sample Geometric Object"; }

	void DeleteThis() { delete this; }
};
///funcion se hace referencia a la clases

void SampleGObject::BuildMesh(TimeValue t)
{
	ivalid = FOREVER;
	mesh.setNumVerts(4);//numero de caras 
	mesh.setNumFaces(3);//numero de vertices 
	mesh.setVert(0, objSize * Point3(0.0, 0.0, 0.0));//posicion de vertice 
	mesh.setVert(1, objSize * Point3(20.0, 0.0, 0.0));//configuracion de los vertices 
	mesh.setVert(2, objSize * Point3(0.0, 20.0, 0.0));
	mesh.setVert(3, objSize * Point3(0.0, 0.0, 20.0));

	mesh.faces[0].setVerts(0, 1, 2);
	mesh.faces[0].setEdgeVisFlags(1, 1, 0);
	mesh.faces[0].setSmGroup(2);
	mesh.faces[1].setVerts(3, 1, 0);
	mesh.faces[1].setEdgeVisFlags(1, 1, 0);
	mesh.faces[1].setSmGroup(2);
	mesh.faces[2].setVerts(0, 2, 3);
	mesh.faces[2].setEdgeVisFlags(1, 1, 0);
	mesh.faces[2].setSmGroup(4);

	mesh.InvalidateGeomCache();
}



//funcion que desaparece cuando sueltan el boton 
void maxProject3::BeginEditParams(Interface* ip,IUtil* iu) 
{
	SampleGObject* myGeomObj = new SampleGObject();
	INode* node = ip->CreateObjectNode(myGeomObj);
	TimeValue t(0);//indicarle el tiempo inicial
	Matrix3 tm(1);//matrix 
	node->SetNodeTM(t, tm);
}
//se llama a las funciones cuando se presiona el boton de utilite 
void maxProject3::EndEditParams(Interface* ip,IUtil*)
{
	this->iu = nullptr;
	ip->DeleteRollupPage(hPanel);
	hPanel = nullptr;


}

void maxProject3::Init(HWND /*handle*/)
{

}

void maxProject3::Destroy(HWND /*handle*/)
{

}

INT_PTR CALLBACK maxProject3::DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{
		case WM_INITDIALOG:
			maxProject3::GetInstance()->Init(hWnd);
			break;

		case WM_DESTROY:
			maxProject3::GetInstance()->Destroy(hWnd);
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
