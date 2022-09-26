#include "sceneGraph.h"

#define sceneGraph_CLASS_ID	Class_ID(0x0fea4743, 0x62776eec)

class sceneGraph : public SceneExport {
public:
	//Constructor/Destructor
	sceneGraph();
	~sceneGraph();

	static HWND hParams;

	int				ExtCount();					// Number of extensions supported
	const TCHAR *	Ext(int n);					// Extension #n (i.e. "3DS")
	const TCHAR *	LongDesc();					// Long ASCII description (i.e. "Autodesk 3D Studio File")
	const TCHAR *	ShortDesc();				// Short ASCII description (i.e. "3D Studio")
	const TCHAR *	AuthorName();				// ASCII Author name
	const TCHAR *	CopyrightMessage();			// ASCII Copyright message
	const TCHAR *	OtherMessage1();			// Other message #1
	const TCHAR *	OtherMessage2();			// Other message #2
	unsigned int	Version();					// Version number * 100 (i.e. v3.01 = 301)
	void			ShowAbout(HWND hWnd);		// Show DLL's "About..." box

	BOOL SupportsOptions(int ext, DWORD options);
	int  DoExport(const TCHAR *name,ExpInterface *ei,Interface *i, BOOL suppressPrompts=FALSE, DWORD options=0);

	//SE CONFIGURA LAS 3 FUNCIONES AUXILIARES Usamos tres funciones auxiliares llamadas Lesson2::BeginWriting() , SampleExp::Write() y Lesson2::EndWriting() 

private:

	void Export(INode* pNode, int iTreeDepth = 0);

	FILE* m_pFile;

	BOOL BeginWriting(const TCHAR* pPath);

	void EndWriting();

	void Write(int indent, const MCHAR* pMsg, ...);

};





class sceneGraphClassDesc : public ClassDesc2 
{
public:
	virtual int           IsPublic() override                       { return TRUE; }
	virtual void*         Create(BOOL /*loading = FALSE*/) override { return new sceneGraph(); }
	virtual const TCHAR * ClassName() override                      { return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID     SuperClassID() override                   { return SCENE_EXPORT_CLASS_ID; }
	virtual Class_ID      ClassID() override                        { return sceneGraph_CLASS_ID; }
	virtual const TCHAR*  Category() override                       { return GetString(IDS_CATEGORY); }

	virtual const TCHAR*  InternalName() override                   { return _T("sceneGraph"); } // Returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE     HInstance() override                      { return hInstance; } // Returns owning module handle


};

ClassDesc2* GetsceneGraphDesc()
{
	static sceneGraphClassDesc sceneGraphDesc;
	return &sceneGraphDesc; 
}





INT_PTR CALLBACK sceneGraphOptionsDlgProc(HWND hWnd,UINT message,WPARAM,LPARAM lParam) {
	static sceneGraph* imp = nullptr;

	switch(message) {
		case WM_INITDIALOG:
			imp = (sceneGraph *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;

		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}


//--- sceneGraph -------------------------------------------------------
sceneGraph::sceneGraph()
{
	m_pFile = NULL; //SE INICIALIZA

}

sceneGraph::~sceneGraph() 
{
	DbgAssert(m_pFile == NULL);//SE VERIFICA QUE ESTE NULL
}

int sceneGraph::ExtCount()
{
	//#pragma message(TODO("Returns the number of file name extensions supported by the plug-in."))
	return 1;
}

const TCHAR *sceneGraph::Ext(int n)
{		
	//#pragma message(TODO("Return the 'i-th' file name extension (i.e. \"3DS\")."))
	return _T("txt");
}

const TCHAR *sceneGraph::LongDesc()
{
	#pragma message(TODO("Return long ASCII description (i.e. \"Targa 2.0 Image File\")"))
	return _T("Basic ASCII Scene Exporter");
}
	
const TCHAR *sceneGraph::ShortDesc() 
{			
	//#pragma message(TODO("Return short ASCII description (i.e. \"Targa\")"))
	return _T("Lesson2-ASCII");
}

const TCHAR *sceneGraph::AuthorName()
{			
	//#pragma message(TODO("Return ASCII Author name"))
	return _T("Your Name");
}

const TCHAR *sceneGraph::CopyrightMessage() 
{	
	//#pragma message(TODO("Return ASCII Copyright message"))
	return _T("copyrigth: your Studio");
}

const TCHAR *sceneGraph::OtherMessage1() 
{		
	//TODO: Return Other message #1 if any
	return _T("");
}

const TCHAR *sceneGraph::OtherMessage2() 
{		
	//TODO: Return other message #2 in any
	return _T("");
}

unsigned int sceneGraph::Version()
{				
	#pragma message(TODO("Return Version number * 100 (i.e. v3.01 = 301)"))
	return 100;
}

void sceneGraph::ShowAbout(HWND /*hWnd*/)
{			
	// Optional
}

BOOL sceneGraph::SupportsOptions(int ext, DWORD options)
{
	#pragma message(TODO("Decide which options to support.  Simply return true for each option supported by each Extension the exporter supports."))
	return TRUE;
}


int	sceneGraph::DoExport(const TCHAR *name, ExpInterface *ei, Interface *i, BOOL suppressPrompts, DWORD options)
{
//	#pragma message(TODO("Implement the actual file Export here and"))

	//if(!suppressPrompts)
	//	DialogBoxParam(hInstance, 
	//			MAKEINTRESOURCE(IDD_PANEL), 
	//			GetActiveWindow(), 
	//			sceneGraphOptionsDlgProc, (LPARAM)this);
//	#pragma message(TODO("return TRUE If the file is exported properly"))
	if (BeginWriting(name))
	{

		INode* pRootNode = i->GetRootNode();

		//Export tree.
		Export(pRootNode);

		EndWriting();

		return TRUE; // We have successfully exported to our file!
	}
	return FALSE;
}

void sceneGraph::Export(INode* pNode, int iTreeDepth /* = 0 */) {
	MCHAR* pNodeName = const_cast<MCHAR*>(pNode->GetName());
	int nChildren = pNode->NumberOfChildren();

	// Write out this node as [NodeName] : XX Children
	Write(iTreeDepth, _T("[%s] : %i children"), pNodeName, nChildren);

	// Recursively call the children
	iTreeDepth++;
	for (int i = 0; i < nChildren; i++)
	{
		Export(pNode->GetChildNode(i), iTreeDepth);
	}

}
BOOL sceneGraph::BeginWriting(const TCHAR* pPath)
{
	// Check we are not currently writing
	DbgAssert(m_pFile == NULL);

	errno_t lErr = _tfopen_s(&m_pFile, pPath, TEXT("w"));
	return lErr == 0;
}

void sceneGraph::EndWriting()
{
	DbgAssert(m_pFile != NULL);

	fclose(m_pFile);
	m_pFile = NULL;
}

void sceneGraph::Write(int indent, const MCHAR* pMsg, ...)
{
	DbgAssert(m_pFile != NULL);

	// first, write in the indent
	for (int i = 0; i < indent; i++) _ftprintf(m_pFile, _T("\t"));

	// Write the message, passing in our variable
	// parameters to a function that wraps printf
	va_list vargs;
	va_start(vargs, pMsg);
	vfwprintf(m_pFile, pMsg, vargs);
	va_end(vargs);

	// Finish the line
	_ftprintf(m_pFile, _T("\n"));
}



