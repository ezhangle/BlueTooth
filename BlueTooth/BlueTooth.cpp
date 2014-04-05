// BlueTooth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>


#include "BTClasses.h"

int _tmain(int argc, _TCHAR* argv[])
{
	String port="COM4";
	BTManager* BlueTooth=new BTManager(port);
	Event event;

	BlueTooth->OpenPort();
	BlueTooth->Setup(EBaud9600,EData8,EParNone,EStop1);
	BlueTooth->SetEventMask(EEventBreak |
							EEventCTS   |
							EEventDSR   |
							EEventError |
							EEventRing  |
							EEventRLSD  |
							EEventRecv);
	BlueTooth->SetReadTimeout(EReadTimeoutNonblocking);
	BlueTooth->WaitEvent(event);
	Sleep(50000);
	return 0;
}

