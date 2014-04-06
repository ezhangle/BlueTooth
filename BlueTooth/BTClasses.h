
#ifndef UNICODE  
typedef std::string String; 
#else
typedef std::wstring String; 
#endif

#include "BTEnums.h"
class BTManager
{
	String m_Port;
	HANDLE m_file;
	DWORD m_mask;
public:

	BTManager(String port )
	{
		m_Port=port;
	}

	bool OpenPort()
	{
		m_file=CreateFile(
			m_Port.c_str(),
			GENERIC_READ|GENERIC_WRITE,
			0,
			0,
			OPEN_EXISTING,
			0,
			0);

		if(m_file==INVALID_HANDLE_VALUE)
		{
			m_file=0;

			printf("Failed to Open Com Port: %s \n",m_Port.c_str());
			return false;
		}
		
		printf("Successfully Opened Com Port: %s \n",m_Port.c_str());
		return true;
	}

	bool Setup(Baudrate baudrate,DataBits DataSize,Parity ParityScheme,StopBits StopBitsScheme)
	{
		DCB dcb;
		if(!GetCommState(m_file,&dcb))
		{
			printf("Failed to Get Comm State During Setup \n");
			return false;
		}

		dcb.BaudRate=DWORD(baudrate);
		dcb.ByteSize=BYTE(DataSize);
		dcb.Parity=BYTE(ParityScheme);
		dcb.StopBits=BYTE(StopBitsScheme);

		dcb.fParity=(ParityScheme != EParNone);

		if(!SetCommState(m_file,&dcb))
		{
			printf("Failed to Set DCB info during Setup \n");
			return false;
		}
		printf("Successfully Setup \n");
	}

	bool SetEventMask(DWORD mask)
	{
		if(!SetCommMask(m_file,mask))
		{
			printf("Failed to set mask \n");
			return false;		
		}
		m_mask=mask;
		printf("Set Mask Successfully \n");

		return true;
	}

	bool SetReadTimeout(ReadTimeout timeout)
	{
		COMMTIMEOUTS cto;
		if(!GetCommTimeouts(m_file,&cto))
		{
			printf("Failed to Get Comm Timout Info \n");
			return false;
		}

		switch(timeout)
		{
		case EReadTimeoutBlocking:
			cto.ReadIntervalTimeout = 0;
			cto.ReadTotalTimeoutConstant = 0;
			cto.ReadTotalTimeoutMultiplier = 0;
			break;
		case EReadTimeoutNonblocking:
			cto.ReadIntervalTimeout = MAXDWORD;
			cto.ReadTotalTimeoutConstant = 0;
			cto.ReadTotalTimeoutMultiplier = 0;
			break;
		default:
			printf("Shouldn't be in Here, Check this shit in ReadTimeout \n");
		}

		if(!SetCommTimeouts(m_file,&cto))
		{
			printf("Failed to Set CommState \n");
			return false;		
		}
		printf("Successfully Set CommState \n");
		return true;
	}

	bool WaitEvent(Event &EventType)
	{
		Event event;

		if(!WaitCommEvent(m_file,LPDWORD(&event),NULL))
		{
			printf("Failed to Wait For Event \n");
			return false;
		}
		std::cout<<"Event of Type: "<<std::hex<<event<<" Found \n";
		EventType=event;
		return true;
	}

	String ReadData()
	{
		char buffer[5000];
		DWORD bytesread=0;
		size_t size=sizeof(buffer);

		if(!ReadFile(m_file,&buffer,size,&bytesread,NULL))
		{
			printf("Failed to Read Data \n");
		}
		std::cout<<buffer<<"\n";

		String returnval=String(buffer);
		return returnval;
	}
};