/* 
 * File:   ServerSDPSourceInfo.h
 * Author: lstoll
 *
 * Created on May 25, 2008, 2:32 PM
 */
/*
    File:       ServerSDPSourceInfo.h

    Contains:   This object extends the SDPSourceInfo class, and adds server-only
                functionality for testing the reflecability of an IP.



*/

#ifndef _SERVERSDPSOURCEINFO_H
#define	_SERVERSDPSOURCEINFO_H

#include "StrPtrLen.h"
#include "SourceInfo.h"
#include "SDPSourceInfo.h"
#include "StringParser.h"

class ServerSDPSourceInfo : public SDPSourceInfo
{
    public:
        // COPIED FROM PARENT - Uses the SDP Data to build up the StreamInfo structures
        ServerSDPSourceInfo(char* sdpData, UInt32 sdpLen) { Parse(sdpData, sdpLen); }
        ServerSDPSourceInfo() {}
        virtual ~ServerSDPSourceInfo();
    
    protected:
        
        //utility function used by IsReflectable
        Bool16 IsReflectableIPAddr(UInt32 inIPAddr);
      
    //private:

};

#endif	/* _SERVERSDPSOURCEINFO_H */

