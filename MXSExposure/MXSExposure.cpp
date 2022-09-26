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
#include <codeanalysis\warnings.h>
#pragma warning (disable : ALL_CODE_ANALYSIS_WARNINGS)

#include "MXSExposure.h"

#include "3dsmaxsdk_preinclude.h"
#include "resource.h"
#include <iparamb2.h>
#include <istdplug.h>
#include <iparamm2.h>
#include <maxtypes.h>

#define MXSExposure_CLASS_ID	Class_ID(0xb8b0b51a, 0x5d5832e9)


class MXSExposure : public GUP
{
public:
	//Constructor/Destructor
	MXSExposure();
	virtual ~MXSExposure();

	// GUP Methods
	virtual DWORD     Start();
	virtual void      Stop();
	virtual DWORD_PTR Control(DWORD parameter);
	virtual void      DeleteThis();

	// Loading/Saving
	virtual IOResult Save(ISave* isave);
	virtual IOResult Load(ILoad* iload);
};



class MXSExposureClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return new MXSExposure(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return GUP_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return MXSExposure_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("MXSExposureUtil"); } // Complemento de utilidad global #pragma warning
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetMXSExposureDesc()
{
	static MXSExposureClassDesc MXSExposureDesc;
	return &MXSExposureDesc; 
}




MXSExposure::MXSExposure()
{

}

MXSExposure::~MXSExposure()
{

}

void MXSExposure::DeleteThis()
{
	delete this;
}

// Activate and Stay Resident
DWORD MXSExposure::Start()
{
	//#pragma message(TODO("Do plugin initialization here"))
	//#pragma message(TODO("Return if you want remain loaded or not"))
	return GUPRESULT_KEEP;
}

void MXSExposure::Stop()
{
	//#pragma message(TODO("Do plugin un-initialization here"))
}

DWORD_PTR MXSExposure::Control( DWORD /*parameter*/ )
{
	return 0;
}

IOResult MXSExposure::Save(ISave* /*isave*/)
{
	return IO_OK;
}

IOResult MXSExposure::Load(ILoad* /*iload*/)
{
	return IO_OK;
}

