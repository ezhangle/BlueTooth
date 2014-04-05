//
// Baud rates at which the communication device operates
//

#define CBR_110             110
#define CBR_300             300
#define CBR_600             600
#define CBR_1200            1200
#define CBR_2400            2400
#define CBR_4800            4800
#define CBR_9600            9600
#define CBR_14400           14400
#define CBR_19200           19200
#define CBR_38400           38400
#define CBR_56000           56000
#define CBR_57600           57600
#define CBR_115200          115200
#define CBR_128000          128000
#define CBR_256000          256000


typedef enum
{
	EBaudUnknown = -1,			// Unknown
	EBaud110     = CBR_110,		// 110 bits/sec
	EBaud300     = CBR_300,		// 300 bits/sec
	EBaud600     = CBR_600,		// 600 bits/sec
	EBaud1200    = CBR_1200,	// 1200 bits/sec
	EBaud2400    = CBR_2400,	// 2400 bits/sec
	EBaud4800    = CBR_4800,	// 4800 bits/sec
	EBaud9600    = CBR_9600,	// 9600 bits/sec
	EBaud14400   = CBR_14400,	// 14400 bits/sec
	EBaud19200   = CBR_19200,	// 19200 bits/sec (default)
	EBaud38400   = CBR_38400,	// 38400 bits/sec
	EBaud56000   = CBR_56000,	// 56000 bits/sec
	EBaud57600   = CBR_57600,	// 57600 bits/sec
	EBaud115200  = CBR_115200,	// 115200 bits/sec
	EBaud128000  = CBR_128000,	// 128000 bits/sec
	EBaud256000  = CBR_256000,	// 256000 bits/sec
}
Baudrate;

typedef enum
{
	EDataUnknown = -1,			// Unknown
	EData5       =  5,			// 5 bits per byte
	EData6       =  6,			// 6 bits per byte
	EData7       =  7,			// 7 bits per byte
	EData8       =  8			// 8 bits per byte (default)
}
DataBits;

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

typedef enum
{
	EParUnknown = -1,			// Unknown
	EParNone    = NOPARITY,		// No parity (default)
	EParOdd     = ODDPARITY,	// Odd parity
	EParEven    = EVENPARITY,	// Even parity
	EParMark    = MARKPARITY,	// Mark parity
	EParSpace   = SPACEPARITY	// Space parity
}
Parity;


#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2
typedef enum
{
	EStopUnknown = -1,			// Unknown
	EStop1       = ONESTOPBIT,	// 1 stopbit (default)
	EStop1_5     = ONE5STOPBITS,// 1.5 stopbit
	EStop2       = TWOSTOPBITS	// 2 stopbits
} 
StopBits;


typedef enum
{
	EEventUnknown  	   = -1,			// Unknown event
	EEventNone  	   = 0,				// Event trigged without cause
	EEventBreak 	   = EV_BREAK,		// A break was detected on input
	EEventCTS   	   = EV_CTS,		// The CTS signal changed state
	EEventDSR   	   = EV_DSR,		// The DSR signal changed state
	EEventError 	   = EV_ERR,		// A line-status error occurred
	EEventRing  	   = EV_RING,		// A ring indicator was detected
	EEventRLSD  	   = EV_RLSD,		// The RLSD signal changed state
	EEventRecv  	   = EV_RXCHAR,		// Data is received on input
	EEventRcvEv 	   = EV_RXFLAG,		// Event character was received on input
	EEventSend		   = EV_TXEMPTY,	// Last character on output was sent
	EEventPrinterError = EV_PERR,		// Printer error occured
	EEventRx80Full	   = EV_RX80FULL,	// Receive buffer is 80 percent full
	EEventProviderEvt1 = EV_EVENT1,		// Provider specific event 1
	EEventProviderEvt2 = EV_EVENT2,		// Provider specific event 2
} 
Event;

typedef enum
{
	EReadTimeoutUnknown		= -1,	// Unknown
	EReadTimeoutNonblocking	=  0,	// Always return immediately
	EReadTimeoutBlocking	=  1	// Block until everything is retrieved
}
ReadTimeout;
