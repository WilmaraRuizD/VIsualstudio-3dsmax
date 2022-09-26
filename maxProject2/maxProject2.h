#pragma once

#include "3dsmaxsdk_preinclude.h"
#include "resource.h"
#include <istdplug.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <maxtypes.h>
//SIMPLE TYPE


extern TCHAR* GetString(int id);

extern HINSTANCE hInstance;

class SampleProCtrl : public Control
{

public:

	SampleProCtrl() {};
	~SampleProCtrl() {};

	SClass_ID SuperClassID() { return CTRL_POSITION_CLASS_ID; }

	int NumRefs() { return 0; }
	void SetReference(int i, ReferenceTarget* pTarget) {}
	ReferenceTarget* GetReference(int i) { return NULL; }
	RefResult NotifyRefChanged(const Interval&, RefTargetHandle, PartID&, RefMessage, BOOL) { return REF_DONTCARE; }

	void Copy(Control* pFrom) {}

	void GetValue(TimeValue t, void* ptr, Interval& valid, GetSetMethod method);
	void SetValue(TimeValue t, void* ptr, int commit, GetSetMethod method);
};