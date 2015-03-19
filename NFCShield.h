/*

  Project:       1Sheeld Library 
  File:          NFCShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
  
#ifndef NFCShield_h
#define NFCShield_h

// Input Function ID 
#define NFC_GET_BASIC_INFO 0x01
#define NFC_ON_ERROR	   0x02

#include "ShieldParent.h"
#include "NFCTag.h"
#include "NFCRecord.h"

class NFCShield : public ShieldParent
{
public:
	NFCShield();
	NFCTag & getLastTag();
	bool isNewTagScanned();
	void setOnNewTagScanned(void (*)(NFCTag &));
	void setOnError(void (*)(byte));
	
private:
	bool isErrorAssigned;
	bool isNewTag;
	bool isNewTagSetOnAssigned;
	NFCTag * tag;
	void processData();
	void (*errorCallBack)(byte);
	void (*newTagCallBack)(NFCTag &);
	static NFCTag nullTag;
};

//Extern Object
extern NFCShield NFC;
#endif