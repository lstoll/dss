/*
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 *
 */
/*
    File:       ServerSDPSourceInfo.cpp

    Contains:   Implements object defined in .h file.
                    

*/

#include "SourceInfo.h"
#include "SocketUtils.h"
#include "ServerSDPSourceInfo.h"
#include "OSMemory.h"
#include "StringParser.h"
#include <arpa/inet.h>
#include "../../Server.tproj/QTSServerInterface.h"



ServerSDPSourceInfo::~ServerSDPSourceInfo()
{
    // Not reqd as the destructor of the 
    // base class will take care of delete the stream array
    // and output array if allocated
    /* 
    if (fStreamArray != NULL)
    {
        char* theCharArray = (char*)fStreamArray;
        delete [] theCharArray;
    }
    */
    
    //fSDPData.Delete();
}

Bool16  ServerSDPSourceInfo::IsReflectableIPAddr(UInt32 inIPAddr)
{
    /*//qtss_printf("ServerSDPSourceInfo::IsReflectableIPAddr: method invoked for IP %lu\n", inIPAddr);
    // If the alt transport addr is set and matches the incoming address, then we are reflectable.
    char srcIPAddrBuf[20];
    StrPtrLen theSrcIPAddress(srcIPAddrBuf, 20);
    QTSServerInterface::GetServer()->GetPrefs()->GetTransportSrcAddr(&theSrcIPAddress);
    //qtss_printf("ServerSDPSourceInfo::IsReflectableIPAddr: Parsed IP %s\n", theSrcIPAddress.GetAsCString());
    if (theSrcIPAddress.Len != 0) {
        UInt32 altTransportIPAddr = ntohl(inet_addr(theSrcIPAddress.GetAsCString()));
        //qtss_printf("ServerSDPSourceInfo::IsReflectableIPAddr: There is an alternate src IP Addr in config\n");
        //qtss_printf("ServerSDPSourceInfo::IsReflectableIPAddr: About to compare in: %lu to config: %lu\n", inIPAddr, altTransportIPAddr);
        if (true) { // inIPAddr == altTransportIPAddr
            //qtss_printf("ServerSDPSourceInfo::IsReflectableIPAddr: Addresses match!");*/
            return true; // The alternate transport address matches the address being checked 
        /*}
    }

    if (SocketUtils::IsMulticastIPAddr(inIPAddr) || SocketUtils::IsLocalIPAddr(inIPAddr))
        return true;
    return false;*/

}