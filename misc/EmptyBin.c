/*
 *	EmptyBin.c
 */

#include "stdafx.h"

VOID	EmptyBin()
{
	HRESULT hr;
	
	hr = SHEmptyRecycleBin(
		NULL, // A handle to the parent window
		NULL, // all recycle bins on all drives will be emptied
		SHERB_NOPROGRESSUI | SHERB_NOSOUND | SHERB_NOCONFIRMATION
	);
	
	if(SUCCEEDED(hr))
		MessageBox(
			NULL, 
			TEXT("The Recycle Bin has been emptied."), 
			TEXT("Garbage Discarder"), 
			MB_OK
		);
	else
		ErrorExit(TEXT("EmptyBin"));
}
