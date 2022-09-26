#pragma once

//**************************************************************************/
// Copyright (c) 1998-2018 Autodesk, Inc.
// All rights reserved.
// 
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.
//**************************************************************************/
// DESCRIPTION: Includes for Plugins
// AUTHOR: 
//***************************************************************************/

#include "3dsmaxsdk_preinclude.h"
#include "resource.h"
#include <istdplug.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <maxtypes.h>
#include <Simpobj.h>
#include <mouseman.h>
//SIMPLE TYPE

#include <mouseman.h>
#include <triobj.h>



extern TCHAR *GetString(int id);

extern HINSTANCE hInstance;

enum { samplegobject2_params };


// TODO: Add enums for various parameters
enum { 
	pb_spin,
};


