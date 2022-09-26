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

#include "maxProject6.h"

#define SampleKFCtrl_CLASS_ID	Class_ID(0x4e58f6a2, 0x51ad0d9e)

#define PBLOCK_REF	0

class SampleKFCtrl : public Control {
	public:

		// Parameter block
		IParamBlock2	*pblock;	//ref 0

		// Loading/Saving
		IOResult Load(ILoad *iload) {return IO_OK;}
		IOResult Save(ISave *isave) {return IO_OK;}

		//From Animatable
		Class_ID ClassID() {return SampleKFCtrl_CLASS_ID;}		
		SClass_ID SuperClassID() { return CTRL_POSITION_CLASS_ID; }
		void GetClassName(TSTR& s) {s = GetString(IDS_CLASS_NAME);}

		RefTargetHandle Clone( RemapDir &remap );
		RefResult NotifyRefChanged(const Interval& changeInt, RefTargetHandle hTarget, 
			PartID& partID, RefMessage message, BOOL propagate);


		int NumSubs() { return 1; }
		TSTR SubAnimName(int i) { return GetString(IDS_PARAMS); }				
		Animatable* SubAnim(int i) { return pblock; }

		// TODO: Maintain the number or references here
		int NumRefs() { return 1; }
		RefTargetHandle GetReference(int i) { return pblock; }
		void SetReference(int i, RefTargetHandle rtarg) { pblock=(IParamBlock2*)rtarg; }

		int	NumParamBlocks() { return 1; }					// return number of ParamBlocks in this instance
		IParamBlock2* GetParamBlock(int i) { return pblock; } // return i'th ParamBlock
		IParamBlock2* GetParamBlockByID(BlockID id) { return (pblock->ID() == id) ? pblock : NULL; } // return id'd ParamBlock

		void DeleteThis() { delete this; }		
		
		//Constructor/Destructor
		SampleKFCtrl() {}
		~SampleKFCtrl() {}

};



class SampleKFCtrlClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return new SampleKFCtrl(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return CTRL_POSITION_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return SampleKFCtrl_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("SampleKFCtrl"); } // Returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetSampleKFCtrlDesc()
{
	static SampleKFCtrlClassDesc SampleKFCtrlDesc;
	return &SampleKFCtrlDesc; 
}






