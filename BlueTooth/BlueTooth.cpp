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
							EEventSend  |
							EEventRecv);
	BlueTooth->SetReadTimeout(EReadTimeoutNonblocking);

	while(true)
	{
		BlueTooth->WaitEvent(event);
		if(event==EEventRecv)
		{
			printf("Data: %s \n",BlueTooth->ReadData().c_str());
		}
	}
	
	Sleep(50000);
	return 0;
}

